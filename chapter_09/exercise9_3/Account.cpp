#include <iostream>
#include "Account.h"

Account::Account()
{
    id = 0;
    balance = 0;
    annualInterestRate = 0;
}

void Account::setId(int newId)
{
    id = newId;
}

void Account::setBalance(double newBalance)
{
    balance = newBalance;
}

void Account::setAnnualInterestRate(double newRate)
{
    annualInterestRate = newRate;
}

int Account::getId()
{
    return id;
}

double Account::getBalance()
{
    return balance;
}

double Account::getAnnualInterestRate()
{
    return annualInterestRate;
}

double Account::getMonthlyInterestRate()
{
    return (annualInterestRate / 1200);
}

void Account::withdraw(double amount)
{
    if (balance > amount)
    {
        balance -= amount;
    }
}

void Account::deposit(double amount)
{
    balance += amount;
}
