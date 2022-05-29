#include <iostream>
#include <vector>
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "TrustAccount.h"
#include "Account_Util.h"
#include <memory>

using namespace std;


class Test
{
private:
    int data;
public:
    Test() : data{0} { cout << "Test constructor (" << data << ")" << endl;}
    Test(int data) : data{data} { cout << "Test constructor (" << data << ")" << endl;}
    int GetData() const { return data;}
    ~Test() { cout << "Test destructor (" << data << ")" << endl;}
};


int main()
{ 
    //Test t1 {1000};
    
    //Test* pT1 = new Test {1000};
    //delete pT1;
    
    /*std::unique_ptr<Test> pT1 {new Test{1000}};
    std::unique_ptr<Test> pT2 = make_unique<Test>(100);
    std::unique_ptr<Test> pT3;
    pT3 = std::move(pT1);
    if (!pT1)
        cout << "pT1 is nullptr" << endl;*/
        
    std::unique_ptr<Account> pA1 = make_unique<CheckingAccount>("Moe", 5000);
    cout << *pA1 << endl;
    pA1->Deposit(1000);
    cout << *pA1 << endl;
    
    std::vector<unique_ptr<Account>> accounts;
    
    accounts.push_back(make_unique<CheckingAccount>("James", 1000));
    accounts.push_back(make_unique<SavingsAccount>("Billy", 4000, 5.2));
    accounts.push_back(make_unique<TrustAccount>("Bobby", 5000, 4.5));
    
    for (const auto &acc: accounts)
        cout << *acc << endl;
}
