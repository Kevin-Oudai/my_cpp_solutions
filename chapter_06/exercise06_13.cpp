// Exercise 6.13 - Estimate Pi
#include <iostream>
#include <iomanip>
#include <cmath>

double term(double n)
{
    double answer = 1.0 / std::pow(n, 2);
    return answer;
}

double sumTo(double n)
{
    double sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += term(i);
    }
    return sum;
}

int main()
{
    std::cout << std::setw(6) << std::left << "n"
              << "f(n)" << std::endl;
    for (int i = 2; i <= 20; i += 2)
    {
        std::cout << std::setw(6) << std::left << i
                  << std::sqrt(6 * sumTo(i)) << std::endl;
    }
}