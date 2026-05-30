#include "SquareSeries.h"

double SquareSeries::sum(int n) const
{
    if (n == 1)
    {
        return 1.0;
    }
    return sum(n - 1) + 1.0 / (n * n);
}
