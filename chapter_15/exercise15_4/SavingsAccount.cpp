#include "SavingsAccount.h"
#include <sstream>

SavingsAccount::SavingsAccount()
{
}

SavingsAccount::SavingsAccount(int id, double balance, double annualInterestRate)
    : Account(id, balance, annualInterestRate)
{
}

void SavingsAccount::withdraw(double amount)
{
    if (getBalance() >= amount)
    {
        Account::withdraw(amount);
    }
}

std::string SavingsAccount::toString() const
{
    std::ostringstream output;
    output << "Savings account " << getId()
           << " balance: " << getBalance()
           << ", date created: " << getDateCreated();
    return output.str();
}
