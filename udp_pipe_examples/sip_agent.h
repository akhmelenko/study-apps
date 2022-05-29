
/*!
 * \file sip_agent.h
 * Пример использования Framework системы Фагот. В данном примере показан
 * механизм создания потоков, менеджера потоков, межпоточных сообщений, а
 * также передачи сообщений между потоками.
 *
 * \author
 */

#ifndef __SIP_AGENT_H__
#define __SIP_AGENT_H__

#include "framework.h"
#include "user_interface_thread_base.h"
#include "sip_agent_service_thread.h"
#include "audio_common_types.h"
#include "data_streamer.h"
#include "sip_agent_connection_config.h"
#include "unix_pipe.h"

#include <unistd.h>
#include <fcntl.h>
#include <vector>
#include <memory>
#include <sys/un.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pjsua2.hpp>

//! Класс потока.
/*! В классе потока определены функции инициализации и обработки сообщения.
 *  В классе показана работа с межпотоковыми сообщениями:
 *   - отправка сообщений.
 */
class SipAgent : public UserCommandInterfaceThreadBase,
                 public pj::Account,
                 public DataStreamer
{
public:
    DEFINE_OBJECT_TYPE(SipAgent);

    SipAgent(std::shared_ptr<SharedBase> *pSharedPtr);
    virtual ~SipAgent();

protected:
    //! Функция инициализации
    /*! В функции анализируется аргумент, полученный при создании потока.
     *  Этот аргумент должен быть указателем на дугой поток. Если указатель
     *  не нулевой:
     *   - через указатель получается идентификатор потока.
     *   - создается сообщение, получателем которого является поток с
     *   полученным идентификатором.
     *   - в сообщение добавляются несколько объектов: свой идентификатор,
     *   текстовое сообщение и количество пересылок.
     *   - сообщение отпраялется.
     */
    virtual void PreWorkInit() override;
    virtual void PostWorkDeinit() override;

    virtual void ProcessCommand(const std::string &command) override;
    void ProcessSymbol(int c) override;

    virtual void ProcessMessage(Framework::ThreadMessagePtr_t message);
    virtual void ProcessFdEvent(Framework::FileDescriptor_t fd, unsigned int events) override;

protected:
    // DataStreamer
    virtual pj_status_t PutFrame(pjmedia_frame *frame) override;
    virtual pj_status_t GetFrame(pjmedia_frame *frame) override;
    virtual pj_status_t OnDestroy() override { return -1; };

protected:
    /**
     * @brief UdpClientSetup
     *
     * @param udpSocket
     * @param server_address
     * @param udpServerPort
     * @return true: Ok
     * @return false: Error
     */
    bool UdpClientSetup(int &udpSocket,
                        struct sockaddr_in &server_address,
                        int udpServerPort);

    void CloseSocket(int &udpSocketFd);

    /**
     * @brief SuaToCntrlStartMsg
     *
     */
    void ProcessSuaToCntrlStartMsg();

    /**
     * @brief SendToUdpMsg
     *
     * @param udpSocket
     * @param msgSuaToCntrl
     * @param server_address
     * @return true: Ok
     * @return false: Error
     */
    bool SendToUdpMsg(
        int udpSocket,
        SUA_TO_SIPCNTRL_MSG_t &msgSuaToCntrl,
        struct sockaddr_in &server_address);

    /**
     * @brief SuaToCntrlDisconnMsg
     *
     */
    void ProcessSuaToCntrlDisconnMsg();

    void ProcessAgentToHwConnectConfirmMsg();

    /**
     * @brief SuaToCntrlCloseMsg
     *
     */
    void ProcessSuaToCntrlCloseMsg();

protected:
    /*
        class MyAccount : public pj::Account
        {
        public:
            std::vector<pj::Call *> calls;

        public:
            MyAccount(SipAgent &_owner);

            ~MyAccount();

            void removeCall(pj::Call *call);
            virtual void onRegState(pj::OnRegStateParam &prm);
            virtual void onIncomingCall(pj::OnIncomingCallParam &iprm);

        private:
            SipAgent &sipAgent;
        };*/

    struct AUDIO_MEDIA_OBJECT : virtual public Framework::SharedBase
    {
        DEFINE_OBJECT_TYPE(AUDIO_MEDIA_OBJECT);
        AUDIO_MEDIA_OBJECT(
            std::shared_ptr<SharedBase> *pSharedPtr,
            const pj::AudioMedia &_aud_med)
            : SharedBase(pSharedPtr),
              aud_med(_aud_med) {}
        pj::AudioMedia aud_med;
    };

    class MyCall : public pj::Call
    {
    public:
        MyCall(
            SipAgent &_owner,
            int call_id = PJSUA_INVALID_ID);

        ~MyCall();

        virtual void onCallState(pj::OnCallStateParam &prm) override;
        virtual void onCallTransferRequest(pj::OnCallTransferRequestParam &prm) override;
        virtual void onCallReplaced(pj::OnCallReplacedParam &prm) override;
        virtual void onCallMediaState(pj::OnCallMediaStateParam &prm) override;

    private:
        SipAgent &sipAgent;
        AUDIO_MEDIA_OBJECT::ObjectType_t aud_med_;
    };

    void removeCall(pj::Call *call);
    // pj::Account
    virtual void onRegState(pj::OnRegStateParam &prm) override;
    void OnRegState();

    virtual void onIncomingCall(pj::OnIncomingCallParam &iprm) override;
    void OnIncomingCall(const std::shared_ptr<MyCall> &call);
    void ProcessOnIncomingCall(Framework::ThreadMessagePtr_t message);

    void OnCallStateDisconnect();
    void ProcessOnCallStateDisconnect();
    void OnCallStateConfirmed();
    void ProcessOnCallStateConfirmed();
    // void OnCallTransferRequest(pj::OnCallTransferRequestParam &prm);
    // void ProcessOnCallTransferRequest(ThreadMessagePtr_t message);
    // void OnCallReplaced(pj::OnCallReplacedParam &prm);
    // void ProcessOnCallReplaced(ThreadMessagePtr_t message);
    void OnCallMediaState(const AUDIO_MEDIA_OBJECT::ObjectType_t &aud_med);
    void ProcessOnCallMediaState(Framework::ThreadMessagePtr_t message);

    // // pj::Call
    // virtual void onCallState(pj::OnCallStateParam &prm) override;
    // virtual void onCallTransferRequest(pj::OnCallTransferRequestParam &prm) override;
    // virtual void onCallReplaced(pj::OnCallReplacedParam &prm) override;
    // virtual void onCallMediaState(pj::OnCallMediaStateParam &prm) override;

    /// @brief Очередь буферов данных
    struct AudioBuffer
    {
        short buf[AUDIO_BUFFER_SIZE];
    };
    class BufQueue : public std::list<AudioBuffer>
    {
    public:
        /// @brief Конструктор по умолчанию
        enum
        {
            BUF_DELAY = 2,
        };
        BufQueue()
        {
        }
        /// @brief Деструктор
        ~BufQueue()
        {
            clear();
        }

        /**
         * @brief Отправить группу данных в очередь
         * @param item - указатель на группу данных
         * @result Нет результата
         */
        void PutItem(short *item)
        {
            emplace_back();
            memcpy(back().buf, item, AUDIO_BUFFER_SIZE * sizeof(short));
            //            DBG_FPRINTF_("P %d\n", (int)this->size());
            // memset(back().buf, 0, AUDIO_BUFFER_SIZE * sizeof(short));
        }

        /**
         * @brief Получить группу данных из очереди
         * @result Указатель на группу данных
         */
        bool GetItem(short *buf)
        {
            if (size() >= BUF_DELAY)
            {
                //                DBG_FPRINTF_("1 %d\n", (int)this->size());
                memcpy(buf, front().buf, AUDIO_BUFFER_SIZE * sizeof(short));
                pop_front();
                return true;
            }
            //            DBG_FPRINTF_("0 %d\n", (int)this->size());
            memset(buf, 0, AUDIO_BUFFER_SIZE * sizeof(short));
            return false;
        }

        /**
         * @brief Инициализация очереди
         */
        int Init()
        {
            clear();
            return 0;
        }
    };

private:
    enum
    {
        //! обработка тестового сообщения
        /*! используется с нулевым указателем, как эвент получения сообщения
         */
        THREAD_MESSAGE_TYPE_ON_CALL_STATE_DISCONNECT = Framework::THREAD_MESSAGE_TYPE_USER_START,
        THREAD_MESSAGE_TYPE_ON_CALL_STATE_CONFIRMED,
        THREAD_MESSAGE_TYPE_ON_TRANSFER_REQUEST,
        THREAD_MESSAGE_TYPE_ON_CALL_REPLACED,
        THREAD_MESSAGE_TYPE_ON_CALL_MEDIA_STATE,
        THREAD_MESSAGE_TYPE_AGENT_REGISTERED,
        THREAD_MESSAGE_TYPE_ON_INCOMING_CALL,
        THREAD_MESSAGE_TYPE_DESTROY,
    };

    void ProcessUserCmd(const std::string &cmd, const std::string &arg);
    void Destroy();
    void ProcessDestroy();

    struct INCOMING_CALL_PARAM_OBJECT : virtual public Framework::SharedBase
    {
        DEFINE_OBJECT_TYPE(INCOMING_CALL_PARAM_OBJECT);
        INCOMING_CALL_PARAM_OBJECT(
            std::shared_ptr<SharedBase> *pSharedPtr,
            const std::shared_ptr<MyCall> &_call)
            : SharedBase(pSharedPtr),
              call(_call) {}
        std::shared_ptr<MyCall> call;
    };

    void SockaddrInit(
        struct sockaddr_in &server_address,
        const std::string &host,
        const std::string &port);

    bool UdpServerSetup(
        int &socketFd,
        unsigned int port);

    bool InitUdpServer(
        int &socketFd,
        struct sockaddr_in &server_address);

    bool InitInputPipe(UnixPipe &pipe, std::string &path);

    void ProcessHwToAgentSound();
    void ProcessHwToAgentControl();
    void ProcessCallHangup();
    void ProcessCallToExternal(const char *_destName);

private:
    std::vector<std::shared_ptr<MyCall>> calls_;

    unsigned int agentPort_ = -1;
    pj::Endpoint ep_;

    struct sockaddr_in ctrlServerUdpAddress_;
    // agent control UDP interface
    unsigned int controlUdpServerPort_ = -1;
    int agentControlUdpSocketFd_ = 0;
    // Agent to Hw Sound Pipe interface
    std::string agentToHwSoundPath_;
    UnixPipe agentToHwSoundUnixPipe_;
    // HW to Agent Sound Pipe interface
    std::string hwToAgentSoundPath_;
    UnixPipe hwToAgentSoundUnixPipe_;
    // struct sockaddr_in hwToAgentSoundUdpSocketAddr_;
    // Agent to Hw Sound Pipe interface
    std::string agentToHwStatusPath_;
    UnixPipe agentToHwStatusUnixPipe_;
    // agent status UDP interface
    unsigned int statusUdpServerPort_ = -1;
    int agentStatusUdpSocketFd_ = 0;

    using BufQueueAccessHelper = Framework::Lockable<BufQueue>::AccessHelper;
    Framework::Lockable<BufQueue> inBufQueue_;

    // short inBuf_[AUDIO_BUFFER_SIZE];
};

#endif /* __SIP_AGENT_H__ */
