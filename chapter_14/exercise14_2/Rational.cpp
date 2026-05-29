#include "Rational.h"
#include <iostream>
#include <numeric>
#include <stdexcept>

Rational::Rational(long long n, long long d)
{
    if (d == 0)
    {
        throw std::invalid_argument("Denominator cannot be zero");
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

void Rational::reduce()
{
    long long g = std::gcd(static_cast<long long>(r[0]), static_cast<long long>(r[1]));
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
