/* Codex Task: Exercise 12.25 — New Account class with Transaction log */
#include <iostream>
#include "Account.h"

int main() {
    Account::setAnnualInterestRate(1.5);
    Account account("George", 1122, 1000.0);

    account.deposit(30);
    account.deposit(40);
    account.deposit(50);

    account.withdraw(5);
    account.withdraw(4);
    account.withdraw(2);

    std::cout << "Name: " << account.getName() << std::endl;
    std::cout << "Annual interest rate: " << Account::getAnnualInterestRate() << std::endl;
    std::cout << "Balance: " << account.getBalance() << std::endl;

    for (const auto& t : account.getTransactions()) {
        std::cout << t.getDate().toString() << ' ' << t.getType() << ' '
                  << t.getAmount() << ' ' << t.getBalance() << ' '
                  << t.getDescription() << std::endl;
    }
    return 0;
}
