#include <iostream>
#include <memory>

class Base
{
public:
    virtual void SayHello() const
    {
        std::cout << "Hello, I am a Base class" << std::endl;
    }
};

class Derived: public Base
{
public:
    virtual void SayHello() const
    {
        std::cout << "Hello, I am a Derived class" << std::endl;
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
    b.SayHello();
    
    Derived d;
    d.SayHello();
    
    Greetings(b);
    Greetings(d);
    
    Base* pBase = new Derived();
    pBase->SayHello();
    
    delete pBase;
    
    return 0;
}
