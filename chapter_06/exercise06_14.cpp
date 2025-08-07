// Exercise 6.14 - Financial Application: print a tax table

#include <iostream>
#include <iomanip>
#include <cmath>

double computeTax(int status, double taxableIncome)
{
    double tax;

    if (status == 0) // Compute tax for single filers
    {
        if (taxableIncome <= 8350)
            tax = taxableIncome * 0.10;
        else if (taxableIncome <= 33950)
            tax = 8350 * 0.10 + (taxableIncome - 8350) * 0.15;
        else if (taxableIncome <= 82250)
            tax = 8350 * 0.10 + (33950 - 8350) * 0.15 + (taxableIncome - 33950) * 0.25;
        else if (taxableIncome <= 171550)
            tax = 8350 * 0.10 + (33950 - 8350) * 0.15 + (82250 - 33950) * 0.25 + (taxableIncome - 82250) * 0.28;
        else if (taxableIncome <= 372950)
            tax = 8350 * 0.10 + (33950 - 8350) * 0.15 + (82250 - 33950) * 0.25 + (171550 - 82250) * 0.28 + (taxableIncome - 171550) * 0.33;
        else
            tax = 8350 * 0.10 + (33950 - 8350) * 0.15 + (82250 - 33950) * 0.25 + (171550 - 82250) * 0.28 + (372950 - 171550) * 0.33 + (taxableIncome - 372950) * 0.35;
    }
    else if (status == 1) // Compute tax for married file jointly
    {
        if (taxableIncome <= 16700)
            tax = taxableIncome * 0.10;
        else if (taxableIncome <= 67900)
            tax = 16700 * 0.10 + (taxableIncome - 16700) * 0.15;
        else if (taxableIncome <= 137050)
            tax = 16700 * 0.10 + (67900 - 16700) * 0.15 + (taxableIncome - 67900) * 0.25;
        else if (taxableIncome <= 208850)
            tax = 16700 * 0.10 + (67900 - 16700) * 0.15 + (137050 - 67900) * 0.25 + (taxableIncome - 137050) * 0.28;
        else if (taxableIncome <= 372950)
            tax = 16700 * 0.10 + (67900 - 16700) * 0.15 + (137050 - 67900) * 0.25 + (208850 - 137050) * 0.28 + (taxableIncome - 208850) * 0.33;
        else
            tax = 16700 * 0.10 + (67900 - 16700) * 0.15 + (137050 - 67900) * 0.25 + (208850 - 137050) * 0.28 + (372950 - 208850) * 0.33 + (taxableIncome - 372950) * 0.35;
    }
    else if (status == 2) // Compute tax for married separately
    {
        if (taxableIncome <= 8350)
            tax = taxableIncome * 0.10;
        else if (taxableIncome <= 33950)
            tax = 8350 * 0.10 + (taxableIncome - 8350) * 0.15;
        else if (taxableIncome <= 68525)
            tax = 8350 * 0.10 + (33950 - 8350) * 0.15 + (taxableIncome - 33950) * 0.25;
        else if (taxableIncome <= 104425)
            tax = 8350 * 0.10 + (33950 - 8350) * 0.15 + (68525 - 33950) * 0.25 + (taxableIncome - 68525) * 0.28;
        else if (taxableIncome <= 186475)
            tax = 8350 * 0.10 + (33950 - 8350) * 0.15 + (68525 - 33950) * 0.25 + (104425 - 68525) * 0.28 + (taxableIncome - 104425) * 0.33;
        else
            tax = 8350 * 0.10 + (33950 - 8350) * 0.15 + (68525 - 33950) * 0.25 + (104425 - 68525) * 0.28 + (186475 - 104425) * 0.33 + (taxableIncome - 186475) * 0.35;
    }
    else if (status == 3) // Compute tax for head of household
    {
        if (taxableIncome <= 11950)
            tax = taxableIncome * 0.10;
        else if (taxableIncome <= 45500)
            tax = 11950 * 0.10 + (taxableIncome - 11950) * 0.15;
        else if (taxableIncome <= 117450)
            tax = 11950 * 0.10 + (45500 - 11950) * 0.15 + (taxableIncome - 45500) * 0.25;
        else if (taxableIncome <= 190200)
            tax = 11950 * 0.10 + (45500 - 11950) * 0.15 + (117450 - 45500) * 0.25 + (taxableIncome - 117450) * 0.28;
        else if (taxableIncome <= 372950)
            tax = 11950 * 0.10 + (45500 - 11950) * 0.15 + (117450 - 45500) * 0.25 + (190200 - 117450) * 0.28 + (taxableIncome - 190200) * 0.33;
        else
            tax = 11950 * 0.10 + (45500 - 11950) * 0.15 + (117450 - 45500) * 0.25 + (190200 - 117450) * 0.28 + (372950 - 190200) * 0.33 + (taxableIncome - 372950) * 0.35;
    }
    else
    {
        tax = 0;
    }
    return tax;
}

int main()
{
    std::cout << std::setw(10) << std::left << "Taxable"
              << std::setw(9) << " "
              << std::setw(23) << "Married Joint or"
              << std::setw(11) << "Married"
              << "Head of" << std::endl;

    std::cout << std::setw(10) << std::left << "Income"
              << std::setw(9) << "Single"
              << std::setw(23) << "Qualifying Widow(er)"
              << std::setw(11) << "Separate"
              << "a House" << std::endl
              << std::endl;

    for (int i = 50000; i <= 60000; i += 50)
    {
        std::cout << std::setw(10) << std::left << i
                  << std::setw(9) << std::round(computeTax(0, i))
                  << std::setw(23) << std::round(computeTax(1, i))
                  << std::setw(11) << std::round(computeTax(2, i))
                  << std::floor(computeTax(3, i)) << std::endl;
    }
    return 0;
}