#include "DecimalToFractionConverter.h"

Rational DecimalToFractionConverter::convert(const std::string &decimal) const
{
    int sign = 1;
    int start = 0;
    if (decimal.length() > 0 && decimal[0] == '-')
    {
        sign = -1;
        start = 1;
    }

    int decimalPoint = -1;
    for (int i = start; i < static_cast<int>(decimal.length()); i++)
    {
        if (decimal[i] == '.')
        {
            decimalPoint = i;
        }
    }

    if (decimalPoint == -1)
    {
        return Rational(sign * toNumber(decimal, start, static_cast<int>(decimal.length())), 1);
    }

    long long integerPart = toNumber(decimal, start, decimalPoint);
    long long fractionalPart = toNumber(decimal, decimalPoint + 1, static_cast<int>(decimal.length()));
    long long denominator = 1;

    for (int i = decimalPoint + 1; i < static_cast<int>(decimal.length()); i++)
    {
        denominator *= 10;
    }

    long long numerator = integerPart * denominator + fractionalPart;
    return Rational(sign * numerator, denominator);
}

long long DecimalToFractionConverter::toNumber(const std::string &text, int start, int end)
{
    long long number = 0;
    for (int i = start; i < end; i++)
    {
        if (text[i] >= '0' && text[i] <= '9')
        {
            number = number * 10 + (text[i] - '0');
        }
    }
    return number;
}
