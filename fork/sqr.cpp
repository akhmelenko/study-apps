
#include <iostream>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Sqr: Arguments number != 2:" << argc << "\n";
        return -1;
    }

    int arg = atoi(argv[1]);

    for (int i = 0; i < arg; i++)
    {
        sleep(2);
        std::cout
            << "Sqr: Sqr of " << arg << " = " << arg * arg << "\n";
    }

    return 0;
}