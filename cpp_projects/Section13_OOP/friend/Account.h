#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <string>


class Account
{
    friend void FriendDisplayAccount(Account &a);
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
    double GetBalance() const;
    void SetBalance(double newBalance);
    //ctor
    Account(std::string name_ = "AccountName", double balance_ = 0.0);       
    //copy ctor
    Account(const Account &src);        
    //detor
    ~Account();
};

#endif // _ACCOUNT_H_
