// Exercise 5.23 - Compare loans with various interest rates

#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
    std::cout << "Loan Amount: ";
    double loanAmount;
    std::cin >> loanAmount;

    std::cout << "Number of Years: ";
    int numberOfYears;
    std::cin >> numberOfYears;

    double annualInterestRate = 5.0;
    int count = 0;
    std::cout << std::setw(16) << std::left << "Interest Rate"
              << std::setw(18) << "Monthly Payment"
              << std::setw(13) << "Total Payment\n";
    while (count <= 24)
    {
        double monthlyInterestRate = annualInterestRate / 1200;

        double monthlyPayment = loanAmount * monthlyInterestRate /
                                (1 - 1 / pow(1 + monthlyInterestRate, numberOfYears * 12));
        double totalPayment = monthlyPayment * numberOfYears * 12;
        monthlyPayment = static_cast<int>(monthlyPayment * 100) / 100.0;
        totalPayment = static_cast<int>(totalPayment * 100) / 100.0;

        std::cout << std::left << std::setw(5) << std::setprecision(3) << std::fixed << std::showpoint
                  << annualInterestRate << std::setw(11) << "%"
                  << std::setw(18) << std::setprecision(2) << monthlyPayment
                  << std::setw(13) << totalPayment << std::endl;
        annualInterestRate += 0.125;
        count++;
    }

    return 0;
}
