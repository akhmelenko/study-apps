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
    //"=" (assignment)
    //copy
    MyString &operator=(const MyString &rhs); //copy assignment
    //move
    MyString &operator=(MyString &&src) noexcept; //move assignment
    //"-"before (to lower case)
    MyString operator-() const;
    //"=="
    bool operator==(const MyString &rhs) const; 
    //"+"
    MyString operator+(const MyString &rhs) const; 
    
};

#endif // _MYSTRING_H_
