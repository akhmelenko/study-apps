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
MyString &MyString::operator=(MyString &&rhs) noexcept
{
    std::cout << "Move assingment" << std::endl;
    delete [] this->pStr;
    this->pStr = rhs.pStr;
    rhs.pStr = nullptr;
    return *this;
}

//"-"before (to lower case)
MyString MyString::operator-() const
{
    /*char* pBufStr = new char[std::strlen(this->pStr) + 1];
    for (size_t i = 0; i < (std::strlen(this->pStr) + 1); ++i)
        pBufStr[i] = std::tolower(this->pStr[i]);
    MyString temp{pBufStr};
    delete [] pBufStr;
    return temp;*/
    MyString temp;
    delete [] temp.pStr;
    temp.pStr = new char[std::strlen(this->pStr) + 1]; 
    for (size_t i = 0; i < (std::strlen(this->pStr) + 1); ++i)
        temp.pStr[i] = std::tolower(this->pStr[i]);
    return temp;
}
//"-"after (to lower case)
/*MyString MyString::-operator() const
{
    MyString temp;
    delete [] temp.pStr;
    temp.pStr = new char[std::strlen(this->pStr) + 1]; 
    for (size_t i = 0; i < (std::strlen(this->pStr) + 1); ++i)
        temp.pStr[i] = std::tolower(this->pStr[i]);
    return temp;
}*/

//"==" (compare by content)
bool MyString::operator==(const MyString &rhs) const
{
    if (std::strcmp(this->pStr, rhs.pStr))
        return false;
    else
        return true;
}

//"+" (concatenate)
MyString MyString::operator+(const MyString &rhs) const
{
    /*size_t thisLen = std::strlen(this->pStr);
    size_t srcLen = std::strlen(rhs.pStr);
    char* pBufStr = new char[thisLen + srcLen + 1];
    std::strcpy(pBufStr, this->pStr);
    std::strcat(pBufStr, rhs.pStr);
    MyString temp{pBufStr};
    delete [] pBufStr;
    return temp;*/
    size_t thisLen = std::strlen(this->pStr);
    size_t srcLen = std::strlen(rhs.pStr);
    MyString temp;
    delete [] temp.pStr;
    temp.pStr = new char[thisLen + srcLen + 1];
    std::strcpy(temp.pStr, this->pStr);
    std::strcat(temp.pStr, rhs.pStr);
    return temp;
}
