/* Codex Task: Exercise 12.25 — New Account class with Transaction log */
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>
#include "Transaction.h"

class Account {
public:
    Account(const std::string& name, int id, double balance);

    void setId(int id);
    int getId() const;

    void setBalance(double balance);
    double getBalance() const;

    static void setAnnualInterestRate(double rate);
    static double getAnnualInterestRate();

    double getMonthlyInterestRate() const;

    void setName(const std::string& name);
    std::string getName() const;

    void deposit(double amount);
    void withdraw(double amount);

    const std::vector<Transaction>& getTransactions() const;

private:
    int id;
    double balance;
    static double annualInterestRate;
    std::string name;
    std::vector<Transaction> transactions;
};

#endif
