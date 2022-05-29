#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

using namespace std;

class Account
{
public:
    double balance;
//    int id;
    string name;
//    Account(): id{0},balance{0}, name{"Empty account"} {};
//    Account(string name): id{0}, balance{0}, name{name} {};
    Account(string name, double balance): balance{balance}, name{name} {};
//    double GetBalance()
//    {
//        return balance;
//    }
//    void Deposit(double amount)
//    {
//        balance = balance + amount;
//    }
//    void Withdrow(double amount)
//    {
//        if (balance - amount >= 0)
//        {
//            balance = balance - amount;
//        }
//        else
//        {
//            cout << "Error in withdrowals - balance not enough!" << endl;
//        }
//    }
};

#endif // ACCOUNT_H
