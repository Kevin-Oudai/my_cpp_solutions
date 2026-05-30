#include "DigitParityCounter.h"

DigitParityCounter::DigitParityCounter()
{
    evenCount = 0;
    oddCount = 0;
}

void DigitParityCounter::evenAndOddCount(int value)
{
    evenCount = 0;
    oddCount = 0;
    if (value < 0)
    {
        value = -value;
    }
    countDigits(value);
}

int DigitParityCounter::getEvenCount() const
{
    return evenCount;
}

int DigitParityCounter::getOddCount() const
{
    return oddCount;
}

void DigitParityCounter::countDigits(int value)
{
    int digit = value % 10;
    if (digit % 2 == 0)
    {
        evenCount++;
    }
    else
    {
        oddCount++;
    }

    if (value >= 10)
    {
        countDigits(value / 10);
    }
}
