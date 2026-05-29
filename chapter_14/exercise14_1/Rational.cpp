#include "Rational.h"
#include <iostream>
#include <numeric>
#include <stdexcept>

Rational::Rational(long long n, long long d) : num(n), den(d)
{
    if (den == 0)
    {
        throw std::invalid_argument("Denominator cannot be zero");
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

void Rational::reduce()
{
    long long g = std::gcd(num, den);
    num /= g;
    den /= g;
    if (den < 0)
    {
        den = -den;
        num = -num;
    }
}
