#include <iostream>
#include "Account.h"

int main()
{
    Account act;
    act.setId(1122);
    act.setBalance(20000);
    act.setAnnualInterestRate(4.5);
    act.withdraw(2500);
    act.deposit(3000);
    std::cout << "Balance: $" << act.getBalance() << std::endl;
    std::cout << "Monthly Interest Rate: " << act.getMonthlyInterestRate() << std::endl;
    return 0;
}