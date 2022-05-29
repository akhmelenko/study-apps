#include <iostream>
#include <vector>
#include "Account.h"
#include "SavingsAccount.h"
#include "Account_Util.h"

using namespace std;

int main()
{ 
    cout.precision(2);
    cout << fixed;
    
    std::vector<Account> accounts;
    accounts.push_back(Account {});
    accounts.push_back(Account {"Larry"});
    accounts.push_back(Account {"Moe", 2000});
    accounts.push_back(Account {"Curly", 5000});

    Display(accounts);
    Deposit(accounts, 1000);
    Withdraw(accounts, 2000);

    std::vector<SavingsAccount> savAccounts;
    savAccounts.push_back(SavingsAccount {});
    savAccounts.push_back(SavingsAccount {"Superman"});
    savAccounts.push_back(SavingsAccount {"Batman", 2000});
    savAccounts.push_back(SavingsAccount {"Supergirl", 5000, 5});
    
    Display(savAccounts);
    Deposit(savAccounts, 1000);
    Withdraw(savAccounts, 2000);
}
