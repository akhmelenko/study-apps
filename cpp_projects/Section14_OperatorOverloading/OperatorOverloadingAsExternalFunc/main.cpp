#include <iostream>
#include <vector>
#include "MyString.h"

using namespace std;


int main()
{
    MyString larry{"Larry"};
    MyString moe{"Moe"};
    MyString b = -larry;
    
    if (larry == b)
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
    
    
	return 0;
}
