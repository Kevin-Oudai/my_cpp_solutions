/* Codex Task: Exercise 12.25 — New Account class with Transaction log */
#include "Transaction.h"

Transaction::Transaction(char type, double amount, double balance, const std::string& description)
    : type(type), amount(amount), balance(balance), description(description) {}

Date Transaction::getDate() const { return date; }
char Transaction::getType() const { return type; }
double Transaction::getAmount() const { return amount; }
double Transaction::getBalance() const { return balance; }
std::string Transaction::getDescription() const { return description; }
