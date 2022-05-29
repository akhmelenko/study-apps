#include "SavingsAccount.h"
#include <iostream>

using namespace std;

SavingsAccount::SavingsAccount()
    :interestRate{3.0}
{
}

SavingsAccount::~SavingsAccount()
{
}

double SavingsAccount::GetInterestRate()
{
    return this->interestRate;
}
