#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_

#include "Account.h"
#include <iostream>

class SavingsAccount : public Account
{
    //friend std::ostream &operator<<(std::ostream &os, const SavingsAccount &account);
private:
    static constexpr const char* pDefaultName = "Unnamed Savings Account";
    static constexpr double defBalance = 0.0;
    static constexpr double defInterestRate = 0.0;
protected:
    double interestRate;
public:
    //SavingsAccount();
    SavingsAccount(std::string name = pDefaultName, double balance = defBalance, double interestRate = defInterestRate);
    virtual void Print(std::ostream &os) const override;
    virtual bool Deposit(double amount) override;
    virtual bool Withdraw(double amount) override;
    virtual ~SavingsAccount() = default;
};

#endif // _SAVINGS_ACCOUNT_H_
