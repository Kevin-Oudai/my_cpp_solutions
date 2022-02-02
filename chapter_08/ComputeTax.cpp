// Exercise 8.6 - Financial Application: compute tax

#include <iostream>
#include <iomanip>

int getStatus()
{
    std::cout << "1. Single Filer" << std::endl;
    std::cout << "2. Married Jointly or Qualifying Widow(er)" << std::endl;
    std::cout << "3. Married Separately" << std::endl;
    std::cout << "4. Head of Household" << std::endl;
    std::cout << "Enter your choice: ";
    int status;
    std::cin >> status;
    return status;
}

double computeTaxes(const int group[], const double rates[], double income)
{
    double tax = 0;
    for (int i = 0; i < 6; i++)
    {
        int lower, upper;
        (i == 0)
            ? lower = 0
            : lower = group[i - 1];
        (i == 5)
            ? upper = income
            : upper = group[i];

        if (income < upper && income > lower)
        {
            upper = income;
            tax += (upper - lower) * rates[i];
            break;
        }
        else
        {
            tax += (upper - lower) * rates[i];
        }
    }

    return tax;
}

void display(double tax, int status)
{
    switch (status)
    {
    case 1:
        std::cout << "The taxes for Single Filer is: $"
                  << std::setprecision(2) << std::fixed << std::showpoint << tax << std::endl;
        break;
    case 2:
        std::cout << "The taxes for Married Jointly or Qualifying Widow(er) is: $"
                  << std::setprecision(2) << std::fixed << std::showpoint << tax << std::endl;
        break;
    case 3:
        std::cout << "The taxes for Married Separately is: $"
                  << std::setprecision(2) << std::fixed << std::showpoint << tax << std::endl;
        break;
    case 4:
        std::cout << "The taxes for Head of Household is: $"
                  << std::setprecision(2) << std::fixed << std::showpoint << tax << std::endl;
        break;
    default:
        std::cout << "Something happened... It does not look good." << std::endl;
        break;
    }
}

int main()
{
    const double rates[] = {0.10, 0.15, 0.25, 0.28, 0.33, 0.36};

    int brackets[4][5] =
        {
            {8350, 33950, 82250, 171550, 372950},  // Single Filer
            {16700, 67900, 137050, 20885, 372950}, // Married jointly or qualifying widow(er)
            {8350, 33950, 68525, 104425, 186475},  // Married Separately
            {11950, 45500, 117450, 190200, 372950} // Head of Household
        };

    std::cout << "Enter your income: ";
    double income;
    std::cin >> income;

    int status = getStatus();

    double tax = computeTaxes(brackets[status - 1], rates, income);

    display(tax, status);
}