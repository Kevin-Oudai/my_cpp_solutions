#include <iostream>
#include "PrimeFileBuilder.h"

int main()
{
    std::cout << "Enter limit for generated primes (1000000000 for the exercise): ";
    long limit;
    std::cin >> limit;

    if (limit < 2)
    {
        std::cout << "No primes are generated" << std::endl;
        return 0;
    }

    PrimeFileBuilder builder;
    builder.generateThrough(limit);

    return 0;
}
