#include "TrustAccount.h"
#include "SavingsAccount.h"

TrustAccount::TrustAccount(std::string name, double balance, double interestRate)
    :SavingsAccount(name, balance, interestRate), withdrawNumber{0}
{
}

bool TrustAccount::Deposit(double amount)
{
    if (amount >= bonusThreshold)
        return SavingsAccount::Deposit(amount + bonus);
    else
        return SavingsAccount::Deposit(amount);
}

bool TrustAccount::Withdraw(double amount)
{
    if (amount > 0)
    {
        if (withdrawNumber < maxWithdrawNumber)
        {
            if (amount < balance * maxWithdrawPercent)
            {
                if (SavingsAccount::Withdraw(amount))
                {
                    withdrawNumber++;
                    return true;
                }
                else
                    return false;
            }            
            else
            {                
                std::cout << "Withdraw amount More then MAX percent!" << std::endl;
                return false;
            }
        }
        else
        {
            std::cout << "Withdraw number limit exceed" << std::endl;
            return false;
        }
    }
}

void TrustAccount::Print(std::ostream &os) const
{
    os << "[Trust account: " << this->name << ": " 
        << this->balance << ", " 
        << this->interestRate << "%, "
        << "executed withdrawals: " << this->withdrawNumber << "]";
}
/*std::ostream &operator<<(std::ostream &os, const TrustAccount &account)
{
    os << "[Trust account: " << account.name << ": " 
        << account.balance << ", " 
        << account.interestRate << "%, " 
        << "executed withdrawals: " << account.withdrawNumber << "]";
    return os;
}*/