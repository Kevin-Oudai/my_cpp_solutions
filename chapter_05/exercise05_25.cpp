// Exercise 5.25 - Demonstrate cancellation errors
// Errors do not show up until after 12 decimal places
#include <iostream>
#include <iomanip>

int main()
{
    int n = 50;

    double leftToRight = 0, rightToLeft = 0;
    for (int i = n; i > 0; i--)
    {
        rightToLeft += (1.0 / i);
    }
    for (int i = 1; i <= n; i++)
    {
        leftToRight += (1.0 / i);
    }

    std::cout << "Left to Right: " << std::setprecision(50) << std::fixed << std::showpoint << leftToRight << std::endl;
    std::cout << "Right to Left: " << rightToLeft << std::endl;

    return 0;
}