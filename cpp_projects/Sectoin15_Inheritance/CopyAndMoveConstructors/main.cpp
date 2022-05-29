#include <iostream>

using namespace std;

class Base
{
private:
    int value;

public:
    Base() : value{0} { cout << "Base no args ctor" << endl;};
    Base(int x) : value{x} { cout << "Base (int) overloaded ctor" << endl;};
    Base(const Base &other) : value{other.value} { cout << "Base copy ctor" << endl;};
    ~Base() {cout << "Base detor" << endl;};

    Base &operator=(const Base &rhs)
    {
        if (this != &rhs)
            this->value = rhs.value;
        return *this;
    };
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
    Derived(const Derived &other)
        :Base{other}, doubledValue{2*other.doubledValue} 
    { 
        cout << "Derived copy ctor" << endl;
    };
    ~Derived() 
    {
        cout << "Derived detor" << endl;
    };     

    Derived &operator=(const Derived &rhs)
    {
        if (this != &rhs)
        {
            Base::operator=(rhs);
            this->doubledValue = rhs.doubledValue;            
        }
        return *this;
    };   
};

int main()
{
        
    Derived derivedInit{2000};
    Derived derived2{derivedInit};
    Derived c;
    c = derived2;
    
	return 0;
}
