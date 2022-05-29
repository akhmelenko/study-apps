#include <iostream>

using namespace std;

class Deep
{
private:
    int* pData;
    
public:
    void SetDataValue(int data) { *pData = data;}
    int GetDataValue() { return *pData; }
    //constructor
    Deep(int data);
    //copy constructor
    Deep(const Deep &src);
    //destructor
    ~Deep();
};

    //constructor
Deep::Deep(int data)
    {
        pData = new int;
        *pData = data;
        cout << "Deep constructor" << endl;
    }
    //copy constructor
Deep::Deep(const Deep &src)
        :Deep{*src.pData}
    {
        cout << "Deep copy constructor" << endl;
    }
    //destructor
Deep::~Deep()
    {
        delete pData;
        cout << "Destructor freeing data" << endl;
    }

void ViewDeep(Deep s)
{
    cout << "Deep ptr = " << s.GetDataValue() << endl;
}

int main()
{
	Deep obj1 {100};
    ViewDeep(obj1);
    
    Deep obj2 {obj1};
    ViewDeep(obj2);
    obj2.SetDataValue(1000);
    ViewDeep(obj2);
    
	return 0;
}
