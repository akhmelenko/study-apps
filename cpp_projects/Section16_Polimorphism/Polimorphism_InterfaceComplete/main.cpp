#include <iostream>

class I_Printable
{
    friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);
public:
    virtual void Print(std::ostream &os) const = 0;
    virtual ~I_Printable() = default;
};

std::ostream &operator<<(std::ostream &os, const I_Printable &obj)
{
    obj.Print(os);
    return os;
}

class Account : public I_Printable
{
public:
    virtual void Print(std::ostream &os) const override
    {
        os << "In Account";
    }
    virtual ~Account() {}
};

class Savings : public Account
{
public:
    virtual void Print(std::ostream &os) const override
    {
        os << "In Savings";
    }
    virtual ~Savings() {}
};

class Trust : public Account
{
public:
    virtual void Print(std::ostream &os) const override
    {
        os << "In Trust";
    }
    virtual ~Trust() {}
};

class Dog : public I_Printable
{
public:
    virtual void Print(std::ostream &os) const override
    {
        os << "Woow";
    }
    virtual ~Dog() {}
};

void Print(const I_Printable &obj)
{
    std::cout << obj << std::endl;
}

int main()
{
	Dog* pDog = new Dog();
    Print(*pDog);
    
    Account* pAccount = new Account();
    std::cout << *pAccount << std::endl;
    Print(*pAccount);
    
    Savings* pSavings = new Savings();
    Print(*pSavings);
    
    Trust* pTrust = new Trust();
    Print(*pTrust);
    
	return 0;
}
