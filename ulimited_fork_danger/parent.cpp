
#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int cnt = 0;

void create_fork(int *pCnt)
{
    cnt++;
    int pid = fork();
    if (pid != 0)
    {
        // parent process
        std::cout << "Parent: parent process (pid = " << pid << " all= " << *pCnt << ")\n";
    }
    else
    {
        // child process
        std::cout << "Child: child process (pid = " << pid << " all= " << *pCnt << ")\n";
    }
}

int main()
{

    while (1)
    {
        create_fork(&cnt);
    }

    return 0;
}