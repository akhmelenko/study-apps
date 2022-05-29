#include <iostream>

using namespace std;

class Player
{
private:
    //attributes
    std::string name;
    int health;
    int xp;

public:    
    //methods
    void SetName(std::string newName)
    {
        name = newName;
    }
    //constructors overload
    Player()
    : Player{"None"} //deligate to 1-arg constructor
    {
        cout << "Constructor 0- args" << name << endl;
    };
    Player(std::string name_)
        : Player{name_, 100} //deligate to 2-arg constructor
    {        
        cout << "Constructor 1-arg init name = <" << name << "> and health = <" << health << "> and xp = <" << xp << ">" << endl;
    };
    Player(std::string name_, int health_)
        : Player{name_, health_, 0} //deligate to 3-arg constructor
    {        
        cout << "Constructor 2-arg init name = <" << name << "> and health = <" << health << "> and xp = <" << xp << ">" << endl;
    };
    Player(std::string name_, int health_, int xp_)
        : name{name_}, health{health_}, xp{xp_}
    {        
        cout << "Constructor 3-arg init name = <" << name << "> and health = <" << health << "> and xp = <" << xp << ">" << endl;
    };
    //destructor
    ~Player()
    {
        cout << "Destructor called for " << name << endl;
    };
};

int main()
{

    Player empty;
    empty.SetName("Empty");
    Player nameOnly("NameOnly");
    nameOnly.SetName("health");
    Player nameAndHealth{"NameAndHealth", 88};        

	
	return 0;
}
