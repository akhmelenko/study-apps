#include <iostream>

using namespace std;

int main()
{
    int num1 {}, num2 {};
    double average {0.0};
    
    cout << "Enter 2 numbers" << endl;
    cin >> num1 >> num2;
    average = (static_cast<double>(num1) + num2)/2;
	cout << "Average = " << average << endl;
    
	return 0;
}
