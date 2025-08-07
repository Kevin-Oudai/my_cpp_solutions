// Exercise 5.14 - Find the largest n such that 2^n < 30,000

#include <iostream>
#include <cmath>

int main()
{
    int n = 0;
    while (pow(2, n) <= 30000)
    {
        n++;
    }
    n--;
    std::cout << "The largest value of n is: " << n << std::endl;
    return 0;
}