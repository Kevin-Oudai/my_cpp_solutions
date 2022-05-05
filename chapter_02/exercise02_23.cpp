#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
    double investmentAmount, annualInterestRate, numberOfYears, accumulatedValue;
    std::cout << "Enter investment amount: ";
    std::cin >> investmentAmount;
    std::cout << "Enter annual interest rate in percentage: ";
    std::cin >> annualInterestRate;
    std::cout << "Enter number of years: ";
    std::cin >> numberOfYears;

    accumulatedValue = investmentAmount * pow((1 + (annualInterestRate / 1200)), numberOfYears * 12);

    std::cout << std::setprecision(2) << std::showpoint << std::fixed;
    std::cout << "Accumulated value is $" << accumulatedValue << std::endl;
    return 0;
}