#include <iostream>
#include <vector>
#include "MyString.h"

using namespace std;

int main()
{	
    MyString a{"Hello"};
    MyString b = -a;
    
    if (a == b)
    {
        std::cout << "EQUAL" << std::endl;
    }
    else
    {
        std::cout << "NOT EQUAL" << std::endl;
    }
    
    MyString conc = a + " " + b;
    
    
	return 0;
}
