#include "Account_Util.h"

//Helper functions for Account class
void Display(const std::vector<Account> &accounts)
{
    std::cout << "======== Accounts ============" << std::endl;
    for (const auto &acc: accounts)
    {
        std::cout << acc << std::endl;
    }
}

void Deposit(std::vector<Account> &accounts, double amount)
{
    std::cout << "\n======== Depositing to Accounts ============" << std::endl;
    for (auto &acc: accounts)
    {
        if (acc.Deposit(amount))
            std::cout << "Deposited " << amount << " to " << acc << std::endl;
        else
            std::cout << "Failed Deposited of " << amount << " to " << acc << std::endl;
    }
}

void Withdraw(std::vector<Account> &accounts, double amount)
{
    std::cout << "\n======== Withdrawing from Accounts ============" << std::endl;
    for (auto &acc: accounts)
    {
        if (acc.Withdraw(amount))
            std::cout << "Withdrew " << amount << " from " << acc << std::endl;
        else
            std::cout << "Failed to Withdrawal of " << amount << " from " << acc << std::endl;
    }
}


//Helper functions for SavingsAccount class
void Display(const std::vector<SavingsAccount> &accounts)
{
    std::cout << "\n======== Savings Accounts ============" << std::endl;
    for (auto &acc: accounts)
    {
        std::cout << acc << std::endl;
    }
}

void Deposit(std::vector<SavingsAccount> &accounts, double amount)
{
    std::cout << "\n======== Depositing to Savings Accounts ============" << std::endl;
    for (auto &acc: accounts)
    {
        if (acc.Deposit(amount))
            std::cout << "Deposited " << amount << " to " << acc << std::endl;
        else
            std::cout << "Failed Deposited of " << amount << " to " << acc << std::endl;
    }
}

void Withdraw(std::vector<SavingsAccount> &accounts, double amount)
{
    std::cout << "\n======== Withdrawing from Savings Accounts ============" << std::endl;
    for (auto &acc: accounts)
    {
        if (acc.Withdraw(amount))
            std::cout << "Withdrew " << amount << " from " << acc << std::endl;
        else
            std::cout << "Failed to Withdrawal of " << amount << " from " << acc << std::endl;
    }
}
