#include <iostream>
#include <vector>

using namespace std;

int main()
{
    
    int num {100};
    int num2 {50};
    int &ref = num;
    
    cout << "init============================" << endl;
    cout << "num = " << num << endl;
    cout << "ref = " << ref << endl;
    
    cout << "change num============================" << endl;
    num = 200;
    cout << "num = " << num << endl;
    cout << "ref = " << ref << endl;
    
    cout << "change ref============================" << endl;
    ref = 300;
    cout << "num = " << num << endl;
    cout << "ref = " << ref << endl;
    
    /*cout << "ref <= num2 ============================" << endl;
    &ref = num2; //COMPILER ERROR - REFERENCE CAN INIT ONLY ONCE!!!
    cout << "num = " << num << endl;
    cout << "num2 = " << num << endl;
    cout << "ref = " << ref << endl;*/
    
    
    vector<string> strVec {"LArry", "Moe", "Curly"};
    
    cout << "copy============================" << endl;
    
    for (auto str: strVec)
        str = "Changed"; // NOT CHANGING VECTOR ELEMENTS
        //BECAUSE str IS COPY
        
    for (auto str: strVec)    
        cout << str << endl;
        
    cout << "reference============================" << endl;
    
    for (auto &str: strVec)
        str = "Changed";
    
    //Better to use reference in range-based for loops
    for (auto const &str: strVec) // avoids not to change elements but save memory as in COPY (without &)
        cout << str << endl;        
    
	return 0;
}
