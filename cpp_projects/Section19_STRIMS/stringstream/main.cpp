#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <limits>

int main ()
{
    int num {0};
    float total {0.0};
    std::string name {""};

    std::cout << "==Data input to stringstream==" << std::endl;
    std::istringstream iss{"Moe 100 54.78"};
    iss >> name >> num >> total;
    std::cout
        << name << std::endl
        << num << std::endl
        << total << std::endl;

    
    std::cout << "==Data output from stringstream==" << std::endl;
    std::ostringstream oss{};
    oss << std::setw(10) << std::left << name
        << std::setw(5) << num
        << std::setw(10) << total;
    std::cout << oss.str() << std::endl;


    std::cout << "==Data validation==" << std::endl;
    int intValidChecker {};
    std::string entry {""};
    std::cout << "Enter the integer value" << std::endl;
    std::cin >> entry;
    std::istringstream validator {entry};
    std::string leftBuffer {""};
    if (validator >> intValidChecker)
    {
        std::cout << intValidChecker << " is integer" << std::endl;
        // print ignored data
        std::cin >> leftBuffer;
        std::cout << "Ignored data: " << leftBuffer << std::endl;
        //discard the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else
    {
        std::cout << intValidChecker << " is not integer" << std::endl;
    }


    int a;
    std::cin >> a;
    return 0;
}