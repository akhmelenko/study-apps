#include "Account.h"
#include <iostream>

using namespace std;

Account::Account()
    :balance{0.0}, name{"Empty Account"}
{
}

Account::~Account()
{
}

double Account::GetBalance()
{
    return this->balance;
}

void Account::Deposit(double amount)
{
    cout << "Account deposit called with " << amount << endl;
    balance += amount;
}

void Account::Withdraw(double amount)
{
    cout << "Account withdraw called with " << amount << endl;
    if ((this->balance - amount) > 0)
        this->balance -= amount;
    else
       cout << "Account withdraw ERR: not enough money!" << endl; 
}