#include <iostream>

int main()
{
    int oneLakh = 100000;
    int loanAmount;
    double interest;
    std::cout << "Enter the Loan Amount: ";
    std::cin >> loanAmount;

    int a = loanAmount / oneLakh;

    if (a > 0.1 && a <= 1)
    {
        std::cout << "The interest for the loan is " << 15 << "." << std::endl;
    }
    else if (a > 1 && a <= 5)
    {
        std::cout << "The interest for the loan is " << 13.5 << "." << std::endl;
    }
    else if (a > 5 && a <= 10)
    {
        std::cout << "The interest for the loan is " << 12.5 << "." << std::endl;
    }
    else if (a > 10 && a <= 50)
    {
        std::cout << "The interest for the loan is " << 11 << "." << std::endl;
    }
    else
    {
        std::cout << "Loan cannot by provided."
                  << "." << std::endl;
    }

    return 0;
}