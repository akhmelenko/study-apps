#include <iostream>
#include <vector>
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "TrustAccount.h"
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
    
    std::vector<CheckingAccount> checkAccounts;
    checkAccounts.push_back(CheckingAccount {});
    checkAccounts.push_back(CheckingAccount {"Butch"});
    checkAccounts.push_back(CheckingAccount {"Cris", 2000});
    checkAccounts.push_back(CheckingAccount {"Rooth", 5000});
    
    Display(checkAccounts);
    Deposit(checkAccounts, 1000);
    Withdraw(checkAccounts, 2000);
    
    std::vector<TrustAccount> trustAccounts;
    trustAccounts.push_back(TrustAccount {});
    trustAccounts.push_back(TrustAccount {"Bill"});
    trustAccounts.push_back(TrustAccount {"Barak", 2000});
    trustAccounts.push_back(TrustAccount {"Donald", 5000, 10});
    
    Display(trustAccounts);
    Deposit(trustAccounts, 1000);
    Deposit(trustAccounts, 6000);
    Withdraw(trustAccounts, 2000);
    Withdraw(trustAccounts, 200);
    Withdraw(trustAccounts, 300);
    Withdraw(trustAccounts, 100);
}
