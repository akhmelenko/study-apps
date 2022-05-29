#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main()
{
    char firstName[20] {};
    char lastName[20] {};
    char fullName[50] {};
    char temp[50] {};
    
	cout << "enter fullName = " << endl;
    cin.getline(fullName, sizeof(fullName));
	cout << "fullName is " << fullName << endl;
    
    cout << "==============================" << endl;
    
    for (unsigned int i {0}; i < strlen(fullName); ++i)
        {
            if (isalpha(fullName[i]))
            {
                fullName[i] = toupper(fullName[i]);
            }
        }
        cout << "fullName is " << fullName << endl;
    
    return 0;
}
