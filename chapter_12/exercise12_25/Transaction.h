/* Codex Task: Exercise 12.25 — New Account class with Transaction log */
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include "Date.h"

class Transaction {
public:
    Transaction(char type, double amount, double balance, const std::string& description);
    Date getDate() const;
    char getType() const;
    double getAmount() const;
    double getBalance() const;
    std::string getDescription() const;
private:
    Date date;
    char type;
    double amount;
    double balance;
    std::string description;
};

#endif
