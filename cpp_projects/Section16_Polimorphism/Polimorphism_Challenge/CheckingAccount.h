#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_

#include "Account.h"
#include <iostream>

class CheckingAccount: public Account
{
    //friend std::ostream &operator<<(std::ostream &os, const CheckingAccount &account);
private:
    static constexpr const char* pDefName = "Unnamed Checking account";
    static constexpr double defBalance = 0.0;
    static constexpr double withdrawFee = 1.50;
public:
    CheckingAccount(std::string name = pDefName, double balance = defBalance);
    virtual void Print(std::ostream &os) const override;
    virtual bool Deposit(double amount) override;
    virtual bool Withdraw(double amount) override;
    virtual ~CheckingAccount() = default;
};

#endif // _CHECKING_ACCOUNT_H_
