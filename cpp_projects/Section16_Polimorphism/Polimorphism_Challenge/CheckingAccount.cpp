#include "CheckingAccount.h"
#include "Account.h"

CheckingAccount::CheckingAccount(std::string name, double balance)
    :Account(name, balance)
{
}

bool CheckingAccount::Withdraw(double amount)
{
    return Account::Withdraw(amount + withdrawFee);
}

bool CheckingAccount::Deposit(double amount)
{
    return Account::Deposit(amount);
}

void CheckingAccount::Print(std::ostream &os) const
{
    os << "[Checking account: " << this->name << ": " << this->balance << "]";
}
/*std::ostream &operator<<(std::ostream &os, const CheckingAccount &account)
{
    os << "[Checking Account: " << account.name << ": " << account.balance << "]";
    return os;
}*/



