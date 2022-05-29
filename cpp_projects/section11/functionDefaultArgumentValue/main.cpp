#include <iostream>

using namespace std;

int Adder(int a = 1, int b = 2);

int main()
{
	cout << "Adder default is " << Adder() << endl;
    cout << "Adder (a = 10) is " << Adder(10) << endl;
    cout << "Adder (a = 10, b = 20) is " << Adder(10, 20) << endl;
}

int Adder(int a, int b)
{
    return a + b;
}