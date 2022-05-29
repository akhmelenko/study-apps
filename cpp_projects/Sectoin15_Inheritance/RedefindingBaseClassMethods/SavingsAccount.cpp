#include "SavingsAccount.h"


SavingsAccount::SavingsAccount(double balance, double interestRate)
    : Account(balance), interestRate{interestRate}
{
}

SavingsAccount::SavingsAccount()
    : SavingsAccount(0.0, 0.0)
{
}

void SavingsAccount::Deposit(double amount)
{
    amount = amount + amount*this->interestRate/100;
    Account::Deposit(amount);
}

std::ostream &operator<<(std::ostream &os, const SavingsAccount &account)
{
    os << "Account balance: " << account.balance << " with interst rate = " << account.interestRate << "%";
    return os;
}
