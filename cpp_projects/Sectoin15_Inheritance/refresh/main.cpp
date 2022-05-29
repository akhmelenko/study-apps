#include <iostream>
#include "Account.h"
#include "SavingsAccount.h"
#include <string>

using namespace std;

int main()
{
	cout << "Account class" << endl;
    Account irmaAccount("Irma", 53.3);
    cout << " Irma balance = " << irmaAccount.balance << endl;
    cout << " Irma name = " << irmaAccount.name << endl;
    
    irmaAccount.balance = 3.5;
    irmaAccount.name = "IrmaNA";
//    Account danielAccount();
    cout << " Irma balance = " << irmaAccount.balance << endl;
    cout << " Irma name = " << irmaAccount.name << endl;
    
    cout << "------- ptr --------" << endl;
    
    Account* pDanielAcc = new Account("Daniel", 54);
    cout << "Daniel name = " << pDanielAcc->name << endl;
    cout << "Daniel balance = " << pDanielAcc->balance << endl;
    
    pDanielAcc->name = "DanielNa";
    pDanielAcc->balance = 78;
    
    cout << "Daniel name = " << pDanielAcc->name << endl;
    cout << "Daniel balance = " << pDanielAcc->balance << endl;
    
    delete pDanielAcc;
    
    cout << "------- savings --------" << endl;
    
    SavingsAccount nikaAcc("Nika", 80);
    cout << "Nika name = " << nikaAcc.name << endl;
    cout << "Nika balance = " << nikaAcc.balance << endl;
    cout << "Nika rate = " << nikaAcc.GetRate() << endl;
    
    nikaAcc.name = "NikaNa";
    nikaAcc.balance = 34;
    nikaAcc.SetRate(3);
    
    cout << "Nika name = " << nikaAcc.name << endl;
    cout << "Nika balance = " << nikaAcc.balance << endl;
    cout << "Nika rate = " << nikaAcc.GetRate() << endl;
    
    cout << "------- ptr --------" << endl;
    
    SavingsAccount* pVital = new SavingsAccount("Vital", 54);
    cout << "Vital name =" << pVital->name << endl;
    cout << "Vital balance" << pVital->balance << endl;
    
    pVital->name = "VitalNa";
    pVital->balance = 4534;
    pVital->SetRate(4);
    
    cout << "Vital name = " << pVital->name << endl;
    cout << "Vital balance" << pVital->balance << endl;
    cout << "Vital rate = " << pVital->GetRate() << endl;
    
    delete pVital;
    
	return 0;
}
