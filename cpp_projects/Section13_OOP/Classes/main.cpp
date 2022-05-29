#include <iostream>
#include <vector>

using namespace std;


class Player
{
public:
    //attributes
    std::string name {"PlayerName"};
    int health {100};
    
    //methods
    void Talk(std::string textToSay) {cout << name << " says: " << textToSay << endl;};
    bool IsDead();
};

class Account
{
private:
    //attributes
    std::string name {"AccountName"};
    double balance {0.0};
    
public:    
    //methods
    bool Deposit(double money) 
    {
        balance += money; 
        return true;
    };
    bool Withdraw(double money) 
    {        
        if (balance-money >= 0)
            balance -= money;
            return true;
        else
        {
            return false;            
        }
    };
    //outside definition
    double GetBalance();
};

double Account::GetBalance()
{
    return balance;
}

int main()
{
    Account frankAcc;
    Account jimAcc;
    
    Player frank;
    Player hero;
    
    frank.name = "Frank";
    frank.Talk("I am ok");
    
    
    Player players[] {frank, hero};
    
    vector<Player> playersVector {frank};
    playersVector.push_back(hero);
    
    Player* pEnemyPlayer {nullptr};
    pEnemyPlayer = new Player();
    
    pEnemyPlayer->name = "Enemy";
    pEnemyPlayer->health = 50;
    pEnemyPlayer->Talk("I will destroy you");
    
    
    delete pEnemyPlayer;
    
    //cout << "Frank init balance = " << frankAcc.balance << endl;
    frankAcc.Deposit(50);
    //cout << "Frank after deposit 50 balance = " << frankAcc.balance << endl;
    frankAcc.Withdraw(60);
    //cout << "Frank after withdraw 60 balance = " << frankAcc.balance << endl;
    
    
    cout << "Account::GetBalance() = " << frankAcc.GetBalance() << endl;
    
	return 0;
}
