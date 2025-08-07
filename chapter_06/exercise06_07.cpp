// Exercise 6.7 - Financial Application: Compute the future investment value

#include <iostream>
#include <cmath>
#include <iomanip>

double futureInvestmentValue(double investmentAmount, double monthlyInterestRate, int years)
{
    double accumulatedValue = investmentAmount * pow((1 + monthlyInterestRate), years * 12);
    return accumulatedValue;
}

int main()
{
    double investmentAmount, monthlyInterestRate, annualInterestRate, years;
    std::cout << "Enter investment amount: ";
    std::cin >> investmentAmount;
    std::cout << "Enter annual interest rate in percentage: ";
    std::cin >> annualInterestRate;
    monthlyInterestRate = annualInterestRate / 1200;
    std::cout << std::setw(8) << std::left << "Years"
              << std::setw(12) << "Future Value" << std::endl;
    for (int years = 1; years <= 30; years++)
    {
        std::cout << std::setw(8) << std::left << years
                  << std::setprecision(2) << std::fixed << std::showpoint
                  << std::setw(12) << futureInvestmentValue(investmentAmount, monthlyInterestRate, years) << std::endl;
    }

    return 0;
}