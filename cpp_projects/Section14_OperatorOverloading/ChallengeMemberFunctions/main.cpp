#include <iostream>
#include <vector>
#include "MyString.h"

using namespace std;


int main()
{
    MyString larry{"Larry"};
    MyString moe{"Moe"};
    //MyString b = -larry;
    
    /*if (larry == b)
    {
        cout << "EQUAL" << endl;
    }
    else
    {
        cout << "NOT EQUAL" << endl;
    }
    
    MyString conc = b + " " + larry + " " + moe;
    
    cout << "===========================" << endl;
    cout << "Simple string output" << endl;
    cout << "Overload string output for " << larry << " and " << moe << endl;
    cout << "===========================" << endl;
    
    MyString name0, name1, name2; 
    
    cout << "Enter 3 names separated by space" << endl;
    cin >> name0 >> name1 >> name2;
    cout << "You entered: " << name0 << ", " << name1 << " and " << name2 << endl;
    
    cout << "===========================" << endl;*/
    
    MyString invert{"INvert"};
    MyString copied{-invert};
    
    cout << "========= == != ===============" << endl;
    cout <<(invert==copied)<<endl;
    cout <<(invert!=copied)<<endl;
    cout << "============ > < ===============" << endl;
    cout <<(invert<copied)<<endl;
    cout <<(invert>copied)<<endl;
    cout <<("knvert">copied)<<endl;
    cout <<("knvert"<copied)<<endl;
    cout << "============ += ===============" << endl;
    invert += "Knvert";
    invert += "Envert";
    cout << invert << endl;
    cout << "============ * =================" << endl;
    copied = "Mul ";
    invert = copied * 5;
    invert = MyString{"mulSTR "} * 5;
    cout << "Mul * 5 " << invert << endl;
    cout << "============ *= =================" << endl;
    copied = "Mul2 ";
    copied *= 8;
    cout << "Mul2 * 8 " << copied << endl;
    cout << "============ ++pre =================" << endl;
    ++copied;
    cout << copied << endl;
    cout << "============ post++ =================" << endl;
    invert = "Post++";
    //invert++;
    cout << invert++ << endl;
    
	return 0;
}
