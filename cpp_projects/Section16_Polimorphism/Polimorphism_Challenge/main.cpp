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
    
    Account* pAcc1 = new SavingsAccount("Curly", 5000, 1.5);
    Account* pAcc2 = new CheckingAccount("Moe", 2000);
    Account* pAcc3 = new TrustAccount("Butch", 3000, 5);
    
    std::vector<Account*> pAccounts {};
    pAccounts.push_back(pAcc1);
    pAccounts.push_back(pAcc2);
    pAccounts.push_back(pAcc3);

    Display(pAccounts);
    Deposit(pAccounts, 1000);
    Withdraw(pAccounts, 500);

    for (auto ptr: pAccounts)
        delete ptr;
    
}
