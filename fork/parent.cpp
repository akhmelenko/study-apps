
#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main()
{
    std::cout
        << "Start\n";
    char param0[100];
    char param1[100];
    char param2[100];
    char *parameter[] = {param0, param1, nullptr};

    while (1)
    {
        std::cout << "Enter your CMD: \n";
        std::cin >> parameter[0] >> parameter[1] >> param2;
        std::cout << "Your CMD: " << parameter[0] << ", parameter: " << parameter[1] << "\n";
        int pid = fork();
        if (pid != 0)
        {
            // parent process
            std::cout << "Parent: parent process (pid = " << pid << ", background = " << param2 << ")\n";
            if (atoi(param2))
            {
                int status;
                waitpid(pid, &status, 0);
                std::cout << "Parent: child process finished\n";
            }
        }
        else
        {
            // child process
            std::cout << "Child: child process (pid = " << pid << ")\n";
            int res = execve(parameter[0], parameter, nullptr);
            // char *par[] = {"child", "4", nullptr};
            // int res = execve(par[0], par, NULL);
            if (res < 0)
                std::cout << "Child: execve() error: " << errno << "\n";
        }
    }

    return 0;
}