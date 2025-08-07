// Exercise 5.15 - Find the smallest n such that 3^n is greater than 30000

#include <iostream>
#include <cmath>

int main()
{
    int n = 0;
    while (pow(3, n) <= 30000)
    {
        n++;
    }
    std::cout << "The largest value of n is: " << n << std::endl;
    return 0;
}