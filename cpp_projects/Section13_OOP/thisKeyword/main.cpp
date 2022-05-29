#include <iostream>
#include <vector>

using namespace std;

class This
{
private:
    int* pData;
    
public:
    void SetDataValue(int data) { *this->pData = data;}
    int GetDataValue() { return *this->pData; }
    //constructor
    This(int data);
    //copy constructor
    This(const This &src);
    //move constructor
    This(This &&src) noexcept;
    //destructor
    ~This();
};

    //constructor
This::This(int data)
    {
        this->pData = new int;
        *this->pData = data;
        cout << "Raw constructor for value = " << *this->pData << endl;
    }
    //copy constructor
This::This(const This &src)
        :This{*src.pData}
    {
        cout << "Copy constructor DEEP COPY for value = " << *src.pData << endl;
    }
    //move constructor
This::This(This &&src) noexcept
        :pData{src.pData} //('STEAL' DATA and NULL SOURCE POINTER)
    {        
        cout << "Move constructor for value = " << *this->pData << endl;
        src.pData = nullptr;
    }
    //destructor
This::~This()
    {
        if (this->pData == nullptr)
        {
            cout << "Destructor freeing memory for nullptr " << endl;
        }        
        else
        {        
            cout << "Destructor freeing memory for value = " << *this->pData << endl;
        }
        delete this->pData; 
    }

void ViewThis(This s)
{
    cout << "View Move class *ptr = " << s.GetDataValue() << endl;
}

int main()
{
    vector<This> vec;
	vec.push_back(This{10});
    ViewThis(vec.at(0));
    
	return 0;
}
