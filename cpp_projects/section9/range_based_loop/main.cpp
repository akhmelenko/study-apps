#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int list[] {2, 5, 8, 25};
    
    for (int listElement : list)
        cout << listElement << endl;
        
    for (auto listElement : list)
        cout << listElement << endl;
	
    int size {0};
    double summ {0.0};
    for (auto temp : {22.7, 10.8, 12.9, 23.4})
    {
        cout << temp << endl;
        summ+= temp;
        size++;
    }
    cout << "average = "<< summ/size << endl;
    
    cout << endl;
    for (auto c: "Test text")
        if (c != 't')
            cout << c;
    cout << endl;
    
        
    for (auto c: "Test text")
        if (c == ' ')
            cout << "\t";
        else
            cout << c;
            
    cout << endl;
    
    
    
    vector<int> vec {1,3,5,15,16,17,18,19,20,21,25,26,27,30,50,55,56,58,100,200,300,400,500,600,700};
    //---- WRITE YOUR CODE BELOW THIS LINE----
    
    int count {};
    for (auto i: vec)
        if ((i % 3) == 0 || (i % 5) == 0)
        {
            count++;
            cout << i << endl;
        }
            
    
    cout << count << endl;
    
    return 0;
}
