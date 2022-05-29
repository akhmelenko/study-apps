#include <iostream>
#include <memory>

class Base //!!!final
{
public:
    virtual void SayHello() const //!!! final
    {
        std::cout << "Hello, I am a Base class" << std::endl;
    }
    virtual ~Base()
    {
        std::cout << "Base virtual destructor" << std::endl;
    }
};

class Derived: public Base
{
public:
    virtual void SayHello() const override
    {
        std::cout << "Hello, I am a Derived class" << std::endl;
    }
    virtual ~Derived()
    {
        std::cout << "Derived virtual destructor" << std::endl;
    }
};

void Greetings(const Base &obj)
{
    std::cout << "Greetings" << std::endl;
    obj.SayHello();
}

int main()
{

    Base b;
    Base &refB = b;
    Greetings(refB);
    
    Derived d;
    Base &refD = d;
    Greetings(refD);
    
    
    return 0;
}
