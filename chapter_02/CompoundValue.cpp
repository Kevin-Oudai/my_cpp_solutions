#include <iostream>
#include <iomanip>

int main()
{
    double monthlySavingAmount, total;
    std::cout << "Enter the monthly saving amount: ";
    std::cin >> monthlySavingAmount;
    total = monthlySavingAmount * (1 + 0.00417);
    total = (monthlySavingAmount + total) * (1 + 0.00417);
    total = (monthlySavingAmount + total) * (1 + 0.00417);
    total = (monthlySavingAmount + total) * (1 + 0.00417);
    total = (monthlySavingAmount + total) * (1 + 0.00417);
    total = (monthlySavingAmount + total) * (1 + 0.00417);
    std::cout << std::setprecision(2) << std::showpoint << std::fixed;
    std::cout << "After the sixth month, the account value is $" << total << std::endl;
}