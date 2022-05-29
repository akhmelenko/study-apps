#include <iostream>
#include <vector>
#include <string>

using namespace std;

void Cycle(vector<string> msg)
{
    for (const string& word : msg)
    {
        cout << word << " " << endl;
    }
}