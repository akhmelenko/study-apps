#include <iostream>
#include "Account.h"

using namespace std;

int main()
{
    Account person;
    
	cout << "Initial balance: " << person.GetBalance() << endl;
    person.SetBalance(150);
    cout << "After set balance: " << person.GetBalance() << endl;
   
	return 0;
}
