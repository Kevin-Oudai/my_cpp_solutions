#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account
{
public:
    Account();
    Account(int id, double balance, double annualInterestRate);
    virtual ~Account();

    void setId(int id);
    void setBalance(double balance);
    void setAnnualInterestRate(double annualInterestRate);

    int getId() const;
    double getBalance() const;
    double getAnnualInterestRate() const;
    double getMonthlyInterestRate() const;
    std::string getDateCreated() const;

    virtual void withdraw(double amount);
    void deposit(double amount);
    virtual std::string toString() const;

private:
    int id;
    double balance;
    double annualInterestRate;
    std::string dateCreated;

    static std::string createDateString();
};

#endif
