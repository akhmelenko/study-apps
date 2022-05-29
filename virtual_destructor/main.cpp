
#include <iostream>

class Base
{
public:
    Base()
    {
        std::cout << "Base ctor\n";
    }
    virtual ~Base()
    {
        std::cout << "Base detor\n";
    }

    virtual void Foo() = 0;
    // {
    //     std::cout << "Base Foo()\n";
    // }
};

class Derived : public Base
{
public:
    Derived()
    {
        std::cout << "Derived ctor\n";
    }
    virtual ~Derived()
    {
        std::cout << "Derived detor\n";
    }

    virtual void Foo() override
    {
        std::cout << "Derived Foo()\n";
    }
};

int main()
{
    Base *b = new Derived();
    b->Foo();
    delete b;
    return 0;
}