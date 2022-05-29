#include <iostream>
#include "Account.h"
#include "SavingsAccount.h"

using namespace std;

int main()
{
    cout << "========== Account =============" << endl;
	Account acc;
    acc.name = "Bill";
    acc.Deposit(3000);
    acc.Withdraw(700);
    cout << acc.name << " " << acc.GetBalance() << endl;
    cout << endl;
    
    Account* pAcc {nullptr};
    pAcc = new Account();
    pAcc->name = "Lars";
    pAcc->Deposit(2000);
    pAcc->Withdraw(500);
    cout << pAcc->name << " " << pAcc->GetBalance() << endl;
    delete pAcc;
    cout << endl;
    
    cout << "========== Savings Account =============" << endl;
	SavingsAccount savingsAcc;
    savingsAcc.name = "Sanny";
    savingsAcc.Deposit(4000);
    savingsAcc.Withdraw(800);
    cout << savingsAcc.name << " " << savingsAcc.GetBalance() << " interest rate = " << savingsAcc.GetInterestRate() << endl;
    cout << endl;
    
    SavingsAccount* pSavingsAccount {nullptr};
    pSavingsAccount = new SavingsAccount();
    pSavingsAccount->name = "Irma";
    pSavingsAccount->Deposit(1000);
    pSavingsAccount->Withdraw(200);
    delete pSavingsAccount;
    cout << pSavingsAccount->name << " " << pSavingsAccount->GetBalance() << " interest rate = " << pSavingsAccount->GetInterestRate() << endl;
    cout << endl;
    
	return 0;
}
