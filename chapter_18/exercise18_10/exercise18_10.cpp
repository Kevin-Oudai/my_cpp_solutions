#include <iostream>
#include <vector>
#include "LastPrimeReader.h"

int main()
{
    LastPrimeReader reader;
    std::vector<long> primes = reader.readLastPrimes(10);

    std::cout << "The last " << primes.size() << " prime numbers in Exercise18_8.dat are:" << std::endl;
    for (int i = 0; i < static_cast<int>(primes.size()); i++)
        std::cout << primes[i] << " ";
    std::cout << std::endl;

    return 0;
}
