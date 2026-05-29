#ifndef RATIONAL_H
#define RATIONAL_H

#include <iosfwd>

class Rational
{
public:
    Rational(long long n = 0, long long d = 1);

    long long numerator() const;
    long long denominator() const;

    Rational operator+(const Rational &other) const;
    Rational &operator+=(const Rational &other);

    double toDouble() const;

    friend std::ostream &operator<<(std::ostream &os, const Rational &r);

private:
    // r[0] = numerator, r[1] = denominator
    int r[2];

    static long long greatestCommonDivisor(long long n, long long d);
    void reduce();
};

#endif
