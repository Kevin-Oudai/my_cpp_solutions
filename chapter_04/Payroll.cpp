#include <iostream>
#include <string>

int main()
{
    std::string name;
    double hoursWorked, rate, federalTax, stateTax;

    std::cout << "Enter employee's name: ";
    std::getline(std::cin, name);

    std::cout << "Enter number of hours worked in a week: ";
    std::cin >> hoursWorked;

    std::cout << "Enter hourly pay rate: ";
    std::cin >> rate;

    std::cout << "Enter federal tax witholding rate: ";
    std::cin >> federalTax;

    std::cout << "Enter state tax withholding rate: ";
    std::cin >> stateTax;

    std::cout << "Employee Name: " << name << std::endl;
    std::cout << "Hours Worked: " << hoursWorked << std::endl;
    std::cout << "Pay Rate: $" << rate << std::endl;
    std::cout << "Gross Pay: $" << hoursWorked * rate << std::endl;
    std::cout << "Deductions:" << std::endl;
    std::cout << "\tFederal Withholding (" << federalTax * 100 << "%): $"
              << federalTax * hoursWorked * rate << std::endl;
    std::cout << "\tState Witholding (" << stateTax * 100 << "%): $"
              << stateTax * hoursWorked * rate << std::endl;
    std::cout << "\tTotal Deduction: $"
              << (federalTax * hoursWorked * rate) + (stateTax * hoursWorked * rate) << std::endl;

    std::cout << "Net Pay: $"
              << (hoursWorked * rate) - ((federalTax * hoursWorked * rate) + (stateTax * hoursWorked * rate))
              << std::endl;

    return 0;
}