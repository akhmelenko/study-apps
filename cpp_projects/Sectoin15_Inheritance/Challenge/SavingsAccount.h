#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_

#include "Account.h"
#include <iostream>

class SavingsAccount : public Account
{
    friend std::ostream &operator<<(std::ostream &os, const SavingsAccount &account);
private:
    static constexpr const char* pDefaultName = "Unnamed Savings Account";
    static constexpr double defBalance = 0.0;
    static constexpr double defInterestRate = 0.0;
protected:
    double interestRate;
public:
    //SavingsAccount();
    SavingsAccount(std::string name = pDefaultName, double balance = defBalance, double interestRate = defInterestRate);
    bool Deposit(double amount);
    //Withdraw is inherited
};

#endif // _SAVINGS_ACCOUNT_H_
