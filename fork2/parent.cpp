
#include <iostream>
#include <string>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main()
{
    std::cout
        << "Start\n";

    bool childStarted = false;
    int pid;

    while (1)
    {
        usleep(4000000);
        std::cout << "While cycle: (pid =" << pid << ")\n";
        if (childStarted)
            continue;
        pid = fork();
        childStarted = true;
        if (pid != 0)
        {
            // parent process
            std::cout << "Parent: parent process after fork (pid =" << pid << ")\n";
        }
        else
        {
            // child process
            std::cout << "Child: child process after fork (pid = " << pid << ")\n";
            int ret = execl("/home/antonh/Desktop/my_projects/fork2/sua", "2222", "5656", NULL);
            if (ret < 0)
                std::cerr << "Error start process:" << strerror(errno) << ")\n";
        }
    }

    return 0;
}