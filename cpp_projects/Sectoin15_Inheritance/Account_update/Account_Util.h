#ifndef _ACCOUNT_UTIL_H_
#define _ACCOUNT_UTIL_H_

#include <vector>
#include "Account.h"
#include "SavingsAccount.h"

//Utility helper functions for Account class
void Display(const std::vector<Account> &accounts);
void Deposit(std::vector<Account> &accounts, double amount);
void Withdraw(std::vector<Account> &accounts, double amount);

//Utility helper functions for SavingsAccount class
void Display(const std::vector<SavingsAccount> &accounts);
void Deposit(std::vector<SavingsAccount> &accounts, double amount);
void Withdraw(std::vector<SavingsAccount> &accounts, double amount);

#endif // _ACCOUNT_UTIL_H_
