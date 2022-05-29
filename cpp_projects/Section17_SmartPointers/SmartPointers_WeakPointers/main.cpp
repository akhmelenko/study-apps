#include <iostream>
#include <memory>

class B; //!!! FORWARD DECLARATION

class A
{
    std::shared_ptr<B> pB;
public:
    SetBPtr(const std::shared_ptr<B> &pB_)
    {
        pB = pB_;
    }
    A(){ std::cout << "A constructor" << std::endl;}
    ~A(){ std::cout << "A destructor" << std::endl;}
};

class B
{
    //std::shared_ptr<A> pA;
    std::weak_ptr<A> pA; // !!! MAKE WEAK TO BREAK THE STRONG CIRCULAR REFERENCE
public:
    SetAPtr(const std::shared_ptr<A> &pA_)
    {
        pA = pA_;
    }
    B(){ std::cout << "B constructor" << std::endl;}
    ~B(){ std::cout << "B destructor" << std::endl;}
};


int main()
{
    //std::weak_ptr<A> ptrA = std::make_shared<A>();
    //std::weak_ptr<B> ptrB = std::make_shared<B>();
    
    std::shared_ptr<A> ptrA = std::make_shared<A>();
    std::shared_ptr<B> ptrB = std::make_shared<B>();
    
    ptrA->SetBPtr(ptrB);
    ptrB->SetAPtr(ptrA);
    
	return 0;
}
