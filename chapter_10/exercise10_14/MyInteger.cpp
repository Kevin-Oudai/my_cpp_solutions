#include "MyInteger.h"

MyInteger::MyInteger(int n)
{
    value = n;
}

int MyInteger::getInteger()
{
    return value;
}

bool MyInteger::isEven()
{
    if (value % 2 == 0)
    {
        return true;
    }
    return false;
}

bool MyInteger::isOdd()
{
    if (value % 2 == 1)
    {
        return true;
    }
    return false;
}

bool MyInteger::isPrime()
{
    if (value == 2 || value == 3)
    {
        return true;
    }

    for (int i = 2; i <= value / 2; i++)
    {
        if (value % i == 0)
        {
            return false;
        }
    }

    return true;
}

bool MyInteger::isEven(int n)
{
    if (n % 2 == 0)
    {
        return true;
    }
    return false;
}

bool MyInteger::isOdd(int n)
{
    if (n % 2 == 1)
    {
        return true;
    }
    return false;
}

bool MyInteger::isPrime(int n)
{
    if (n == 2 || n == 3)
    {
        return true;
    }
    for (int i = 2; i < n / 2; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool MyInteger::isEven(const MyInteger &a)
{
    int num = a.value;
    if (num % 2 == 0)
    {
        return true;
    }
    return false;
}

bool MyInteger::isOdd(const MyInteger &a)
{
    int num = a.value;
    if (num % 2 == 1)
    {
        return true;
    }
    return false;
}

bool MyInteger::isPrime(const MyInteger &a)
{
    int n = a.value;
    if (n == 2 || n == 3)
    {
        return true;
    }
    for (int i = 2; i < n / 2; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool MyInteger::equals(int n) const
{
    if (value == n)
    {
        return true;
    }

    return false;
}

bool MyInteger::equals(const MyInteger &a) const
{
    if (a.value == value)
    {
        return true;
    }
    return false;
}

int MyInteger::parseInt(const std::string &s)
{
    std::string integers[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    int num = 0;
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (integers[j] == s.substr(i, 1))
            {
                num = num * 10 + j;
            }
        }
    }
    return num;
}