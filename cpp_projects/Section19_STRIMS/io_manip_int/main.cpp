#include <iostream>
#include <iomanip>

int main()
{
    int num{255};
    int num2{-255};

    std::cout << "==no base==" << std::endl;
    std::cout << "dec(255) = " << std::dec << num << std::endl;
    std::cout << "hex(255) = " << std::hex << num << std::endl;
    std::cout << "oct(255) = " << std::oct << num << std::endl;

    std::cout << std::endl
              << "==std::showbase==" << std::endl;
    std::cout << std::showbase;
    std::cout << "dec(255) = " << std::dec << num << std::endl;
    std::cout << "hex(255) = " << std::hex << num << std::endl;
    std::cout << "oct(255) = " << std::oct << num << std::endl;

    std::cout << "==std::noshowbase==" << std::endl;
    std::cout << std::noshowbase;
    std::cout << "dec(255) = " << std::dec << num << std::endl;
    std::cout << "hex(255) = " << std::hex << num << std::endl;
    std::cout << "oct(255) = " << std::oct << num << std::endl;

    std::cout << std::endl
              << "==std::showbase std::uppercase==" << std::endl;
    std::cout << std::showbase << std::uppercase;
    std::cout << "dec(255) = " << std::dec << num << std::endl;
    std::cout << "hex(255) = " << std::hex << num << std::endl;
    std::cout << "oct(255) = " << std::oct << num << std::endl;

    std::cout << std::endl
              << "==std::showpos==" << std::endl;
    std::cout << std::dec << std::showpos;
    std::cout << "std::showpos 255 = " << num << std::endl;
    std::cout << "std::showpos -255 = " << -num << std::endl;

    std::cout << std::endl
              << "==std::noshowpos==" << std::endl;
    std::cout << std::noshowpos;
    std::cout << "std::showpos 255 = " << num << std::endl;
    std::cout << "std::showpos -255 = " << -num << std::endl;

    std::cout << std::endl
              << "==setf==" << std::endl;
    std::cout.setf(std::ios::showbase);
    std::cout.setf(std::ios::showpos);
    std::cout.setf(std::ios::uppercase);
    std::cout << "dec(255) = " << std::dec << num << std::endl;
    std::cout << "hex(255) = " << std::hex << num << std::endl;
    std::cout << "oct(255) = " << std::oct << num << std::endl;

    std::cout << std::endl
              << "==resetioflagsf==" << std::endl;
    std::cout << std::resetiosflags(std::ios::showbase);
    std::cout << std::resetiosflags(std::ios::showpos);
    std::cout << std::resetiosflags(std::ios::uppercase);
    std::cout << "dec(255) = " << std::dec << num << std::endl;
    std::cout << "hex(255) = " << std::hex << num << std::endl;
    std::cout << "oct(255) = " << std::oct << num << std::endl;
    std::cout << "oct(255) = " << std::ios::basefield << num << std::endl;

    int a;
    std::cin >> a;
    return 0;
}