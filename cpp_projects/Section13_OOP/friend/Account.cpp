#include "Account.h"


//ctor
Account::Account(std::string name_, double balance_)        
    :name{name_}, balance{balance_}
{
}
//copy ctor
Account::Account(const Account &src)        
    :Account(src.name, src.balance)
{
}
//detor
Account::~Account()
{

}

double Account::GetBalance() const
{
    return balance;
}

void Account::SetBalance(double newBalance)
{
    balance = newBalance;
}