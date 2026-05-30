#include "DigitProduct.h"

int DigitProduct::productDigits(int n) const
{
    if (n < 0)
    {
        n = -n;
    }
    if (n < 10)
    {
        return n;
    }
    return (n % 10) * productDigits(n / 10);
}
