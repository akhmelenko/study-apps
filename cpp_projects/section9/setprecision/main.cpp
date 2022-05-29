#include <iostream>
#include <iomanip>

//using namespace std;

int main()
{
    double num {12.4444444444};
    std::cout << std::fixed << std::setprecision(2);
	std::cout << "My num = " /*<< std::setprecision(4)*/ << num << std::endl;
	return 0;
}
