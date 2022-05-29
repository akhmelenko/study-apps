#include <iostream>
#include <vector>
#include <string>

using namespace std;


void Display(vector<string>* pVector)
{
    for (auto str: *pVector)
        cout << str << endl; 
}

int main()
{
    vector<string> strVector {"Wite", "Blue", "Red"};
    
    Display(&strVector);
	return 0;
}
