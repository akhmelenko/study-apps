#include <iostream>
#include <vector>
#include <string>
#include "func.h"

using namespace std;

/*void Cycle(vector<string> msg)
{
    for (const string& word : msg)
    {
        cout << word << " " << endl;
    }
}*/

int main()
{
    //vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    int msg = 2;

    Cycle(msg);

    cout << "Hello" << endl;
}