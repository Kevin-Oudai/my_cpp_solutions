#include "PrimePerformance.h"
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <vector>

int PrimePerformance::countBySquareRoot(int limit) const
{
    int count = 0;
    for (int number = 2; number <= limit; number++)
    {
        bool isPrime = true;
        int squareRoot = static_cast<int>(sqrt(number * 1.0));
        for (int divisor = 2; divisor <= squareRoot; divisor++)
        {
            if (number % divisor == 0)
            {
                isPrime = false;
                break;
            }
        }

        if (isPrime)
            count++;
    }

    return count;
}

int PrimePerformance::countByPrimeVector(int limit) const
{
    std::vector<int> primes;
    int count = 0;
    int squareRoot = 1;

    for (int number = 2; number <= limit; number++)
    {
        bool isPrime = true;
        if (squareRoot * squareRoot < number)
            squareRoot++;

        for (int i = 0; i < static_cast<int>(primes.size()) && primes[i] <= squareRoot; i++)
        {
            if (number % primes[i] == 0)
            {
                isPrime = false;
                break;
            }
        }

        if (isPrime)
        {
            primes.push_back(number);
            count++;
        }
    }

    return count;
}

int PrimePerformance::countBySieve(int limit) const
{
    bool* primes = new bool[limit + 1];
    for (int i = 0; i <= limit; i++)
        primes[i] = true;

    for (int k = 2; k <= limit / k; k++)
    {
        if (primes[k])
        {
            for (int i = k; i <= limit / k; i++)
                primes[k * i] = false;
        }
    }

    int count = 0;
    for (int i = 2; i <= limit; i++)
    {
        if (primes[i])
            count++;
    }

    delete [] primes;
    return count;
}

long PrimePerformance::timeAlgorithm(int algorithm, int limit, int& count) const
{
    long startTime = static_cast<long>(time(0));
    if (algorithm == 1)
        count = countBySquareRoot(limit);
    else if (algorithm == 2)
        count = countByPrimeVector(limit);
    else
        count = countBySieve(limit);
    long endTime = static_cast<long>(time(0));

    return endTime - startTime;
}

void PrimePerformance::displayTable(bool useExerciseLimits) const
{
    int exerciseLimits[6] = {8000000, 10000000, 12000000, 14000000, 16000000, 18000000};
    int quickLimits[6] = {8000, 10000, 12000, 14000, 16000, 18000};
    int* limits = useExerciseLimits ? exerciseLimits : quickLimits;

    std::cout << std::setw(18) << " ";
    for (int i = 0; i < 6; i++)
        std::cout << std::setw(10) << limits[i];
    std::cout << std::endl;

    const char* labels[3] = {"Listing 18.5", "Listing 18.6", "Listing 18.7"};
    for (int algorithm = 1; algorithm <= 3; algorithm++)
    {
        std::cout << std::setw(18) << labels[algorithm - 1];
        for (int i = 0; i < 6; i++)
        {
            int count = 0;
            long seconds = timeAlgorithm(algorithm, limits[i], count);
            std::cout << std::setw(10) << seconds;
        }
        std::cout << " seconds" << std::endl;
    }
}
