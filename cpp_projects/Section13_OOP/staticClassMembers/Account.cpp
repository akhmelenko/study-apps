#include "Account.h"


int Account::accountsNumber {0};

//ctor
Account::Account(std::string name_, double balance_)        
    :name{name_}, balance{balance_}
{
    ++accountsNumber;
}
//copy ctor
Account::Account(const Account &src)        
    :Account(src.name, src.balance)
{
}
//detor
Account::~Account()
{
    --accountsNumber;
}

int Account::GetAccountsNumber()
{
    return accountsNumber;
}

double Account::GetBalance() const
{
    return balance;
}

void Account::SetBalance(double newBalance)
{
    balance = newBalance;
}