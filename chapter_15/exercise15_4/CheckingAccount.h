#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "Account.h"

class CheckingAccount : public Account
{
public:
    CheckingAccount();
    CheckingAccount(int id, double balance, double annualInterestRate, double overdraftLimit);

    double getOverdraftLimit() const;
    void setOverdraftLimit(double overdraftLimit);

    virtual void withdraw(double amount);
    virtual std::string toString() const;

private:
    double overdraftLimit;
};

#endif
