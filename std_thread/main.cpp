
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

std::mutex mtx;

class TEST_CLASS {
    int parint;
    std::string parstr;
    std::vector<bool> ports;
    std::recursive_mutex mtx;
} tstClass;

void StartTread(int &parInt, std::string &parString, TEST_CLASS &tstClass) {
    mtx.lock();
    std::thread::id threadId = std::this_thread::get_id();
    std::cout << "Thread #" << threadId << " started with parInt=" << parInt << " parString =" << parString << std::endl;
    mtx.unlock();
}

void StartTreadWithStartBinary(int &parInt, std::string &parString, TEST_CLASS &tstClass) {
    mtx.lock();
    std::thread::id threadId = std::this_thread::get_id();
    std::cout << "Thread #" << threadId << " started with parInt=" << parInt << " parString =" << parString << std::endl;
    std::string cmd = "./programm_name " + parString;
    std::cout << "pipe cmd: " << cmd << std::endl;
    // start new process
    std::array<char, 1024> buffer;
    auto pipe = popen(cmd.c_str(), "r");  // get rid of shared_ptr
    if (pipe) {
        // wait finish of the new process in the parent thread
        while (!feof(pipe)) {
            if (fgets(buffer.data(), 128, pipe) != nullptr) {
                std::cout << buffer.data();
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        auto rc = pclose(pipe);
        // std::cout << "pipe result: " << result << std::endl;
    }

    mtx.unlock();
}

int main() {
    int paramInt = 3;
    std::string str = "My str";
    std::thread t1(StartTread, std::ref(paramInt), std::ref(str), std::ref(tstClass));
    std::thread t2(StartTread, std::ref(paramInt), std::ref(str), std::ref(tstClass));
    t1.join();
    t2.join();

    return 0;
}