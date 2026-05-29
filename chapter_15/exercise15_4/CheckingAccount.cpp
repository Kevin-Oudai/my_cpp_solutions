#include "CheckingAccount.h"
#include <sstream>

CheckingAccount::CheckingAccount()
{
    overdraftLimit = 0;
}

CheckingAccount::CheckingAccount(int id, double balance, double annualInterestRate, double overdraftLimit)
    : Account(id, balance, annualInterestRate)
{
    this->overdraftLimit = overdraftLimit;
}

double CheckingAccount::getOverdraftLimit() const
{
    return overdraftLimit;
}

void CheckingAccount::setOverdraftLimit(double overdraftLimit)
{
    this->overdraftLimit = overdraftLimit;
}

void CheckingAccount::withdraw(double amount)
{
    if (getBalance() + overdraftLimit >= amount)
    {
        setBalance(getBalance() - amount);
    }
}

std::string CheckingAccount::toString() const
{
    std::ostringstream output;
    output << "Checking account " << getId()
           << " balance: " << getBalance()
           << ", overdraft limit: " << overdraftLimit
           << ", date created: " << getDateCreated();
    return output.str();
}
