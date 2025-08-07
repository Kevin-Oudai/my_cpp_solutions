// Exercise 5.32 - Financial Application: Compound Value

#include <iostream>
#include <iomanip>

int main()
{
    std::cout << "Enter an amount: ";
    double amount, compoundValue = 0;
    std::cin >> amount;

    std::cout << "Enter annual interest rate: ";
    double annualRate, monthlyRate;
    std::cin >> annualRate;
    annualRate /= 100.0;
    monthlyRate = annualRate / 12.0;

    std::cout << "Enter the number of months: ";
    int numberOfMonths;
    std::cin >> numberOfMonths;

    for (int i = 0; i < numberOfMonths; i++)
    {
        compoundValue = (amount + compoundValue) * (1 + monthlyRate);
    }
    std::cout << "The compound value is: $"
              << std::setprecision(2) << std::fixed << std::showpoint << compoundValue << std::endl;

    return 0;
}