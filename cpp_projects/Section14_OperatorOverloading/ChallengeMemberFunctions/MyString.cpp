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


//EXTERNAL FUNCTIONS

//"-"before (to lower case with no change) 
MyString operator-(const MyString &obj)
{
    MyString temp;
    delete [] temp.pStr;
    temp.pStr = new char[std::strlen(obj.pStr) + 1]; 
    for (size_t i = 0; i < (std::strlen(obj.pStr) + 1); ++i)
        temp.pStr[i] = std::tolower(obj.pStr[i]);
    return temp;
}

//"-"after (to lower case with change)  not working!!!
/*MyString &operator-(MyString &obj, int)
{
    for (size_t i = 0; i < std::strlen(obj.pStr); ++i)
        obj.pStr[i] = std::tolower(obj.pStr[i]);
    return obj;
}*/

//"++"prefix (all to upper case)
MyString &operator++(MyString &obj)
{
    MyString temp{obj};
    for (size_t i = 0; i < (std::strlen(temp.pStr) + 1); ++i)
        obj.pStr[i] = std::toupper(temp.pStr[i]);
    return obj;
}

//"++"postfix (all to upper case)
MyString operator++(MyString &obj, int)
{
    MyString temp{obj};
    ++obj;
    return temp;
}

//"=="
bool operator==(const MyString &lhs, const MyString &rhs)
{
    return (std::strcmp(lhs.pStr, rhs.pStr) == 0);
}

//"!="
bool operator!=(const MyString &lhs, const MyString &rhs)
{
    return (std::strcmp(lhs.pStr, rhs.pStr) != 0);
}

//"+"
MyString operator+(const MyString &lhs, const MyString &rhs)
{
    MyString temp;
    delete [] temp.pStr;
    temp.pStr = new char[std::strlen(lhs.pStr) + std::strlen(rhs.pStr) + 1]; 
    std::strcpy(temp.pStr, lhs.pStr);
    std::strcat(temp.pStr, rhs.pStr);
    return temp;
}

//"+="
MyString &operator+=(MyString &lhs, const MyString &rhs)
{
    lhs = lhs + rhs;
    return lhs;
}

//"*"
MyString operator*(const MyString &lhs, const int mul)
{
    MyString temp;
    for (size_t i = 0; i < mul; ++i)        
        temp += lhs;
    return temp;
}

//"*="
MyString &operator*=(MyString &lhs, const int mul)
{
    MyString temp{lhs};
    lhs = "";
    for (size_t i = 0; i < mul; ++i)     
        lhs += temp;
    return lhs;
}

//">"
bool operator>(const MyString &lhs, const MyString &rhs)
{
    return (std::strcmp(lhs.pStr, rhs.pStr) > 0);    
}
//">"
bool operator<(const MyString &lhs, const MyString &rhs)
{
    return (std::strcmp(lhs.pStr, rhs.pStr) < 0);    
}

//cout "<<"
std::ostream &operator<<(std::ostream &lhsOs, const MyString &rhsObj)
{
    lhsOs << rhsObj.pStr;
    return lhsOs;
}

//cin ">>"
std::istream &operator>>(std::istream &lhsIs, MyString &rhsObj)
{
    char* pTempBuf = new char[1000];
    lhsIs >> pTempBuf;
    std::cout << "!" << std::endl;
    rhsObj = MyString{pTempBuf};
    delete [] pTempBuf;
    return lhsIs;
}