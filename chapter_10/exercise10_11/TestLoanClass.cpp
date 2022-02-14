// Listing 9.14 - TestLoanClass.cpp

#include <iostream>
#include <iomanip>
#include "Loan.h"

int main()
{
    // Enter annual interest rate
    std::cout << "Enter yearly interest rate, for example 8.25: ";
    double annualInterestRate;
    std::cin >> annualInterestRate;

    // Enter number of years
    std::cout << "Enter number of years as an integer, for example 5; ";
    int numberOfYears;
    std::cin >> numberOfYears;

    // Enter loan amount
    std::cout << "Enter loan amount, for example 120000.95: ";
    double loanAmount;
    std::cin >> loanAmount;

    // Create Loan object
    Loan loan(annualInterestRate, numberOfYears, loanAmount);

    // Display results
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "The monthly payment is " << loan.getMonthlyPayment() << std::endl;
    std::cout << "The total payment is " << loan.getTotalPayment() << std::endl;

    std::cout << "The monthly payment is " << loan.getMonthlyPayment(8.25, 5, 120000.95) << std::endl;
    std::cout << "The monthly payment is " << loan.getTotalPayment(8.25, 5, 120000.95);

    return 0;
}