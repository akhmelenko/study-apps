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

void Func(std::shared_ptr<Test> ptr)
{
    std::cout << "Use count = " << ptr.use_count() << std::endl;
}


int main()
{ 
    cout << "================ 1 =====================" << endl;
    std::shared_ptr<int> p1 {new int (100)};
    cout << "Use count p1 = " << p1.use_count() << endl;
    
    std::shared_ptr<int> p2 {p1};
    cout << "Use count p2 = " << p2.use_count() << endl;
    
    p1.reset();
    cout << "Use count p1 = " << p1.use_count() << endl;
    cout << "Use count p2 = " << p2.use_count() << endl;
    
    cout << "================== 2 =======================" << endl;
    
    std::shared_ptr<Test> pT = make_shared<Test>(100);
    Func(pT);
    std::cout << "Use count for pT: " << pT.use_count() << endl;
    {
        std::shared_ptr<Test> pT1 = {pT};
        std::cout << "Use count for pT: " << pT.use_count() << endl;
        {
            std::shared_ptr<Test> pT2 = {pT1};
            std::cout << "Use count for pT: " << pT.use_count() << endl;
            pT.reset();
        }
        std::cout << "Use count for pT: " << pT.use_count() << endl;
    }
    std::cout << "Use count for pT: " << pT.use_count() << endl;
     
     
     cout << "\n================= 3 ===================" << endl;
     
     std::shared_ptr<Account> p1 = std::make_shared<CheckingAccount>("Moe", 5000);
     std::shared_ptr<Account> p2 = std::make_shared<SavingsAccount>("Larry", 6000, 5);
     std::shared_ptr<Account> p3 = std::make_shared<TrustAccount>("Curly", 10000, 2.5);
     
     std::vector<shared_ptr<Account>> accounts; //{p1, p2, p3};
     
     accounts.push_back(p1);
     accounts.push_back(p2);
     accounts.push_back(p3);
     
     for (const auto &acc: accounts)
     {
         cout << *acc << endl;
         cout << "Use count" << acc.use_count() << endl;         
     }
}
