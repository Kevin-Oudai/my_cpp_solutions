#include <iostream>
#include <iomanip>

int main()
{
    double interest, balance, annualInterestRate;
    std::cout << "Enter balance and interest rate (e.g., 3 for 3%): ";
    std::cin >> balance >> annualInterestRate;

    interest = balance * (annualInterestRate / 1200);

    std::cout << std::setprecision(2) << std::showpoint << std::fixed;
    std::cout << "The interest is $" << interest << std::endl;
    return 0;
}