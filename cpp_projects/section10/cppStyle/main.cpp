#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main()
{
    string s1 {"star "};
    string s2 {"sun"};
    string s3 = s2 + " is " + s1;
    s3 = s3 + "sun" + " is " + "star";
	cout << s3 << endl;
    
    cout << s1[0] << endl;
    cout << s1.at(0) << endl;
    
    s1.at(0) = 'q';
    cout << s1 << endl;
    
    for (auto c: s1)
        cout << c << endl;
        
    cout << "====================" << endl;
    
    for (int c: s1)
        cout << c << endl;
        
    cout << "====================" << endl;
    
    cout << s1.substr(3, 3) << endl;
        
    cout << "====================" << endl;
    
    cout << s3.find("star", 8) << endl;        
    cout << "====================" << endl;
            
    cout << s3.erase(3, 2) << endl;
    //s3.clear();
    cout << s3 << endl;
    
    cout << "s3 length = " << s3.length() << endl;
    cout << "====================" << endl;
    
    s3 += " in space";
    cout << s3 << endl;
    cout << "s3 length = " << s3.length() << endl;
    
    
    /*cout << "====================" << endl;
    cout << "Enter string" << endl;
    string s4 {};
    getline(cin, s4);
    cout << "Your string is " << s4 << endl;
    
    cout << "====================" << endl;
    cout << "Enter string with 'x'" << endl;
    getline(cin, s4, 'x');
    cout << "Your string is " << s4 << endl;*/
    
    cout << "====================" << endl;
    cout << "enter word to search inside... " << s3 << endl;
    string searchWord {};
    getline(cin, searchWord);
    if (s3.find(searchWord) != string::npos)
        cout << "word =" << searchWord << "= is on the " << s3.find(searchWord) << " position" << endl;    
    else
        cout << "word =" << searchWord << "= is not in string" << endl;
    
	return 0;
}
