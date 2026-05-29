#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account
{
public:
    SavingsAccount();
    SavingsAccount(int id, double balance, double annualInterestRate);

    virtual void withdraw(double amount);
    virtual std::string toString() const;
};

#endif
