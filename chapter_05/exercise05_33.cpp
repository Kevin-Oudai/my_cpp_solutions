// Exercise 5.33 - Financial Application: Compute CD value
// A CD is a Certificate of Deposit

// Exercise 5.32 - Financial Application: Compound Value

#include <iostream>
#include <iomanip>

int main()
{
    std::cout << "Enter the initial deposit amount: ";
    double amount, compoundValue = 0;
    std::cin >> amount;

    std::cout << "Enter annual percentage yield: ";
    double annualRate, monthlyRate;
    std::cin >> annualRate;
    annualRate /= 100.0;
    monthlyRate = annualRate / 12.0;

    std::cout << "Enter maturity period (number of months): ";
    int numberOfMonths;
    std::cin >> numberOfMonths;

    std::cout << "\nMonth   CD Value" << std::endl;
    for (int i = 1; i <= numberOfMonths; i++)
    {
        amount = amount + amount * monthlyRate;
        std::cout << std::setw(8) << std::left << i
                  << std::setprecision(2) << std::fixed << std::showpoint << amount << std::endl;
    }

    return 0;
}