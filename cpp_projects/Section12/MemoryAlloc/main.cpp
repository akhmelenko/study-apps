#include <iostream>
#include <array>


using namespace std;

int main()
{
    int* pInt {nullptr};
    cout << "before alloc pInt = " << pInt << endl;
    
    pInt = new int;    
	cout << "afrter alloc pInt = " << pInt << endl;
    cout << "*pInt = " << *pInt << endl;
    *pInt = 30;
    cout << "*pInt = " << *pInt << endl;
    delete pInt;
    cout << "after delete pInt = " << pInt << endl;
    cout << "after delete *pInt = " << *pInt << endl;
    
    cout << "and again ========================== " << endl;
    
    pInt = new int;    
	cout << "afrter alloc pInt = " << pInt << endl;
    cout << "*pInt = " << *pInt << endl;
    *pInt = 30;
    cout << "*pInt = " << *pInt << endl;
    delete pInt;
    cout << "after delete pInt = " << pInt << endl;
    cout << "after delete *pInt = " << *pInt << endl;
    
    cout << "and alloc array ========================== " << endl;
    
    int size {4};
    pInt = new int[size];    
	cout << "after alloc pInt = " << pInt << endl;
    cout << "*pInt = " << *pInt << endl;
    pInt[0] = 0;
    pInt[1] = 10;
    pInt[2] = 20;
    pInt[3] = 30;
    cout << "*pInt[0] = " << pInt[0] << endl;
    cout << "*pInt[1] = " << pInt[1] << endl;
    cout << "*pInt[2] = " << pInt[2] << endl;
    cout << "*pInt[3] = " << pInt[3] << endl;
    delete [] pInt;
    cout << "after delete pInt = " << pInt << endl;
    cout << "after delete *pInt = " << *pInt << endl;
    cout << "*pInt[0] = " << pInt[0] << endl;
    cout << "*pInt[1] = " << pInt[1] << endl;
    cout << "*pInt[2] = " << pInt[2] << endl;
    cout << "*pInt[3] = " << pInt[3] << endl;
    
    cout << "and usual array ========================== " << endl;
    int array1[4] {10, 20, 30, 40};
    pInt = array1;
    cout << "*pInt[0] = " << pInt[0] << endl;
    cout << "*pInt[1] = " << pInt[1] << endl;
    cout << "*pInt[2] = " << pInt[2] << endl;
    cout << "*pInt[3] = " << pInt[3] << endl;
    
	return 0;
}
    