#include <iostream>
#include <vector>

using namespace std;

class Move
{
private:
    int* pData;
    
public:
    void SetDataValue(int data) { *pData = data;}
    int GetDataValue() { return *pData; }
    //constructor
    Move(int data);
    //copy constructor
    Move(const Move &src);
    //move constructor
    Move(Move &&src) noexcept;
    //destructor
    ~Move();
};

    //constructor
Move::Move(int data)
    {
        pData = new int;
        *pData = data;
        cout << "Raw constructor for value = " << *pData << endl;
    }
    //copy constructor
Move::Move(const Move &src)
        :Move{*src.pData}
    {
        cout << "Copy constructor DEEP COPY for value = " << *src.pData << endl;
    }
    //move constructor
Move::Move(Move &&src) noexcept
        :pData{src.pData} //('STEAL' DATA and NULL SOURCE POINTER)
    {        
        cout << "Move constructor for value = " << *pData << endl;
        src.pData = nullptr;
    }
    //destructor
Move::~Move()
    {
        if (pData == nullptr)
        {
            cout << "Destructor freeing memory for nullptr " << endl;
        }        
        else
        {        
            cout << "Destructor freeing memory for value = " << *pData << endl;
        }
        delete pData; 
    }

void ViewMove(Move s)
{
    cout << "View Move class *ptr = " << s.GetDataValue() << endl;
}

int main()
{
    vector<Move> moveVector;
    cout << "========after moveVector created: moveVector size = " << moveVector.size() << ", moveVector capasity = " << moveVector.capacity() << endl;
	moveVector.push_back(Move{10});
    cout << "========after moveVector push_back "<< moveVector.back().GetDataValue() <<": moveVector size = " << moveVector.size() << ", moveVector capasity = " << moveVector.capacity() << endl;   

    moveVector.push_back(Move{20});
    cout << "========after moveVector push_back "<< moveVector.back().GetDataValue() <<": moveVector size = " << moveVector.size() << ", moveVector capasity = " << moveVector.capacity() << endl;    
    
    moveVector.push_back(Move{30});
    cout << "========after moveVector push_back "<< moveVector.back().GetDataValue() <<": moveVector size = " << moveVector.size() << ", moveVector capasity = " << moveVector.capacity() << endl;    
    
    moveVector.push_back(Move{40});
    cout << "========after moveVector push_back "<< moveVector.back().GetDataValue() <<": moveVector size = " << moveVector.size() << ", moveVector capasity = " << moveVector.capacity() << endl;    
    
    moveVector.push_back(Move{50});
    cout << "========after moveVector push_back "<< moveVector.back().GetDataValue() <<": moveVector size = " << moveVector.size() << ", moveVector capasity = " << moveVector.capacity() << endl;    
    
	return 0;
}
