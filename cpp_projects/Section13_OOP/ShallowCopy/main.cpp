#include <iostream>

using namespace std;

class Shallow
{
private:
    int* pData;
    
public:
    void SetDataValue(int data) { *pData = data;}
    int GetDataValue() { return *pData; }
    //constructor
    Shallow(int data);
    //copy constructor
    Shallow(const Shallow &src);
    //destructor
    ~Shallow();
};

    //constructor
Shallow::Shallow(int data)
    {
        pData = new int;
        *pData = data;
    }
    //copy constructor
Shallow::Shallow(const Shallow &src)
    {
        pData = src.pData;
    }
    //destructor
Shallow::~Shallow()
    {
        delete pData;
        cout << "Destructor freeing data" << endl;
    }

void DisplayShallow(Shallow s)
{
    cout << "Shallow ptr = " << s.GetDataValue() << endl;
}

int main()
{
	Shallow obj1 {100};
    DisplayShallow(obj1);
    
    Shallow obj2 {obj1};
    DisplayShallow(obj2);
	return 0;
}
