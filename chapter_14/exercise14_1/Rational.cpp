#include "Rational.h"
#include <iostream>

Rational::Rational(long long n, long long d) : num(n), den(d)
{
    if (den == 0)
    {
        num = 0;
        den = 1;
    }
    reduce();
}

long long Rational::numerator() const
{
    return num;
}

long long Rational::denominator() const
{
    return den;
}

Rational Rational::operator+(const Rational &other) const
{
    Rational result(num * other.den + other.num * den, den * other.den);
    return result;
}

Rational &Rational::operator+=(const Rational &other)
{
    num = num * other.den + other.num * den;
    den = den * other.den;
    reduce();
    return *this;
}

double Rational::toDouble() const
{
    return static_cast<double>(num) / static_cast<double>(den);
}

std::ostream &operator<<(std::ostream &os, const Rational &r)
{
    os << r.num << "/" << r.den;
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
    long long g = greatestCommonDivisor(num, den);
    num /= g;
    den /= g;
    if (den < 0)
    {
        den = -den;
        num = -num;
    }
}
