#include "Rational.h"
#include <iostream>

Rational::Rational(long long n, long long d)
{
    if (d == 0)
    {
        n = 0;
        d = 1;
    }
    r[0] = static_cast<int>(n);
    r[1] = static_cast<int>(d);
    reduce();
}

long long Rational::numerator() const
{
    return r[0];
}

long long Rational::denominator() const
{
    return r[1];
}

Rational Rational::operator+(const Rational &other) const
{
    Rational result(r[0] * other.r[1] + other.r[0] * r[1], r[1] * other.r[1]);
    return result;
}

Rational &Rational::operator+=(const Rational &other)
{
    r[0] = r[0] * other.r[1] + other.r[0] * r[1];
    r[1] = r[1] * other.r[1];
    reduce();
    return *this;
}

double Rational::toDouble() const
{
    return static_cast<double>(r[0]) / static_cast<double>(r[1]);
}

std::ostream &operator<<(std::ostream &os, const Rational &rat)
{
    os << rat.r[0] << "/" << rat.r[1];
    return os;
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
    long long g = greatestCommonDivisor(static_cast<long long>(r[0]), static_cast<long long>(r[1]));
    if (g != 0)
    {
        r[0] = static_cast<int>(r[0] / g);
        r[1] = static_cast<int>(r[1] / g);
    }
    if (r[1] < 0)
    {
        r[1] = -r[1];
        r[0] = -r[0];
    }
}
