#include "ThreeOverSeries.h"

double ThreeOverSeries::sum(int n) const
{
    if (n == 1)
    {
        return 1.0;
    }
    return sum(n - 1) + 3.0 / (n + 2);
}
