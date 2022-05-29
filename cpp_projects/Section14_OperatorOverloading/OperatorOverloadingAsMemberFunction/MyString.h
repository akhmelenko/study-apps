#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <cstring>

class MyString
{
private:
    char* pStr;
public:
    MyString();                         //empty ctor
    MyString(const char* pStr);         //implement ctor
    MyString(const MyString &src);      //copy ctor
    MyString(MyString &&src) noexcept;  //move ctor
    ~MyString();                        //detor
    //operators overloading
    MyString &operator=(const MyString &rhs); //copy asignment
    //move
    MyString &operator=(MyString &&src) noexcept; //move asignment
};

#endif // _MYSTRING_H_
