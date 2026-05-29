#include "Account.h"
#include <sstream>
#include <ctime>

Account::Account()
{
    id = 0;
    balance = 0;
    annualInterestRate = 0;
    dateCreated = createDateString();
}

Account::Account(int id, double balance, double annualInterestRate)
{
    this->id = id;
    this->balance = balance;
    this->annualInterestRate = annualInterestRate;
    dateCreated = createDateString();
}

Account::~Account()
{
}

void Account::setId(int id)
{
    this->id = id;
}

void Account::setBalance(double balance)
{
    this->balance = balance;
}

void Account::setAnnualInterestRate(double annualInterestRate)
{
    this->annualInterestRate = annualInterestRate;
}

int Account::getId() const
{
    return id;
}

double Account::getBalance() const
{
    return balance;
}

double Account::getAnnualInterestRate() const
{
    return annualInterestRate;
}

double Account::getMonthlyInterestRate() const
{
    return annualInterestRate / 1200;
}

std::string Account::getDateCreated() const
{
    return dateCreated;
}

void Account::withdraw(double amount)
{
    if (balance >= amount)
    {
        balance -= amount;
    }
}

void Account::deposit(double amount)
{
    balance += amount;
}

std::string Account::toString() const
{
    std::ostringstream output;
    output << "Account " << id
           << " balance: " << balance
           << ", date created: " << dateCreated;
    return output.str();
}

std::string Account::createDateString()
{
    std::time_t currentTime = std::time(0);
    std::tm *now = std::localtime(&currentTime);

    std::ostringstream output;
    output << now->tm_mon + 1 << "/"
           << now->tm_mday << "/"
           << now->tm_year + 1900;
    return output.str();
}
