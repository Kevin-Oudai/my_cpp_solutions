#include "GcdTimer.h"
#include <ctime>
#include <iostream>
#include <iomanip>

long GcdTimer::fibonacci(int index) const
{
    if (index == 0)
        return 0;
    if (index == 1)
        return 1;

    long previous = 0;
    long current = 1;
    for (int i = 2; i <= index; i++)
    {
        long next = previous + current;
        previous = current;
        current = next;
    }

    return current;
}

long GcdTimer::gcd1(long m, long n) const
{
    if (n > m)
    {
        long temp = m;
        m = n;
        n = temp;
    }

    if (n == 0)
        return m;
    if (m % n == 0)
        return n;

    for (long k = n / 2; k >= 1; k--)
    {
        if (m % k == 0 && n % k == 0)
            return k;
    }

    return 1;
}

long GcdTimer::gcd2(long m, long n) const
{
    if (n == 0)
        return m;
    if (m % n == 0)
        return n;
    return gcd2(n, m % n);
}

long GcdTimer::timeGcd1(long m, long n) const
{
    long startTime = static_cast<long>(time(0));
    gcd1(m, n);
    long endTime = static_cast<long>(time(0));
    return endTime - startTime;
}

long GcdTimer::timeGcd2(long m, long n) const
{
    long startTime = static_cast<long>(time(0));
    gcd2(m, n);
    long endTime = static_cast<long>(time(0));
    return endTime - startTime;
}

void GcdTimer::displayTable(int startIndex, int endIndex) const
{
    std::cout << std::setw(18) << " ";
    for (int index = startIndex; index <= endIndex; index++)
        std::cout << std::setw(8) << index;
    std::cout << std::endl;

    std::cout << std::setw(18) << "Listing 18.2";
    for (int index = startIndex; index <= endIndex; index++)
        std::cout << std::setw(8) << timeGcd1(fibonacci(index), fibonacci(index - 1));
    std::cout << std::endl;

    std::cout << std::setw(18) << "Listing 18.3";
    for (int index = startIndex; index <= endIndex; index++)
        std::cout << std::setw(8) << timeGcd2(fibonacci(index), fibonacci(index - 1));
    std::cout << std::endl;
}
