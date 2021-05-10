// Listing 3.3 - ComputeTax.cpp
#include <iostream>

using namespace std;

int main()
{
    // Prompt the user to enter filing status
    cout << "(0-single filer, 1-married jointly, "
         << "or qualifying widow(er), " << endl
         << "2-married separately, 3-head of household)" << endl
         << "Enter the filing status: ";

    int status;
    cin >> status;

    // Prompt the user to enter taxable income
    cout << "Enter the taxable income: ";
    double income;
    cin >> income;

    // Compute tax
    double tax = 0;

    if (status == 0) // Compute tax for single filers
    {
        if (income <= 8350)
            tax = income * 0.10;
        else if (income <= 33950)
            tax = 8350 * 0.10 + (income - 8350) * 0.15;
        else if (income <= 82250)
            tax = 8350 * 0.10 + (33950 - 8350) * 0.15 + (income - 33950) * 0.25;
        else if (income <= 171550)
            tax = 8350 * 0.10 + (33950 - 8350) * 0.15 + (82250 - 33950) * 0.25 + (income - 82250) * 0.28;
        else if (income <= 372950)
            tax = 8350 * 0.10 + (33950 - 8350) * 0.15 + (82250 - 33950) * 0.25 + (171550 - 82250) * 0.28 + (income - 171550) * 0.33;
        else
            tax = 8350 * 0.10 + (33950 - 8350) * 0.15 + (82250 - 33950) * 0.25 + (171550 - 82250) * 0.28 + (372950 - 171550) * 0.33 + (income - 372950) * 0.35;
    }
    else if (status == 1) // Compute tax for married file jointly
    {
        // Left as an exercise
    }
    else if (status == 2) // Compute tax for married separately
    {
        // Left as an exercise
    }
    else if (status == 3) // Compute tax for head of household
    {
        // Left as an exercise
    }
    else
    {
        cout << "Error: invalid status";
        return 0;
    }

    // Display the result
    cout << "Tax is " << static_cast<int>(tax * 100) / 100.0 << endl;
    return 0;
}