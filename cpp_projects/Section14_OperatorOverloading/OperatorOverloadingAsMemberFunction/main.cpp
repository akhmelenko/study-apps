#include <iostream>
#include <vector>
#include "MyString.h"

using namespace std;

int main()
{
	MyString a;
    MyString b {MyString{"Hello"}};
    MyString c {b};
    
    a = b;
    c = MyString{"New"};
    b = "Changed";
    
    std::cout << "========= vector ===========" << std::endl;
    
    std::vector<MyString> vec;
    vec.push_back("VecElem1");
    vec.push_back("VecElem2");
    vec.push_back(MyString{"VecElem3"});
    
    vec.at(0) = "Changed1";
    vec.at(1) = MyString{"Changed2"};
    
	return 0;
}
