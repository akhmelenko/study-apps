#include <iostream>
#include <vector>

using namespace std;

class Const
{
private:
    int* pData;
    
public:
    void SetDataValue(int data) { *this->pData = data;}
    int GetDataValue() const { return *this->pData; } // const !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //constructor
    Const(int data);
    //copy constructor
    Const(const Const &src);
    //move constructor
    Const(Const &&src) noexcept;
    //destructor
    ~Const();
};

    //constructor
Const::Const(int data)
    {
        this->pData = new int;
        *this->pData = data;
        cout << "Raw constructor for value = " << *this->pData << endl;
    }
    //copy constructor
Const::Const(const Const &src)
        :Const{*src.pData}
    {
        cout << "Copy constructor DEEP COPY for value = " << *src.pData << endl;
    }
    //move constructor
Const::Const(Const &&src) noexcept
        :pData{src.pData} //('STEAL' DATA and NULL SOURCE POINTER)
    {        
        cout << "Move constructor for value = " << *this->pData << endl;
        src.pData = nullptr;
    }
    //destructor
Const::~Const()
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

void ViewConst(const Const &s) // const !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
    cout << "View Move class *ptr = " << s.GetDataValue() << endl;
}

int main()
{
    const Const obj{55};
    Const obj2{80};
    
    
    ViewConst(obj);
    
	return 0;
}
