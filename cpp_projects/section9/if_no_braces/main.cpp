#include <iostream>

using namespace std;

int main()
{
    bool a {true};
    bool b {true};
    if (b)
        if (a)
            cout << "true1" << endl;
        //cout << "true2" << endl;        
    else
        cout << "false1" << endl;
        cout << "false2" << endl; 
	
    return 0;
}
