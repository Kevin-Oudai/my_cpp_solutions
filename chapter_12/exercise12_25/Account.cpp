/* Codex Task: Exercise 12.25 — New Account class with Transaction log */
#include "Account.h"


double Account::annualInterestRate = 0.0;

Account::Account(const std::string& name, int id, double balance)
    : id(id), balance(balance), name(name) {}

void Account::setId(int id) { this->id = id; }
int Account::getId() const { return id; }

void Account::setBalance(double balance) { this->balance = balance; }
double Account::getBalance() const { return balance; }

void Account::setAnnualInterestRate(double rate) { annualInterestRate = rate; }
double Account::getAnnualInterestRate() { return annualInterestRate; }

double Account::getMonthlyInterestRate() const { return annualInterestRate / 12; }

void Account::setName(const std::string& name) { this->name = name; }
std::string Account::getName() const { return name; }

void Account::deposit(double amount) {
    balance += amount;
    transactions.emplace_back('D', amount, balance, "deposit");
}

void Account::withdraw(double amount) {
    balance -= amount;
    transactions.emplace_back('W', amount, balance, "withdraw");
}

const std::vector<Transaction>& Account::getTransactions() const {
    return transactions;
}
