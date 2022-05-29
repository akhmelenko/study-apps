#include <iostream>
#include "Account.h"

using namespace std;

void DisplayActiveAccountsNumber()
{
    cout << "Nubmer of active accounts = " << Account::GetAccountsNumber() << endl; 
}

int main()
{
    DisplayActiveAccountsNumber();
    {
        Account person1;
        DisplayActiveAccountsNumber();
        Account person2{"Ben Gun", 108};
        DisplayActiveAccountsNumber();
    }
    DisplayActiveAccountsNumber();
    
    Account* pPerson3 = new Account;
    DisplayActiveAccountsNumber();
    delete pPerson3;
    DisplayActiveAccountsNumber();
    
	return 0;
}
