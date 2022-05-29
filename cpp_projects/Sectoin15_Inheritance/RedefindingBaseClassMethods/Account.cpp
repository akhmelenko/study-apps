#include "Account.h"

Account::Account()
    : balance{0.0}
{
}

Account::Account(double balance)
    : balance{balance}
{
}

void Account::Deposit(double amount)
{
    this->balance += amount;
}

void Account::Withdraw(double amount)
{
    if (this->balance - amount >= 0)
        this->balance -= amount;
    else
        std::cout << "Insufficient fund" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Account &account)
{
    os << "Account balance: " << account.balance;
    return os;
}
