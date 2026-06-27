#include "Rational.h"
#include <iostream>
#include <stdexcept>

Rational::Rational(long long numerator, long long denominator)
{
    if (denominator == 0)
    {
        numerator = 0;
        denominator = 1;
    }

    this->numerator = numerator;
    this->denominator = denominator;
    reduce();
}

long long Rational::getNumerator() const
{
    return numerator;
}

long long Rational::getDenominator() const
{
    return denominator;
}

long long &Rational::operator[](int index)
{
    if (index == 0)
    {
        return numerator;
    }
    if (index == 1)
    {
        return denominator;
    }

    throw std::runtime_error("Subscript index must be 0 or 1");
}

long long Rational::operator[](int index) const
{
    if (index == 0)
    {
        return numerator;
    }
    if (index == 1)
    {
        return denominator;
    }

    throw std::runtime_error("Subscript index must be 0 or 1");
}

std::ostream &operator<<(std::ostream &output, const Rational &rational)
{
    if (rational.denominator == 1)
    {
        output << rational.numerator;
    }
    else
    {
        output << rational.numerator << "/" << rational.denominator;
    }
    return output;
}

long long Rational::greatestCommonDivisor(long long n, long long d)
{
    if (n < 0)
    {
        n = -n;
    }
    if (d < 0)
    {
        d = -d;
    }

    if (n == 0)
    {
        return d == 0 ? 1 : d;
    }
    if (d == 0)
    {
        return n;
    }

    while (d != 0)
    {
        long long remainder = n % d;
        n = d;
        d = remainder;
    }
    return n;
}

void Rational::reduce()
{
    long long divisor = greatestCommonDivisor(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;

    if (denominator < 0)
    {
        denominator = -denominator;
        numerator = -numerator;
    }
}
