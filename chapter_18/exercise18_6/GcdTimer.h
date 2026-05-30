#ifndef GCDTIMER_H
#define GCDTIMER_H

class GcdTimer
{
public:
    void displayTable(int startIndex, int endIndex) const;

private:
    long fibonacci(int index) const;
    long gcd1(long m, long n) const;
    long gcd2(long m, long n) const;
    long timeGcd1(long m, long n) const;
    long timeGcd2(long m, long n) const;
};

#endif
