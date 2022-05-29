
#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include "square/square.h"
#include "cube/cube.h"

int main()
{
    std::cout << "Hello Bazel\n";
    std::cout << "Square(2)=" << Square(2) << std::endl;
    std::cout << "Cube(3)=" << Cube(3) << std::endl;

    return 0;
}