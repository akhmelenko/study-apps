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


//"-"before (to lower case with no change) 
MyString MyString::operator-() const
{
    MyString temp;
    delete [] temp.pStr;
    temp.pStr = new char[std::strlen(this->pStr) + 1]; 
    for (size_t i = 0; i < (std::strlen(this->pStr) + 1); ++i)
        temp.pStr[i] = std::tolower(this->pStr[i]);
    return temp;
}

//"++"prefix (all to upper case)
MyString &MyString::operator++()
{
    MyString temp{*this};
    for (size_t i = 0; i < (std::strlen(temp.pStr) + 1); ++i)
        this->pStr[i] = std::toupper(temp.pStr[i]);
    return *this;
}

//"++"postfix (all to upper case)
MyString MyString::operator++( int)
{
    MyString temp{*this};
    ++(*this);
    return temp;
}

//"=="
bool MyString::operator==(const MyString &rhs) const
{
    return (std::strcmp(this->pStr, rhs.pStr) == 0);
}

//"!="
bool MyString::operator!=(const MyString &rhs) const
{
    return (std::strcmp(this->pStr, rhs.pStr) != 0);
}

//"+"
MyString MyString::operator+(const MyString &rhs) const
{
    MyString temp;
    delete [] temp.pStr;
    temp.pStr = new char[std::strlen(this->pStr) + std::strlen(rhs.pStr) + 1]; 
    std::strcpy(temp.pStr, this->pStr);
    std::strcat(temp.pStr, rhs.pStr);
    return temp;
}

//"+="
MyString &MyString::operator+=(const MyString &rhs)
{
    *this = *this + rhs;
    return *this;
}

//"*"
MyString MyString::operator*(const size_t mul) const
{
    MyString temp;
    for (size_t i = 0; i < mul; ++i)        
        temp += *this;
    return temp;
}

//"*="
MyString &MyString::operator*=(const size_t mul)
{
    MyString temp{*this};
    *this = "";
    for (size_t i = 0; i < mul; ++i)     
        *this += temp;
    return *this;
}

//">"
bool MyString::operator>(const MyString &rhs) const
{
    return (std::strcmp(this->pStr, rhs.pStr) > 0);    
}
//">"
bool MyString::operator<(const MyString &rhs) const
{
    return (std::strcmp(this->pStr, rhs.pStr) < 0);    
}


//EXTERNAL FUNCTIONS

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