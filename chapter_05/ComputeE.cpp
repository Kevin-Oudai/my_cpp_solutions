// Exercise 5.28 - Compute e^x

#include <iostream>

int main()
{
    std::cout << "Enter an integer: ";
    int x;
    std::cin >> x;

    double eTox = 1, item = 1;
    for (int n = 1; n <= 15; n++)
    {
        item *= 1.0 * x / n;
        eTox += item;
    }
    std::cout << "The value of e^" << x << " is: " << eTox << std::endl;
    return 0;
}