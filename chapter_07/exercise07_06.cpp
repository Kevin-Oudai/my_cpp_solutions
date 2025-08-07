// Exercise 5.17 - PrimeNumbers.cpp
// Listing 5.17 - PrimeNumber.cpp
#include <iostream>
#include <iomanip>
#include <cmath>

bool isPrimeNumber(int primeList[], int number)
{
    bool isPrime = true;
    int rootNumber = sqrt(number);
    if (number == 2)
    {
        return true;
    }

    for (int divisor = 0; divisor <= rootNumber; divisor++)
    {
        if (number % primeList[divisor] == 0)
        {
            return !isPrime;
        }
    }
    return isPrime;
}

void displayPrimes(int primeList[], int size, int primesPerLine)
{
    for (int i = 1; i <= size; i++)
    {
        i % primesPerLine == 0
            ? std::cout << std::setw(4) << primeList[i - 1] << std::endl
            : std::cout << std::setw(4) << primeList[i - 1];
    }
}

int main()
{
    const int NUMBER_OF_PRIMES = 50;
    const int NUMBER_OF_PRIMES_PER_LINE = 10;
    int count = 0;
    int number = 2;
    int primeList[NUMBER_OF_PRIMES];

    std::cout << "The first 50 prime numbers are \n";

    while (count < NUMBER_OF_PRIMES)
    {
        bool isPrime = isPrimeNumber(primeList, number);

        if (isPrime)
        {
            primeList[count] = number;
            count++;
        }
        number++;
    }
    displayPrimes(primeList, NUMBER_OF_PRIMES, NUMBER_OF_PRIMES_PER_LINE);

    return 0;
}