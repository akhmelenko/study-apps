#include <iostream>
#include <iomanip>

using namespace std;

int main()
{        
	cout << "noboolalpha - default (10 == 10): " << (10 == 10) << endl;
    cout << "noboolalpha - default (10 == 20): " << (10 == 20) << endl;
    
    //Set true/false formating
    cout << boolalpha;
    cout << "boolalpha - default (10 == 10): " << (10 == 10) << endl;
    cout << "boolalpha - default (10 == 20): " << (10 == 20) << endl;
	
    //Toggle 0/1 formating
    cout << noboolalpha;
    cout << "boolalpha - default (10 == 10): " << (10 == 10) << endl;
    cout << "boolalpha - default (10 == 20): " << (10 == 20) << endl;
    
    //Set true/false using method formating
    cout.setf(ios::boolalpha);
    cout << "boolalpha - default (10 == 10): " << (10 == 10) << endl;
    cout << "boolalpha - default (10 == 20): " << (10 == 20) << endl;
    
    //Reset cout flags using method
    cout << resetiosflags(ios::boolalpha);
    cout << "boolalpha - default (10 == 10): " << (10 == 10) << endl;
    cout << "boolalpha - default (10 == 20): " << (10 == 20) << endl;
    return 0;
}
