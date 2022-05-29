/*  cd ~/git/fagot/sw/branches/head
 *  ./script_run_cmake.sh -b /home/imx/tmp_dir/tb/ -c ConfBuild
 *
 *  ssh-keygen -f "/home/imx/.ssh/known_hosts" -R 192.168.10.243
 *  scp ./imx7_drv_test root@192.168.10.243:/home/root
 */
#include <fcntl.h>
#include "sip_agent_connection_config.h"
#include <stdio.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <unistd.h>
#include "audio_common_types.h"
#include "sip_agent.h"
#include "debug.h"

MODULE_DECLARE(sip_agent, 0xffffffff);

//! зона сообщений потока SipAgent
#define DBG_ZONE_THREAD_OUT CREATE_DBG_ZONE(DBG_ZONE_USER)

//! зона сообщений нехватки памяти
#define DBG_ZONE_BAD_ALLOC CREATE_DBG_ZONE(DBG_ZONE_USER + 1)

using namespace Framework;

SipAgent::SipAgent(std::shared_ptr<SharedBase> *pSharedPtr)
    : SharedBase(pSharedPtr),
      UserCommandInterfaceThreadBase(pSharedPtr)
{
}

SipAgent::~SipAgent()
{
    // // delete dataStreamer_
    // if (dataStreamer_)
    // {
    //     delete dataStreamer_;
    // }

    // // delete pAgent_acc_
    // if (pAgent_acc_)
    // {
    //     delete pAgent_acc_;
    // }
}

// SipAgent::MyAccount::MyAccount(SipAgent &_owner) : sipAgent(_owner)
// {
// }

// SipAgent::MyAccount::~MyAccount()
// {
// }

pj_status_t SipAgent::PutFrame(pjmedia_frame *frame)
{
#if 1 // test anton
    // DBG_FPRINTF("Reading frame");
#endif

    // if (agentToHwSoundUdpSocketFd_ < 0)
    //     return PJ_SUCCESS;

    // if (agentToHwSoundUnSocket_.GetFd() < 0)
    //     return PJ_SUCCESS;
    if (agentToHwSoundUnixPipe_.GetFd() < 0)
        return PJ_SUCCESS;

    // int ret = sendto(
    //     agentToHwSoundUdpSocketFd_,
    //     (const void *)frame->buf,
    //     frame->size,
    //     0,
    //     reinterpret_cast<sockaddr *>(&agentToHwSoundUdpSocketAddr_),
    //     sizeof(agentToHwSoundUdpSocketAddr_));

    // int ret = agentToHwSoundUnSocket_.Write(frame->buf, frame->size);
    int ret = agentToHwSoundUnixPipe_.Write(frame->buf, frame->size);
    if (ret < 0)
    {
#if 1 // test anton
        DBG_FPRINTF("sendto() error: %d", ret);
#endif
        return false;
    }
    return PJ_SUCCESS;
}

pj_status_t SipAgent::GetFrame(pjmedia_frame *frame)
{
#if 1 // test anton
    // DBG_FPRINTF("Filling frame");
#endif

    BufQueueAccessHelper l(inBufQueue_);
    l.Value().GetItem((short *)frame->buf);

    //    memset(frame->buf, 0, frame->size);

    // test
    // memcpy(frame->buf, inBuf_, frame->size);

    // DBG_FPRINTF(
    //     "GetFrame(): frame->size()=%d AUDIO_BUFFER_SIZE=%d",
    //     frame->size,
    //     AUDIO_BUFFER_SIZE);

    // TEST
    // inBufQueue_.GetItem((short *)frame->buf);

    // memcpy(frame->buf, 0, frame->size);

    /*
        // TODO test
        char buf[frame->size];
        double tmp = 32 * 2.0 * 3.14 / frame->size;
        for (size_t i = 0; i < frame->size; i++)
        {
            buf[i] = (short)(sin(i * tmp) * 32000.0);
        }

        pj_memcpy(frame->buf, buf, frame->size);*/
    return PJ_SUCCESS;
}

void SipAgent::removeCall(pj::Call *call)
{
    for (auto it = calls_.begin();
         it != calls_.end(); ++it)
    {
        if (it->get() == call)
        {
            calls_.erase(it);
            break;
        }
    }
}

void SipAgent::ProcessOnIncomingCall(
    Framework::ThreadMessagePtr_t message)
{
#if 1 // test anton
    DBG_FPRINTF("*** Incoming Call: put to calls_");
#endif

    INCOMING_CALL_PARAM_OBJECT::ObjectType_t msgObject =
        message->GetObject<INCOMING_CALL_PARAM_OBJECT>();

    if (!msgObject)
    {
        DBG_MSG_ERR(DBG_ZONE_ERROR, "error msgObject = NULL");
        return;
    }

    calls_.push_back(msgObject->call);
}

void SipAgent::OnIncomingCall(
    const std::shared_ptr<MyCall> &call)
{
#if 1 // test anton
    DBG_FPRINTF("*** Incoming Call: 2");
#endif

    INCOMING_CALL_PARAM_OBJECT::ObjectType_t msgObject =
        CREATE_SHARED_OBJECT(
            INCOMING_CALL_PARAM_OBJECT,
            call);

    ResultCode_t ret = AddThreadMessage(
        THREAD_MESSAGE_TYPE_ON_INCOMING_CALL,
        0,
        msgObject);
    if (ret != ErrorBase::SUCCESS)
    {
        DBG_MSG_ERR(DBG_ZONE_ERROR, "AddThreadMessage() Error");
    }
}

void SipAgent::onIncomingCall(pj::OnIncomingCallParam &iprm)
{
#if 1 // test anton
    DBG_FPRINTF("*** Incoming Call: 1");
#endif
#if 1
    // pj::Call *call = new MyCall(*this, sipAgent, iprm.callId);
    std::shared_ptr<MyCall> call{new MyCall(*this, iprm.callId)};
    // std::shared_ptr<pj::Call> call = std::make_shared<pj::Call>(pj::Call(*this, iprm.callId));
    pj::CallInfo ci = call->getInfo();
    pj::CallOpParam prm;

#if 1 // test anton
    DBG_FPRINTF("*** Incoming Call: ci.remoteUri=%s [ci.stateText=%s]",
                ci.remoteUri.c_str(), ci.stateText.c_str());
#endif
    prm.statusCode = (pjsip_status_code)200;
    call->answer(prm);
    // calls_.push_back(call);
    OnIncomingCall(call);
#else
    OnIncomingCall(iprm);
#endif
}

void SipAgent::OnRegState()
{
    Framework::ThreadMessagePtr_t message =
        Framework::ThreadMessage::CreateThreadMessage(
            THREAD_MESSAGE_TYPE_AGENT_REGISTERED,
            0,
            nullptr);

    if (SUCCESS != AddMessage(message))
    {
        DBG_MSG_ERR(DBG_ZONE_ERROR, "Error add msg");
    }
}

void SipAgent::onRegState(pj::OnRegStateParam &prm)
{
    pj::AccountInfo ai = getInfo();
#if 1 // test anton
    DBG_FPRINTF("%s code=%d]",
                ai.regIsActive ? "*** Register: code=" : "*** Unregister: code=", prm.code);
#endif

    // Send "Open SUA" Event
    OnRegState();
}

void SipAgent::ProcessOnCallStateDisconnect()
{
    // myAcc->removeCall(this);
    /* Delete the call */
    // delete this;

    // Anton start
    // exit if disconnected
#if 1 // test anton
    DBG_FPRINTF("SUA state changed to: PJSIP_INV_STATE_DISCONNECTED");
#endif

    // SUA unregistration
    // sipAgent.pAgent_acc_->shutdown();
    shutdown();
    // send DISCONNECTED to SIP controller
    ProcessSuaToCntrlDisconnMsg();

    // close UDP with notify
    ProcessSuaToCntrlCloseMsg();
    // close application
#if 1 // test anton
    DBG_FPRINTF("exit disconnected");
#endif

#if 1 // test anton
    DBG_FPRINTF("EXIT");
#endif
    gp_Application->Stop();
}

void SipAgent::OnCallStateDisconnect()
{
    Framework::ThreadMessagePtr_t message =
        Framework::ThreadMessage::CreateThreadMessage(
            THREAD_MESSAGE_TYPE_ON_CALL_STATE_DISCONNECT,
            0,
            nullptr);

    if (SUCCESS != AddMessage(message))
    {
        DBG_MSG_ERR(DBG_ZONE_ERROR, "Error add msg");
    }
}

void SipAgent::ProcessOnCallStateConfirmed()
{
    // send status (Connect Confirmed) to HW
    ProcessAgentToHwConnectConfirmMsg();
}

void SipAgent::OnCallStateConfirmed()
{
    Framework::ThreadMessagePtr_t message =
        Framework::ThreadMessage::CreateThreadMessage(
            THREAD_MESSAGE_TYPE_ON_CALL_STATE_CONFIRMED,
            0,
            nullptr);

    if (SUCCESS != AddMessage(message))
    {
        DBG_MSG_ERR(DBG_ZONE_ERROR, "Error add msg");
    }
}

void SipAgent::MyCall::onCallState(pj::OnCallStateParam &prm)
{
    PJ_UNUSED_ARG(prm);

    pj::CallInfo ci = getInfo();
#if 1 // test anton
    DBG_FPRINTF("*** Call: ci.remoteUri=%s [ci.stateText=%s]",
                ci.remoteUri.c_str(), ci.stateText.c_str());
#endif

    switch (ci.state)
    {
    case PJSIP_INV_STATE_DISCONNECTED:
        sipAgent.OnCallStateDisconnect();
        break;
    case PJSIP_INV_STATE_CONFIRMED:
        sipAgent.OnCallStateConfirmed();
        break;
    default:
        break;
    }
}

void SipAgent::MyCall::onCallTransferRequest(pj::OnCallTransferRequestParam &prm)
{
    /* Create new Call for call transfer */
    // prm.newCall = new MyCall(*myAcc, sipAgent);
    prm.newCall = new MyCall(sipAgent);
}

void SipAgent::MyCall::onCallReplaced(pj::OnCallReplacedParam &prm)
{
    /* Create new Call for call replace */
    // prm.newCall = new MyCall(*myAcc, sipAgent, prm.newCallId);
    prm.newCall = new MyCall(sipAgent, prm.newCallId);
}

void SipAgent::ProcessOnCallMediaState(
    Framework::ThreadMessagePtr_t message)
{

    AUDIO_MEDIA_OBJECT::ObjectType_t aud_med =
        message->GetObject<AUDIO_MEDIA_OBJECT>();

    // if (!aud_med || agentToHwSoundUdpSocketFd_ < 0)
    // if (!aud_med || agentToHwSoundUnSocket_.GetFd() < 0)
    if (!aud_med || agentToHwSoundUnixPipe_.GetFd() < 0)
    {
        DBG_MSG_ERR(DBG_ZONE_ERROR, "aud_med error");
        return;
    }

#if 1 // test anton
    DBG_FPRINTF("!!!onCallMediaState() 1");
#endif

    ProcessCreateDataStreamer(
        aud_med->aud_med,
        AUDIO_BUFFER_SIZE);
    // agentToHwSoundUdpSocketFd_,
    // agentToHwSoundUnSocket_.GetFd(),
    // agentToHwSoundUdpSocketAddr_);

#if 1 // test anton
    DBG_FPRINTF("!!!onCallMediaState() 2");
#endif
    // This will connect the wav file to the call audio media
    ProcessStartStreaming(aud_med->aud_med);

#if 1 // test anton
    DBG_FPRINTF("!!!onCallMediaState() 3");
#endif
}

void SipAgent::OnCallMediaState(
    const AUDIO_MEDIA_OBJECT::ObjectType_t &aud_med)
{
    Framework::ThreadMessagePtr_t message =
        Framework::ThreadMessage::CreateThreadMessage(
            THREAD_MESSAGE_TYPE_ON_CALL_MEDIA_STATE,
            0,
            aud_med);

    if (SUCCESS != AddMessage(message))
    {
        DBG_MSG_ERR(DBG_ZONE_ERROR, "Error add msg");
    }
}

void SipAgent::MyCall::onCallMediaState(pj::OnCallMediaStateParam &prm)
{

#if 1 // test anton
    DBG_FPRINTF("!!!onCallMediaState()");
#endif

    PJ_UNUSED_ARG(prm);

    try
    {
        // Get the first audio media
        aud_med_.reset();
        aud_med_ = CREATE_SHARED_OBJECT(AUDIO_MEDIA_OBJECT, getAudioMedia(-1));
    }
    catch (...)
    {
        aud_med_.reset();
        std::cout
            << "Failed to get audio media" << std::endl;
        return;
    }

    sipAgent.OnCallMediaState(aud_med_);

#if 0

    std::cout << "!!!onCallMediaState() 1" << std::endl;

    sipAgent.CreateDataStreamer(
        aud_med,
        AUDIO_BUFFER_SIZE,
        agentToHwSoundUdpSocketFd_,
        agentToHwSoundUdpSocketAddr_);

    std::cout << "!!!onCallMediaState() 3" << std::endl;
    // This will connect the wav file to the call audio media
    std::cout << "!!!onCallMediaState() 4" << std::endl;
    sipAgent.StartStreaming(aud_med);

    std::cout << "!!!onCallMediaState() 5" << std::endl;
#endif
}

void SipAgent::SockaddrInit(
    struct sockaddr_in &server_address,
    const std::string &host,
    const std::string &port)
{
    server_address.sin_port = htons(atoi(port.c_str()));
    server_address.sin_family = AF_INET;
    inet_pton(AF_INET, host.c_str(), &server_address.sin_addr);
}

bool SipAgent::InitUdpServer(
    int &socketFd,
    struct sockaddr_in &server_address)
{
    // create socket
    socketFd = socket(AF_INET, SOCK_DGRAM, 0);
    if (socketFd < 0)
    {
        DBG_MSG_ERR(DBG_ZONE_ERROR, "Establishing socket error!!!: %d", socketFd);
        return false;
    }
    DBG_FPRINTF("Socket# %d was successfully created.", socketFd);

    // Bind the socket with the server address
    int ret = bind(socketFd, (const struct sockaddr *)&server_address,
                   sizeof(server_address));
    if (ret < 0)
    {
        DBG_MSG_ERR(
            DBG_ZONE_ERROR,
            "UDP Bind error: %s for socketFd=%d",
            strerror(errno),
            socketFd);
        return false;
    }
    DBG_FPRINTF(
        "=> UDP Starting Listen at %s:%d",
        inet_ntoa(server_address.sin_addr),
        server_address.sin_port);

    return true;
}

bool SipAgent::UdpServerSetup(
    int &socketFd,
    unsigned int port)
{
    struct sockaddr_in udp_server_address;

    SockaddrInit(
        udp_server_address,
        SERVER_UDP_ADDRESS,
        std::to_string(port));
    // DBG_FPRINTF(
    //     "SockaddrInit(agent_to_hw_sound_udp, server_udp_host=%s, agent_to_hw_sound_udp_port_=%d)",
    //     server_udp_host_.c_str(),
    //     port);

    bool result = InitUdpServer(socketFd, udp_server_address);
    if (!result)
    {
        DBG_MSG_ERR(DBG_ZONE_ERROR, "UDPsocket connect error");
        return false;
    }
    ResultCode_t res = AddFd(socketFd, Framework::FILE_DESCRIPTOR_EVENT_IN);
    if (res != ErrorBase::SUCCESS)
    {
        DBG_MSG_ERR(DBG_ZONE_ERROR, "AddFd error (%d)", res);
        return false;
    }
    return true;
}

bool SipAgent::UdpClientSetup(
    int &udpSocket,
    struct sockaddr_in &server_address,
    int statusUdpServerPort_)
{
    udpSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (udpSocket < 0)
    {
#if 1 // test anton
        DBG_FPRINTF("establishing socket error: %s", strerror(errno));
#endif
        return false;
    }
#if 1 // test anton
    DBG_FPRINTF("CLIENT:Socket=%d was successfully created", udpSocket);
#endif

    // init server address
    server_address.sin_port = htons(statusUdpServerPort_);
    server_address.sin_family = AF_INET;
    inet_pton(AF_INET, SERVER_UDP_ADDRESS, &server_address.sin_addr);

    return true;
}

void SipAgent::CloseSocket(int &udpSocketFd)
{
    if (udpSocketFd >= 0)
    {
        RemoveFd(udpSocketFd);
        close(udpSocketFd);
    }
    udpSocketFd = -1;
}

void SipAgent::ProcessAgentToHwConnectConfirmMsg()
{
    // Send "Close SUA" Event with port number
    SUA_TO_SIPCNTRL_MSG_t msgSuaToCntrl{
        SUA_TO_SIPCTRL_MSG_TYPE::SUA_CONNECT_CONFIRMED,
        0};
    bool res = SendToUdpMsg(agentStatusUdpSocketFd_, msgSuaToCntrl, ctrlServerUdpAddress_);
    if (!res)
    {
#if 1 // test anton
        DBG_FPRINTF("CLIENT: SendToUdpMsg(...SUA STARTED...) ERR");
#endif
    }
}

void SipAgent::ProcessSuaToCntrlStartMsg()
{
    // Send "Close SUA" Event with port number
    SUA_TO_SIPCNTRL_MSG_t msgSuaToCntrl{
        SUA_TO_SIPCTRL_MSG_TYPE::SUA_READY,
        0};
    bool res = SendToUdpMsg(agentStatusUdpSocketFd_, msgSuaToCntrl, ctrlServerUdpAddress_);
    if (!res)
    {
#if 1 // test anton
        DBG_FPRINTF("CLIENT: SendToUdpMsg(...SUA STARTED...) ERR");
#endif
    }
}

bool SipAgent::SendToUdpMsg(
    int udpSocket,
    SUA_TO_SIPCNTRL_MSG_t &msgSuaToCntrl,
    struct sockaddr_in &server_address)
{
#if 1 // test anton
    DBG_FPRINTF("SUA: sending to UDP type=%d", (int)msgSuaToCntrl.type);
#endif
    int ret = sendto(
        udpSocket,
        &msgSuaToCntrl,
        sizeof(msgSuaToCntrl),
        0,
        reinterpret_cast<struct sockaddr *>(&server_address),
        sizeof(server_address));
    if (ret < 1)
    {
#if 1 // test anton
        DBG_FPRINTF("sendto() error: %s", strerror(errno));
#endif
        return false;
    }
    return true;
}

void SipAgent::ProcessSuaToCntrlDisconnMsg()
{
    // Send "SUA Disconnected" Event with port number
    SUA_TO_SIPCNTRL_MSG_t msgSuaToCntrl{
        SUA_TO_SIPCTRL_MSG_TYPE::SUA_DISCONN /*,
         static_cast<unsigned short>(agentPort_)*/
    };
    bool res = SendToUdpMsg(agentStatusUdpSocketFd_, msgSuaToCntrl, ctrlServerUdpAddress_);
    if (!res)
    {
#if 1 // test anton
        DBG_FPRINTF("CLIENT: SendToUdpMsg(...SUA DISCONN...) ERR");
#endif
    }
}

void SipAgent::ProcessSuaToCntrlCloseMsg()
{
    if (agentStatusUdpSocketFd_ < 0)
        return;
    // Send "Close SUA" Event with port number
    SUA_TO_SIPCNTRL_MSG_t msgSuaToCntrl{
        SUA_TO_SIPCTRL_MSG_TYPE::SUA_CLOSED,
        static_cast<unsigned short>(agentPort_)};
    bool res = SendToUdpMsg(
        agentStatusUdpSocketFd_,
        msgSuaToCntrl,
        ctrlServerUdpAddress_);

    if (!res)
    {
#if 1 // test anton
        DBG_FPRINTF("CLIENT: SendToUdpMsg(...SUA CLOSED...) ERR");
#endif
    }
    // close UDP
    CloseSocket(agentStatusUdpSocketFd_);
}

// framework
void SipAgent::ProcessUserCmd(const std::string &cmd, const std::string &arg)
{
    DBG_MSG_FUNC_COND(1, DBG_ZONE_ERROR, "+%s cmd=%s, arg=%s", __func__, cmd.c_str(), arg.c_str());
    DBG_FPRINTF("ProcessUserCmd: cmd=%s, arg=%s\n", cmd.c_str(), arg.c_str());

    DBG_MSG_FUNC_COND(1, DBG_ZONE_ERROR, "-%s", __func__);
}

void SipAgent::ProcessCommand(const std::string &command)
{
    std::string cmd;
    std::string arg;
    if (!strcmp("exit", command.c_str()))
    {
        printf("EXIT\n");
        gp_Application->Stop();
        return;
    }
    size_t pos = command.find(" ");
    if (pos != std::string::npos)
    {
        cmd = command.substr(0, pos);
        arg = command.substr(command.find_first_not_of(" \t", pos), std::string::npos);
    }
    else
    {
        cmd = command;
    }
    ProcessUserCmd(cmd, arg);
}

void SipAgent::ProcessSymbol(int c)
{
    /*
        if (c == 'T')
        {
            printf("pushed T\n");
            return;
        }
    */
    if (c == 0x1b)
    {
        DBG_FPRINTF("pushed <%x> - EXIT\n", c);
        gp_Application->Stop();
        // return;
    }
    UserCommandInterfaceThreadBase::ProcessSymbol(c);
}

bool SipAgent::InitInputPipe(UnixPipe &pipe, std::string &path)
{
    bool ret = pipe.Open(path);
    if (!ret)
    {
        DBG_MSG_ERR(DBG_ZONE_ERROR, "OpenRead error path(%s)", path.c_str());
        return false;
    }
    DBG_FPRINTF("Pipe opened");

    ResultCode_t res = AddFd(pipe.GetFd(), Framework::FILE_DESCRIPTOR_EVENT_IN);
    if (res != ErrorBase::SUCCESS)
    {
        DBG_MSG_ERR(DBG_ZONE_ERROR, "AddFd error (%d)", res);
        return false;
    }
    return true;
}

void SipAgent::PreWorkInit()
{
    UserCommandInterfaceThreadBase::PreWorkInit();
    DBG_MSG_FUNC_COND(1, DBG_ZONE_FUNCTION, "+%s", __func__);

    DBG_FPRINTF("Agent MAIN starT\n");

    // pj thread registration
    pj_thread_desc a_thread_desc;
    pj_thread_t *a_thread;

    if (!pj_thread_is_registered())
    {
        pj_thread_register(NULL, a_thread_desc, &a_thread);
    }

    if (gp_Application->argc_ != 7)
    {
        DBG_MSG_ERR(DBG_ZONE_ERROR,
                    "app %s <agent name> <port> parameters error\n",
                    gp_Application->argv_[0]);
        ProcessDestroy();
        gp_Application->Stop(-1);
        return;
    }
    else
    {
        DBG_FPRINTF(
            "app: %s started unique Id=%d\n",
            gp_Application->argv_[0], gp_Application->GetUniqueOnComputerAppId());
    }

    DBG_FPRINTF("SUA main start\n");
    std::string agentName{gp_Application->argv_[1]};
    int agentPort_ = atoi(gp_Application->argv_[2]);
    statusUdpServerPort_ = atoi(gp_Application->argv_[3]);
    controlUdpServerPort_ = atoi(gp_Application->argv_[4]);
    // udpAgentToHwSoundPort_ = atoi(gp_Application->argv_[5]);
    agentToHwSoundPath_ = gp_Application->argv_[5];
    // udpHwToAgentSoundPort_ = atoi(gp_Application->argv_[6]);
    hwToAgentSoundPath_ = gp_Application->argv_[6];
    DBG_FPRINTF(
        "Params: agentName: %s, agentPort_=%d, statusUdpServerPort_=%d, controlUdpServerPort_=%d, agentToHwSoundPath_=%s, hwToAgentSoundPath=%s",
        agentName.c_str(),
        agentPort_,
        statusUdpServerPort_,
        controlUdpServerPort_,
        agentToHwSoundPath_.c_str(),
        hwToAgentSoundPath_.c_str());

    try
    {
        ep_.libCreate();
    }
    catch (pj::Error &err)
    {
        DBG_FPRINTF("Exception ep_.libCreate() : %s\n", err.info().c_str());
        ProcessDestroy();
        gp_Application->Stop(-1);
        return;
    }

    // Init library
    pj::EpConfig ep_cfg;
    ep_cfg.logConfig.level = 4;
    try
    {
        ep_.libInit(ep_cfg);
    }
    catch (pj::Error &err)
    {
        DBG_FPRINTF("Exception ep_.libCreate() : %s\n", err.info().c_str());
        ProcessDestroy();
        gp_Application->Stop(-1);
        return;
    }
    // Turns out to use a null audio device
    try
    {
        ep_.audDevManager().setNullDev();
    }
    catch (pj::Error &err)
    {
        DBG_FPRINTF("Exception ep_.audDevManager().setNullDev() : %s\n", err.info().c_str());
        ProcessDestroy();
        gp_Application->Stop(-1);
        return;
    }

    // Transport
    pj::TransportConfig tcfg;
    tcfg.port = agentPort_;
    try
    {
        ep_.transportCreate(PJSIP_TRANSPORT_UDP, tcfg);
    }
    catch (pj::Error &err)
    {
        DBG_FPRINTF("Exception ep_.transportCreate() : %s\n", err.info().c_str());
        ProcessDestroy();
        gp_Application->Stop(-1);
        return;
    }

    // Start library
    try
    {
        ep_.libStart();
    }
    catch (pj::Error &err)
    {
        DBG_FPRINTF("Exception ep_.libStart() : %s\n", err.info().c_str());
        ProcessDestroy();
        gp_Application->Stop(-1);
        return;
    }
    DBG_FPRINTF("*** PJSUA2 STARTED ***");

    // Add account
    pj::AccountConfig acc_cfg;
    // acc_cfg.idUri = "sip:test1@pjsip.org";
    acc_cfg.idUri = "sip:" + agentName + "@" + SUA_SIP_DOMAIN;
    // acc_cfg.regConfig.registrarUri = "sip:sip.pjsip.org";
    acc_cfg.regConfig.registrarUri = const_cast<char *>("sip:" SUA_SIP_DOMAIN);
    acc_cfg.sipConfig.authCreds.push_back(pj::AuthCredInfo("digest", "*",
                                                           agentName, 0, SUA_SIP_PASSWD));

    // pAgent_acc_ = new MyAccount(*this);
    try
    {
        // Anton
        // acc->create(acc_cfg);
        // pAgent_acc_->create(acc_cfg);
        create(acc_cfg);
        // Anton
    }
    catch (...)
    {
#if 1 // test anton
        DBG_FPRINTF("Adding account failed");
#endif
        ProcessDestroy();
        gp_Application->Stop(-1);
        return;
    }

    bool res;
    // Setup UDP for SUA to CTRL messages
    res = UdpClientSetup(agentStatusUdpSocketFd_, ctrlServerUdpAddress_, statusUdpServerPort_);
    if (!res)
    {
#if 1 // test anton
        DBG_FPRINTF("AGENT: UdpClientSetup() ERR");
#endif
        ProcessDestroy();
        gp_Application->Stop(-1);
        return;
    }

    // Setup UDP for Agent to HW Sound
    // res = UdpClientSetup(
    //     agentToHwSoundUdpSocketFd_,
    //     agentToHwSoundUdpSocketAddr_,
    //     udpAgentToHwSoundPort_);
    // res = agentToHwSoundUnSocket_.OpenWrite(udpAgentToHwSoundPath_);
    res = agentToHwSoundUnixPipe_.Open(agentToHwSoundPath_);
    if (!res)
    {
#if 1 // test anton
        DBG_FPRINTF("AGENT: AgentToHwSoundUdpSetup() ERR");
#endif
        ProcessDestroy();
        gp_Application->Stop(-1);
        return;
    }

    // Setup UDP for HW to Agent Sound
    // res = UdpServerSetup(
    //     hwToAgentSoundUdpSocketFd_,
    //     udpHwToAgentSoundPort_);
    DBG_FPRINTF("hwToAgentSoundPath_=%s", hwToAgentSoundPath_.c_str());
    res = InitInputPipe(hwToAgentSoundUnixPipe_, hwToAgentSoundPath_);
    if (!res)
    {
        ProcessDestroy();
        DBG_MSG_ERR(DBG_ZONE_ERROR, "error start Sound Hw to Agent UDP setup");
        return;
    }
    if (!res)
    {
#if 1 // test anton
        DBG_FPRINTF("AGENT: HwToAgentSoundUdpSetup() ERR");
#endif
        ProcessDestroy();
        gp_Application->Stop(-1);
        return;
    }

    // Setup UDP for HW to Agent Control
    res = UdpServerSetup(
        agentControlUdpSocketFd_,
        controlUdpServerPort_);
    if (!res)
    {
#if 1 // test anton
        DBG_FPRINTF("AGENT: Setup UDP for HW to Agent Control ERR");
#endif
        ProcessDestroy();
        gp_Application->Stop(-1);
        return;
    }

    DBG_MSG_FUNC_COND(1, DBG_ZONE_FUNCTION, "-%s", __func__);
}

void SipAgent::ProcessDestroy()
{

    // CloseSocket(agentToHwSoundUdpSocketFd_);
    // agentToHwSoundUnSocket_.Close();
    agentToHwSoundUnixPipe_.Close();
    // CloseSocket(hwToAgentSoundUdpSocketFd_);
    hwToAgentSoundUnixPipe_.Close();
    CloseSocket(agentStatusUdpSocketFd_);
    CloseSocket(agentControlUdpSocketFd_);

    ep_.libDestroy();
}

void SipAgent::Destroy()
{
    Framework::ThreadMessagePtr_t message =
        Framework::ThreadMessage::CreateThreadMessage(
            THREAD_MESSAGE_TYPE_DESTROY,
            0,
            nullptr);

    if (SUCCESS != AddMessage(message))
    {
        DBG_MSG_ERR(DBG_ZONE_ERROR, "Error add msg");
    }
}

void SipAgent::PostWorkDeinit()
{
    DBG_MSG_FUNC_COND(1, DBG_ZONE_FUNCTION, "+%s", __func__);

    // Destroy library
#if 1 // test anton
    DBG_FPRINTF("*** PJSUA2 SHUTTING DOWN ***");
#endif

    // Anton
    // delete acc; /* Will delete all calls too */

    ProcessDestroy();

    // Destroy library
#if 1 // test anton
    DBG_FPRINTF("*** PJSUA2 SHUTTING DOWN ***");
#endif
    // delete pAgent_acc_; /* Will delete all calls too */

    UserCommandInterfaceThreadBase::PostWorkDeinit();
    DBG_MSG_FUNC_COND(1, DBG_ZONE_FUNCTION, "-%s", __func__);
}

SipAgent::MyCall::MyCall(
    SipAgent &_owner,
    int call_id /*= PJSUA_INVALID_ID*/)
    : pj::Call(_owner, call_id), sipAgent(_owner)
{
}

SipAgent::MyCall::~MyCall()
{
}

void SipAgent::ProcessCallHangup()
{
    DBG_FPRINTF("Internal HangUp!");
    ep_.hangupAllCalls();
}

void SipAgent::ProcessCallToExternal(const char *_destName)
{
    DBG_FPRINTF("Internal Call!");

    if (!_destName)
    {
        DBG_MSG_ERR(DBG_ZONE_ERROR, "Error: bad dest name");
        return;
    }
    std::string destName(_destName);

    if (destName.size() > DEST_CALL_NAME_MAX_SIZE_BYTES)
    {
        DBG_MSG_ERR(DBG_ZONE_ERROR, "Error: bad dest name size");
        return;
    }

    // Make outgoing call
    pj::CallOpParam prm(true);
    prm.opt.audioCount = 1;
    prm.opt.videoCount = 0;
    // std::shared_ptr<MyCall> call{new MyCall(*this, iprm.callId)};
    // use agent port as call ID
    std::shared_ptr<MyCall> call{new MyCall(*this, agentPort_)};
    calls_.push_back(call);
    std::string fullDestStr("sip:" + destName + "@" SUA_SIP_DOMAIN);
    DBG_FPRINTF("destStr=%s fullDestStr=%s", destName.c_str(), fullDestStr.c_str());
    try
    {
        calls_.front()->makeCall(fullDestStr, prm);
    }
    catch (...)
    {
        DBG_MSG_ERR(
            DBG_ZONE_ERROR, "Failed to makeCall");
        return;
    }
}

void SipAgent::ProcessHwToAgentControl()
{

    if (agentControlUdpSocketFd_ < 0)
        return;

    HW_TO_AGENT_MSG msg;
    // HW_TO_AGENT_MSG_TYPE msgType;
    //    memset(buffer, 0, sizeof(buffer));
    int rawSize = recv(agentControlUdpSocketFd_, (void *)&msg, sizeof(msg), 0);
    if (rawSize < 0)
    {
        DBG_MSG_ERR(
            DBG_ZONE_ERROR,
            "UDP INPUT Sound buffer error. received size=%d (expected=%d)?",
            rawSize,
            sizeof(msg));
        CloseSocket(agentControlUdpSocketFd_);
        return;
    }

    switch (msg.type)
    {
    case HW_TO_AGENT_MSG_TYPE::HW_TO_AGENT_MSG_TYPE_CALL_CANCEL:
        ProcessCallHangup();
        break;
    case HW_TO_AGENT_MSG_TYPE::HW_TO_AGENT_MSG_TYPE_CALL_TO_EXTERNAL:
        ProcessCallToExternal(msg.destCallName);
        break;
    default:
        break;
    }
}

void SipAgent::ProcessHwToAgentSound()
{

    // if (hwToAgentSoundUdpSocketFd_ < 0)
    //     return;
    if (hwToAgentSoundUnixPipe_.GetFd() < 0)
        return;

    short buffer[AUDIO_BUFFER_SIZE];
    //    memset(buffer, 0, sizeof(buffer));
    // int rawSize = recv(hwToAgentSoundUdpSocketFd_, buffer, sizeof(buffer), 0);
    int rawSize = hwToAgentSoundUnixPipe_.Read(buffer, sizeof(buffer));
    if (rawSize < 0)
    {
        DBG_MSG_ERR(
            DBG_ZONE_ERROR,
            "UDP INPUT Sound buffer error. received size=%d (expected=%d)?",
            rawSize,
            sizeof(buffer));
        hwToAgentSoundUnixPipe_.Close();
        return;
    }

    // TEST
    //    memset(inBuf_, 0, sizeof(buffer));

    {
        BufQueueAccessHelper l(inBufQueue_);
        l.Value().PutItem((short *)buffer);
    }
}

void SipAgent::ProcessMessage(ThreadMessagePtr_t message)
{
    DBG_MSG_FUNC_COND(1, DBG_ZONE_FUNCTION, "+%s", __func__);

    switch (message->GetType())
    {

    case THREAD_MESSAGE_TYPE_ON_CALL_STATE_DISCONNECT:
        ProcessOnCallStateDisconnect();
        break;
    case THREAD_MESSAGE_TYPE_ON_CALL_STATE_CONFIRMED:
        ProcessOnCallStateConfirmed();
        break;
    case THREAD_MESSAGE_TYPE_ON_TRANSFER_REQUEST:
        break;
    case THREAD_MESSAGE_TYPE_ON_CALL_REPLACED:
        break;
    case THREAD_MESSAGE_TYPE_ON_CALL_MEDIA_STATE:
        ProcessOnCallMediaState(message);
        break;
    case THREAD_MESSAGE_TYPE_AGENT_REGISTERED:
        ProcessSuaToCntrlStartMsg();
        break;
    case THREAD_MESSAGE_TYPE_ON_INCOMING_CALL:
        ProcessOnIncomingCall(message);
        break;
    case THREAD_MESSAGE_TYPE_DESTROY:
        ProcessDestroy();
        break;
    default:
        UserCommandInterfaceThreadBase::ProcessMessage(message);
        DBG_MSG_ERR(DBG_ZONE_ERROR, "error message type");
        break;
    }

    DBG_MSG_FUNC_COND(1, DBG_ZONE_FUNCTION, "-%s", __func__);
}

void SipAgent::ProcessFdEvent(
    Framework::FileDescriptor_t fd,
    unsigned int events)
{
#if 0 // ASTERISK_DEBUG_FUNCTION_CALL
    DBG_FPRINTF("fd=%d hwToAgentSoundUdpSocketFd_=%d events=%x", fd, hwToAgentSoundUdpSocketFd_, events);
#endif

    // if (fd == hwToAgentSoundUdpSocketFd_)
    if (fd == hwToAgentSoundUnixPipe_.GetFd())
    {
        ProcessHwToAgentSound();
    }
    else if (fd == agentControlUdpSocketFd_)
    {
        ProcessHwToAgentControl();
    }
    // else
    // {
    //     return ErrorBase::COMMON_ERROR;
    // }
    // return ErrorBase::SUCCESS;

    UserCommandInterfaceThreadBase::ProcessFdEvent(fd, events);
}
