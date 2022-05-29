#include <iostream>
#include "double.h"

using namespace std;

int main ()
{
    cout << "Enter variable for double2: ";
    int var;
    cin >> var;

    cout << "Double = " << Double(var);
    
    int a;
    cin >> a;
    return 0;
}