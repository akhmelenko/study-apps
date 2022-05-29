#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <string>

using namespace std;

class Account
{
public:    
    double balance;
    string name;

    Account();
    ~Account();

    void Deposit(double amount);
    void Withdraw(double amount);
    double GetBalance();
};

#endif // _ACCOUNT_H_
