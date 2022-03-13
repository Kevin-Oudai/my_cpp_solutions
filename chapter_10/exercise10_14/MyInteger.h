#ifndef MYINTEGER_H
#define MYINTEGER_H
#include <string>

class MyInteger
{
public:
    MyInteger(int n);
    int getInteger();
    bool isEven();
    bool isOdd();
    bool isPrime();
    static bool isEven(int n);
    static bool isOdd(int n);
    static bool isPrime(int n);
    static bool isEven(const MyInteger &a);
    static bool isOdd(const MyInteger &a);
    static bool isPrime(const MyInteger &a);
    bool equals(int) const;
    bool equals(const MyInteger &a) const;
    static int parseInt(const std::string &);

private:
    int value;
};
#endif