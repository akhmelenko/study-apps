#include <iostream>
#include "Account.h"

using namespace std;


void FriendDisplayAccount(Account &a)
{
    cout << "Account name = " << a.name << endl;
    cout << "Account balance = " << a.balance << endl;
}

int main()
{
    Account person1;
    Account person2{"Ben Gun", 108};
    FriendDisplayAccount(person2);

    
	return 0;
}
