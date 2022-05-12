// Exercise 5.26 - Product of a series
#include <iostream>

int main()
{
    double total = 0;
    for (int i = 97; i >= 5; i -= 4)
    {
        total += (1.0 / i);
    }
    std::cout << "The total is: " << total << std::endl;
    return 0;
}