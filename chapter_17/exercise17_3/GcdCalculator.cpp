#include "GcdCalculator.h"

int GcdCalculator::gcd(int m, int n) const
{
    if (m < 0)
    {
        m = -m;
    }
    if (n < 0)
    {
        n = -n;
    }
    if (n == 0)
    {
        return m;
    }
    if (m % n == 0)
    {
        return n;
    }
    return gcd(n, m % n);
}
