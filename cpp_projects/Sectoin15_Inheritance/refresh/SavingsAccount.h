#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account
{
private:
    double rate;
public:
    SavingsAccount(string name, double balance)
        : Account(name, balance), rate{0}
    {        
    };
    void SetRate(double inputRate)
    {
        rate = inputRate;
    };
    double GetRate()
    {
        return rate;
    };   
};

#endif // SAVINGS_ACCOUNT_H
