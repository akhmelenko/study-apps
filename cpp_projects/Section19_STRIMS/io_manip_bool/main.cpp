#include <iostream>
#include <iomanip>

int main ()
{
    std::cout << "==no manip==" << std::endl;
    std::cout << (10 == 10) << std::endl;
    std::cout << (10 == 20) << std::endl;

    std::cout << std::boolalpha;

    std::cout << "==boolalpha==" << std::endl;
    std::cout << (10 == 10) << std::endl;
    std::cout << (10 == 20) << std::endl;

    int a;
    std::cin >> a;
    return 0;
}