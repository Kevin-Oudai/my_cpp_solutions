// Exercise 5.24 - Financial Application: Loan amortization schedule

#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
    // Take inputs
    std::cout << "Loan Amount: ";
    double loanAmount;
    std::cin >> loanAmount;

    std::cout << "Number of Years: ";
    int numberOfYears;
    std::cin >> numberOfYears;

    std::cout << "Annual Interest Rate: ";
    double annualInterestRate;
    std::cin >> annualInterestRate;

    // Calculate and display monthly payment
    double monthlyInterestRate = annualInterestRate / 1200;

    double monthlyPayment = loanAmount * monthlyInterestRate /
                            (1 - 1 / pow(1 + monthlyInterestRate, numberOfYears * 12));

    std::cout << std::setprecision(2) << std::fixed << std::showpoint
              << "\nMonthly Payment: " << monthlyPayment << std::endl;

    // Calculate and display total payment
    double totalPayment = monthlyPayment * numberOfYears * 12;
    monthlyPayment = static_cast<int>(monthlyPayment * 100) / 100.0;
    totalPayment = static_cast<int>(totalPayment * 100) / 100.0;

    std::cout << "Total Payment: " << totalPayment << "\n\n";
    int count = 1;
    std::cout << std::left << std::setw(11) << "Payment#"
              << std::setw(11) << "Interest"
              << std::setw(12) << "Principal"
              << std::setw(7) << "Balance\n";

    double interest, principal;
    while (count <= 12)
    {
        interest = monthlyInterestRate * loanAmount;
        principal = monthlyPayment - interest;
        loanAmount -= principal;
        std::cout << std::left << std::setw(11) << count
                  << std::setprecision(2) << std::fixed << std::showpoint
                  << std::setw(11) << interest
                  << std::setw(12) << principal
                  << std::setw(7) << std::right << loanAmount << std::endl;
        count++;
    }

    return 0;
}
