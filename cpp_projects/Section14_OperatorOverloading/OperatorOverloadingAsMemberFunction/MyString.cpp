#include "MyString.h"
#include <iostream>

MyString::MyString()
    :pStr{nullptr}
{
    std::cout << "Empty ctor" << std::endl;
    this->pStr = new char[1];
    *this->pStr = '\0';
}
MyString::MyString(const char* pStr)
    :pStr{nullptr}
{
    std::cout << "Impl ctor" << std::endl;
    this->pStr = new char[std::strlen(pStr) + 1];
    std::strcpy(this->pStr, pStr);
}
MyString::MyString(const MyString &src)
    :pStr{nullptr}
{
    std::cout << "Copy ctor" << std::endl;
    this->pStr = new char[std::strlen(src.pStr) + 1];
    std::strcpy(this->pStr, src.pStr);
}
MyString::MyString(MyString &&src) noexcept
    :pStr{nullptr}
{
    std::cout << "Move ctor" << std::endl;
    this->pStr = src.pStr;
    src.pStr = nullptr;
}
MyString::~MyString()
{
    if (this->pStr == nullptr)
        std::cout << "Detor of nullptr" << std::endl;
    else
    {
        char* pTemp = this->pStr;
        std::cout << "Detor of ";
        while (*pTemp != '\0')
            std::cout << *pTemp++;
        std::cout << std::endl;        
    }
    delete [] this->pStr;
}

//operators overloading
//copy=
MyString &MyString::operator=(const MyString &rhs)
{
    std::cout << "Copy assingment" << std::endl;
    if (this == &rhs)
        return *this;
    delete [] this->pStr;
    this->pStr = new char[std::strlen(rhs.pStr) + 1];
    std::strcpy(this->pStr, rhs.pStr);
    return *this;
}
//move=
MyString &MyString::operator=(MyString &&src) noexcept
{
    std::cout << "Move assingment" << std::endl;
    delete [] this->pStr;
    this->pStr = src.pStr;
    src.pStr = nullptr;
    return *this;
}