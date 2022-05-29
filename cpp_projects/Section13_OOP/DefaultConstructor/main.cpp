#include <iostream>

using namespace std;

class Player
{
private:
    //attributes
    std::string name;
    int health;

public:    
    //methods
    void SetName(std::string newName)
    {
        name = newName;
    }
    //constructors overload
    /*Player()
    {
        name = "None";
        heakth = 100;
        cout << "Constructor with all default args" << name << endl;
    };*/
    Player(std::string name_ = "None", int health_ = 100);
    //destructor
    ~Player()
    {
        cout << "Destructor called for " << name << endl;
    };
};

    Player::Player(std::string name_, int health_)
        : name{name_}, health{health_}
    {
        cout << "Constructor init name = " << name << " and health = " << health << endl;
    };

int main()
{
    {
        Player empty;
        empty.SetName("Empty");
    }
    
    {
        Player nameOnly("NameOnly");
        nameOnly.SetName("health");
        Player nameAndHealth{"NameAndHealth", 88};        
    }    
	
	return 0;
}
