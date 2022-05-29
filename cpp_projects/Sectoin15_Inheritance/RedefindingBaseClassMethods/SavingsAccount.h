#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_

#include "Account.h"
#include <iostream>

class SavingsAccount : public Account
{
    friend std::ostream &operator<<(std::ostream &os, const SavingsAccount &account);
protected:
    double interestRate;
public:
    SavingsAccount();
    SavingsAccount(double balance, double interestRate);
    void Deposit(double amount);
    //Withdraw is inherited
};

#endif // _SAVINGS_ACCOUNT_H_
