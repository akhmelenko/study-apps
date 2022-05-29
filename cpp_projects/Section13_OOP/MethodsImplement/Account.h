#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <string>


class Account
{
private:
    //attributes
    std::string name {"AccountName"};
    double balance {0.0};
    
public:    
    //methods
    bool Deposit(double money) 
    {
        balance += money; 
        return true;
    };
    bool Withdraw(double money) 
    {        
        if (balance-money >= 0)
        {
            balance -= money;
            return true;
        }        
        else
        {
            return false;            
        }
    };
    //outside definition
    double GetBalance();
    void SetBalance(double newBalance);

};

#endif // _ACCOUNT_H_
