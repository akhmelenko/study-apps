#include "SavingsAccount.h"


SavingsAccount::SavingsAccount(std::string name, double balance, double interestRate)
    : Account(name, balance), interestRate{interestRate}
{
}

/*SavingsAccount::SavingsAccount()
    : SavingsAccount(0.0, 0.0)
{
}*/

bool SavingsAccount::Deposit(double amount)
{
    amount = amount + amount*this->interestRate/100;
    return Account::Deposit(amount);
}

bool SavingsAccount::Withdraw(double amount)
{
    return Account::Withdraw(amount);
}

void SavingsAccount::Print(std::ostream &os) const
{
    os << "[Savings account: " << this->name << ": " << this->balance << ", " << this->interestRate << "%]";
}
/*std::ostream &operator<<(std::ostream &os, const SavingsAccount &account)
{
    os << "[Savings account: " << account.name << ": " << account.balance << ", " << account.interestRate << "%]";
    return os;
}*/
