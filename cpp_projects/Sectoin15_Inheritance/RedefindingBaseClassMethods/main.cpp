#include <iostream>
#include "Account.h"
#include "SavingsAccount.h"

using namespace std;

int main()
{	
    
    cout << "=============== Account ================" << endl;
    
    Account a1 {1000};
    a1.Deposit(500);
    cout << a1 << endl;
    
    a1.Withdraw(100);
    cout << a1 << endl;
    
    a1.Withdraw(1500);
    cout << a1 << endl;
    
    cout << "=============== Savings Account ================" << endl;
    
    SavingsAccount s1 {2000, 5};
    s1.Deposit(500);
    cout << s1 << endl;
    
    s1.Deposit(100);
    cout << s1 << endl;
    
    s1.Withdraw(2700);
    cout << s1 << endl;
}
