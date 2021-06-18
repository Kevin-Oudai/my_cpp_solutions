// Exercise 5.9 - Financial Application: Compute Future Apartment Rent

#include <iostream>
#include <iomanip>

int main()
{
    double rate = 0.03;
    double rent = 1000.0;
    int years = 5;
    while (years > 0)
    {
        rent *= (1.0 + rate);
        years--;
    }

    std::cout << "The rent in 5 years is $"
              << std::setprecision(2) << std::fixed << std::showpoint << rent << std::endl;
    std::cout << "The total rent for the 5th year is $" << rent * 12 << std::endl;
    return 0;
}