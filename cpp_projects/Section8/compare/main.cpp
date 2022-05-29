#include <iostream>

using namespace std;

int main()
{          
    int cents {};
	cout << "Enter amount of cents" << endl;
    cin >> cents;
    cout << "You have " << cents << " cents" << endl;
    cout << "OR" << endl;
    
    int dollars {};
    int quaters {};
    int dimes {};
    int nickels {};
    int pennies {};
    
/*    dollars = cents / 100;
    cents%= 100;
    quaters = cents / 25;
    cents%= 25;
    dimes = cents / 10;
    cents%= 10;
    nickels = cents / 5;
    cents%= 5;
    pennies = cents;

    cout << "You have " << dollars << " dollars" << endl;
    cout << "You have " << quaters << " quaters" << endl;
    cout << "You have " << dimes << " dimes" << endl;
    cout << "You have " << nickels << " nickels" << endl;
    cout << "You have " << pennies << " pennies" << endl;*/

    cout << "You have " << cents / 100 << " dollars" << endl;
    cout << "You have " << (cents%100) / 25 << " quaters" << endl;
    cout << "You have " << ((cents%100) % 25) / 10 << " dimes" << endl;
    cout << "You have " << (((cents%100) % 25) % 10) / 5 << " nickels" << endl;
    cout << "You have " << ((((cents%100) % 25) % 10) % 5) << " pennies" << endl;

	return 0;
}
