#include "Account.h"

/*Account::Account()
    : balance{0.0}
{
}*/

Account::Account(std::string name, double balance)
    : name{name}, balance{balance}
{
}

bool Account::Deposit(double amount)
{
    if (amount >= 0)
    {    
        this->balance += amount;
        return true;
    }
    else
        return false;
}

bool Account::Withdraw(double amount)
{
    if (this->balance - amount >= 0)
    {
        this->balance -= amount;
        return true;
    }
    else
    {
        std::cout << "Insufficient fund" << std::endl;
        return false;
    }
}

double Account::GetBalance(void) const
{
    return this->balance;
}

std::ostream &operator<<(std::ostream &os, const Account &account)
{
    os << "[Account: " << account.name << ": " << account.balance << "]";
    return os;
}
