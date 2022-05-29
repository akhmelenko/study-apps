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
    Base* pBase1 = new Base();
    pBase1->SayHello();
    
    Derived* pDerived1 = new Derived();
    pDerived1->SayHello();
    
    Base* pBase2 = new Derived();
    pBase2->SayHello();
    
    delete pBase1;
    delete pDerived1;
    delete pBase2;
    
    return 0;
}
