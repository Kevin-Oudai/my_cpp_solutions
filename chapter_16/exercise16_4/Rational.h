#ifndef RATIONAL_H
#define RATIONAL_H

#include <iosfwd>

class Rational
{
public:
    Rational(long long numerator = 0, long long denominator = 1);

    long long getNumerator() const;
    long long getDenominator() const;
    long long &operator[](int index);
    long long operator[](int index) const;

    friend std::ostream &operator<<(std::ostream &output, const Rational &rational);

private:
    long long numerator;
    long long denominator;

    static long long greatestCommonDivisor(long long n, long long d);
    void reduce();
};

#endif
