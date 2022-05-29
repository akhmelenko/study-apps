
#include <iostream>
#include <string>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <thread>
#include <semaphore.h>

std::counting_semaphore s;

void Worker0()
{
    std::cout << "Worker 0 start\n";
    std::cout << "Worker 0 finished\n";
}

void Worker1()
{
    std::cout << "Worker 1 start\n";
    std::cout << "Worker 1 finished\n";
}

int main()
{
    std::cout
        << "Start\n";

    return 0;
}