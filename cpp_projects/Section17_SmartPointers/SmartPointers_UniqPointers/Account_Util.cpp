#include "Account_Util.h"

//Helper functions for Account class
void Display(const std::vector<Account*> &pAccounts)
{
    std::cout << "\n======== Accounts ============" << std::endl;
    for (const auto pAcc: pAccounts)
    {
        std::cout << *pAcc << std::endl;
    }
}

void Deposit(std::vector<Account*> &pAccounts, double amount)
{
    std::cout << "\n======== Depositing to Accounts ============" << std::endl;
    for (auto pAcc: pAccounts)
    {
        if (pAcc->Deposit(amount))
            std::cout << "Deposited " << amount << " to " << *pAcc << std::endl;
        else
            std::cout << "Failed Deposited of " << amount << " to " << *pAcc << std::endl;
    }
}

void Withdraw(std::vector<Account*> &pAccounts, double amount)
{
    std::cout << "\n======== Withdrawing from Accounts ============" << std::endl;
    for (auto pAcc: pAccounts)
    {
        if (pAcc->Withdraw(amount))
            std::cout << "Withdrew " << amount << " from " << *pAcc << std::endl;
        else
            std::cout << "Failed to Withdrawal of " << amount << " from " << *pAcc << std::endl;
    }
}
