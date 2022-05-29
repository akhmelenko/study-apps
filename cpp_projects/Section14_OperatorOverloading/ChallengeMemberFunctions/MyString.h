#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <cstring>
#include <iostream>

class MyString
{
    //UNARY
    //"-"prefix (to lower case)
    friend MyString operator-(const MyString &obj);
    //"-"postfix (delete number of chars) not working!!!
    //friend MyString &operator-(MyString &obj, int);
    //"++"prefix (all to upper case)
    friend MyString &operator++(MyString &obj);
    //"++"postfix (all to upper case)
    friend MyString operator++(MyString &obj, int);
    
    //BINARY    
    //"=="
    friend bool operator==(const MyString &lhs, const MyString &rhs);
    //"!="
    friend bool operator!=(const MyString &lhs, const MyString &rhs);
    //"+"
    friend MyString operator+(const MyString &lhs, const MyString &rhs);
    //"+="
    friend MyString &operator+=(MyString &lhs, const MyString &rhs);
    //"*"
    friend MyString operator*(const MyString &lhs, const int mul);
    //"*"
    friend MyString &operator*=(MyString &lhs, const int mul);
    //">"
    friend bool operator>(const MyString &lhs, const MyString &rhs);
    //"<"
    friend bool operator<(const MyString &lhs, const MyString &rhs);
    //cout "<<"
    friend std::ostream &operator<<(std::ostream &lhsOs, const MyString &rhsObj);
    //cin ">>"
    friend std::istream &operator>>(std::istream &lhsIs, MyString &rhsObj);
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
};

#endif // _MYSTRING_H_
