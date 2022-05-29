#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_

#include <iostream>
#include "SavingsAccount.h"

class TrustAccount : public SavingsAccount
{
    friend std::ostream &operator<<(std::ostream &os, const TrustAccount &account);
private:
    static constexpr const char* pDefaultName = "Unnamed Checking Account";
    static constexpr double defBalance = 0.0;
    static constexpr double defInterestRate = 0.0;
    static constexpr double bonusThreshold = 5000.0;
    static constexpr double bonus = 50.0;
    static constexpr double maxWithdrawPercent = 0.2;
    static constexpr int maxWithdrawNumber = 3;
protected:
    int withdrawNumber;
public:
    TrustAccount(std::string name = pDefaultName, double balance = defBalance, double interestRate = defInterestRate);
    bool Deposit(double amount);
    bool Withdraw(double amount);
};

#endif // _TRUST_ACCOUNT_H_
