#include <iostream>
#include <iomanip>

int main()
{
    const int NUMBER_OF_PRIMES = 50;
    const int NUMBER_OF_PRIMES_PER_LINE = 10;
    int count = 0;
    int number = 2;

    std::cout << "The first 50 prime numbers are \n";

    while (count < NUMBER_OF_PRIMES)
    {
        bool isPrime = true;

        for (int divisor = 2; divisor <= number / 2; divisor++)
        {
            if (number % divisor == 0)
            {
                isPrime = false;
                break;
            }
        }

        if (isPrime)
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

    return 0;
}