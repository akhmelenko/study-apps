#include <iostream>

using namespace std;

int main()
{
    int num1 {15}, num2 {8};
            
	cout << "initial (num1 == num2) is " << (num1 == num2) <<endl;
    cout << "initial (num1 != num2) is " << (num1 != num2) <<endl;
    cout << std::boolalpha;
    cout << "boolalpha (num1 == num2) is " << (num1 == num2) <<endl;
    cout << "boolalpha (num1 != num2) is " << (num1 != num2) <<endl;
    cout << std::noboolalpha;
    cout << "noboolalpha (num1 == num2) is " << (num1 == num2) <<endl;
    cout << "noboolalpha (num1 != num2) is " << (num1 != num2) <<endl;
	return 0;
}
