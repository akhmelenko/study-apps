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
    std::string GetName(void)
    {
        return name;
    }
    int GetHealth(void)
    {
        return health;
    }
    int GetXp(void)
    {
        return xp;
    }
    //constructors overload
    /*Player()
    {
        name = "None";
        heakth = 100;
        cout << "Constructor with all default args" << name << endl;
    };*/
    Player(std::string name_ = "None", int health_ = 100, int xp = 0);
    //constructor copy
    Player(const Player &src);
    //destructor
    ~Player()
    {
        cout << "Destructor called for " << name << endl;
    };
};

    Player::Player(std::string name_, int health_, int xp_)
        :name{name_}, health{health_}, xp{xp_}
    {
        cout << "Constructor init name = " << name << " and health = " << health << endl;
    };
    
    Player::Player(const Player &src)
        //:name{src.name}, health{src.health}, xp{src.xp}
        :Player(src.name, src.health, src.xp)
    {
        cout << "Copy constructor  made copy of: " << src.name << endl;
    }
    
    void DisplayPlayer(Player p)
    {
        cout << "Name: " << p.GetName() << endl;
        cout << "Health: " << p.GetHealth() << endl;
        cout << "Xp: " << p.GetXp() << endl;
    }

int main()
{
    Player empty{"XXXX", 100, 50};
    Player newObject{empty};
    
    DisplayPlayer(empty);

    Player nameOnly("NameOnly");
    Player nameAndHealth{"NameAndHealth", 88};        

	
	return 0;
}
