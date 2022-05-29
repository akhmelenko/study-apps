#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <cstring>
#include <iostream>

class MyString
{    
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

    //UNARY
    //"-"prefix (to lower case)
    MyString operator-() const;
    //"++"prefix (all to upper case)
    MyString &operator++();
    //"++"postfix (all to upper case)
    MyString operator++(int);
    
    //BINARY    
    //"=="
    bool operator==(const MyString &rhs) const;
    //"!="
    bool operator!=(const MyString &rhs) const;
    //"+"
    MyString operator+(const MyString &rhs) const;
    //"+="
    MyString &operator+=(const MyString &rhs);
    //"*"
    MyString operator*(const size_t mul) const;
    //"*"
    MyString &operator*=(const size_t mul);
    //">"
    bool operator>(const MyString &rhs) const;
    //"<"
    bool operator<(const MyString &rhs) const;   
};

#endif // _MYSTRING_H_
