#include "FibonacciCalculator.h"

long long FibonacciCalculator::fib(int index) const
{
    if (index == 0)
    {
        return 0;
    }
    if (index == 1)
    {
        return 1;
    }

    long long f0 = 0;
    long long f1 = 1;
    long long currentFib = 0;
    for (int i = 2; i <= index; i++)
    {
        currentFib = f0 + f1;
        f0 = f1;
        f1 = currentFib;
    }
    return currentFib;
}
