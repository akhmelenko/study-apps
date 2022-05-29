#include <iostream>

using namespace std;

class Player
{
public:
    //attributes
    std::string name {"PlayerName"};
    int health {100};
    
    //methods
    void SetName(std::string newName)
    {
        name = newName;
    }
    //constructors overload
    Player()
    {
        cout << "No args constructor" << endl;
    };
    Player(int health_)
    {
        health = health_;
        cout << "Constructor init health = " << health << endl;
    };
    Player(std::string name_, int health_)
    {
        name = name_;
        health = health_;
        cout << "Constructor init name = " << name << " and health = " << health << endl;
    };
    //destructor
    ~Player()
    {
        cout << "Destructor called for " << name << endl;
    };
};

int main()
{
    {
        Player empty;
        empty.SetName("Empty");
    }
    
    {
        Player health(100);
        health.SetName("health");
        Player nameAndHealth("nameAndHealth", 88);        
    }
    
    Player* pEnemy = new Player();
    pEnemy->SetName("Enemy");
    Player* pBoss = new Player("Boss", 300);
    pBoss->SetName("Level Boss");
    
    delete pEnemy;
    delete pBoss;
	
	return 0;
}
