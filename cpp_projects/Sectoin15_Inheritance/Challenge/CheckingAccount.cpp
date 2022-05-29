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

std::ostream &operator<<(std::ostream &os, const CheckingAccount &account)
{
    os << "[Checking Account: " << account.name << ": " << account.balance << "]";
    return os;
}



