#include <iostream>

using namespace std;

class Base
{
private:
    int value;

public:
    Base() : value{0} { cout << "Base no args ctor" << endl;};
    Base(int x) : value{x} { cout << "Base (int) overloaded ctor" << endl;};
    ~Base() {cout << "Base detor" << endl;};        
};

class Derived : public Base
{
private:
    int doubledValue;

public:
    Derived() 
        : Base{}, doubledValue{0} 
    { 
        cout << "Derived no args ctor" << endl;
    };
    Derived(int x)
        :Base{x}, doubledValue{2*x} 
    { 
        cout << "Derived (int) overloaded ctor" << endl;
    };
    ~Derived() 
    {
        cout << "Derived detor" << endl;
    };        
};

int main()
{
    
    //Derived derived;
    Derived derivedInit{2000};
    
	return 0;
}
