#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
public:
    Account();
    void setId(int newId);
    void setBalance(double newBalance);
    void setAnnualInterestRate(double newRate);
    int getId();
    double getBalance();
    double getAnnualInterestRate();
    double getMonthlyInterestRate();
    void withdraw(double amount);
    void deposit(double amount);

private:
    int id;
    double balance;
    double annualInterestRate;
};
#endif