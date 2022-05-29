#ifndef _ACCOUNT_UTIL_H_
#define _ACCOUNT_UTIL_H_

#include <vector>
#include "Account.h"


//Utility helper functions for Account class
void Display(const std::vector<Account*> &pAccounts);
void Deposit(std::vector<Account*> &pAccounts, double amount);
void Withdraw(std::vector<Account*> &pAccounts, double amount);

#endif // _ACCOUNT_UTIL_H_
