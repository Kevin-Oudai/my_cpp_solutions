#include <iostream>
#include <iomanip>

bool isPrime(int number)
{
    for (int divisor = 2; divisor <= number / 2; divisor++)
    {
        if (number % divisor == 0)
        {
            return false;
        }
    }

    return true;
}

void printPrimeNumbers(int numberOfPrimes)
{
    const int NUMBER_OF_PRIMES = 50;
    const int NUMBER_OF_PRIMES_PER_LINE = 10;
    int count = 0;
    int number = 2;

    while (count < numberOfPrimes)
    {
        if (isPrime(number))
        {
            count++;

            if (count % NUMBER_OF_PRIMES_PER_LINE == 0)
            {
                std::cout << std::setw(4) << number << std::endl;
            }
            else
                std::cout << std::setw(4) << number;
        }
        number++;
    }
}

int main()
{
    std::cout << "The first 50 prime numbers are \n";
    printPrimeNumbers(50);

    return 0;
}