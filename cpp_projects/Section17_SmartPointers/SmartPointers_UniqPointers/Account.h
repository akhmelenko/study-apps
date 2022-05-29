#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <iostream>
#include <I_Printable.h>


class Account : public I_Printable
{
    //friend std::ostream &operator<<(std::ostream &os, const Account &account);
private:
    static constexpr const char* pDefName = "Unnamed account";
    static constexpr double defBalance = 0.0;
protected:
    std::string name;
    double balance;
public:
    //Account();
    Account(std::string name = pDefName, double balance = defBalance);
    virtual bool Deposit(double amount) = 0;
    virtual bool Withdraw(double amount) = 0;
    double GetBalance() const;
    virtual ~Account() = default;
};

#endif // _ACCOUNT_H_
