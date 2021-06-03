// Listing 5.9 - TestSum.cpp

#include <iostream>

int main()
{
    double sum = 0;

    for (double i = 0.01; i <= 1.0; i = i + 0.01)
        sum += i;

    std::cout << "The sum is " << sum << std::endl;

    return 0;
}