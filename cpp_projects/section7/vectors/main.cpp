#include <iostream>
#include <vector>

using namespace std;

int main()
{
    
    vector <char> vovels {'a', 'e', 'i', 'o', 'u'};
    
	cout << "vovel 1 = "<< vovels[1] << endl;
    cout << "vovel 3 = "<< vovels.at(4) << endl;
    cout << "vovel size = "<< vovels.size() << endl;
    
    vovels.push_back('q');
    cout << "vovel size = "<< vovels.size() << endl;
    for (unsigned int i = 0; i < vovels.size(); i++)
    {
        cout << "vovels["<< i <<"] = "<< vovels.at(i) << endl;
    }        
    cout << "================================================"<< endl;
    
    
    vovels.erase(vovels.begin() + 1, vovels.begin() + 4);
    cout << "vovel size = "<< vovels.size() << endl;
    for (unsigned int i = 0; i < vovels.size(); i++)
    {
        cout << "vovels["<< i <<"] = "<< vovels.at(i) << endl;
    }        
    cout << "================================================"<< endl;
    
    vector <vector <int>> intVector 
    {
        {1, 2, 3, 4, 5, 6},
        {1, 2, 4, 4},
        {1, 3, 4}
    };
    
    cout << "intVector size = "<< intVector.size() << endl;
    for (unsigned int i = 0; i < intVector.size(); i++)
    {
        cout << "intVector[" << i << "] size = "<< intVector.at(i).size() << endl;
        for (unsigned int j = 0; j < intVector.at(i).size(); j++)
        {
            cout << "intVector["<< i <<"]["<< j <<"] = "<< intVector.at(i).at(j) << endl;
        }
    }    
    
    
    cout << "================================================"<< endl;
    
    vector <int> vector1;
    vector <int> vector2;
    
    vector1.push_back(10);
    vector1.push_back(20);
    
    cout << "vector1 size = "<< vector1.size() << endl;
    for (unsigned int i = 0; i < vector1.size(); i++)
    {
        cout << "vector1["<< i <<"] = "<< vector1.at(i) << endl;
    } 
    
    vector2.push_back(100);
    vector2.push_back(200);
    
    cout << "vector2 size = "<< vector2.size() << endl;
    for (unsigned int i = 0; i < vector2.size(); i++)
    {
        cout << "vector2["<< i <<"] = "<< vector2.at(i) << endl;
    } 
    
    vector <vector <int>> vector2D;
    
    vector2D.push_back(vector1);
    vector2D.push_back(vector2);
    
    cout << "vector2D size = "<< vector2D.size() << endl;
    for (unsigned int i = 0; i < vector2D.size(); i++)
    {
        cout << "vector2D[" << i << "] size = "<< vector2D.at(i).size() << endl;
        for (unsigned int j = 0; j < vector2D.at(i).size(); j++)
        {
            cout << "vector2D["<< i <<"]["<< j <<"] = "<< vector2D.at(i).at(j) << endl;
        }
    }
    
    vector1.at(0) = 1000;
    
    cout << "vector2D size = "<< vector2D.size() << endl;
    for (unsigned int i = 0; i < vector2D.size(); i++)
    {
        cout << "vector2D[" << i << "] size = "<< vector2D.at(i).size() << endl;
        for (unsigned int j = 0; j < vector2D.at(i).size(); j++)
        {
            cout << "vector2D["<< i <<"]["<< j <<"] = "<< vector2D.at(i).at(j) << endl;
        }
    }
    
    cout << "vector1 size = "<< vector1.size() << endl;
    for (unsigned int i = 0; i < vector1.size(); i++)
    {
        cout << "vector1["<< i <<"] = "<< vector1.at(i) << endl;
    } 
    
	return 0;
}
