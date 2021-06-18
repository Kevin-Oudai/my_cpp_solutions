// Listing 2.11 - ComputeLoan.cpp

#include <iostream>
#include <cmath>

int main()
{
    std::cout << "Enter yearly interest rate, for example 8.25: ";
    double annualInterestRate;
    std::cin >> annualInterestRate;

    double monthlyInterestRate = annualInterestRate / 1200;

    std::cout << "Enter number of years as an integer, for example 5: ";
    int numberOfYears;
    std::cin >> numberOfYears;

    std::cout << "Enter loan amount, for example 120000.95: ";
    double loanAmount;
    std::cin >> loanAmount;

    double monthlyPayment = loanAmount * monthlyInterestRate /
                            (1 - 1 / pow(1 + monthlyInterestRate, numberOfYears * 12));
    double totalPayment = monthlyPayment * numberOfYears * 12;
    monthlyPayment = static_cast<int>(monthlyPayment * 100) / 100.0;
    totalPayment = static_cast<int>(totalPayment * 100) / 100.0;

    std::cout << "The monthly payment is " << monthlyPayment
              << "\nThe total payment is " << totalPayment << std::endl;

    return 0;
}