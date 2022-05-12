// Exercise 6.12 - Sum Series
#include <iostream>
#include <iomanip>

double term(double n)
{
    double answer = 1.0 / (n * (n + 2));
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
    for (int i = 2; i <= 14; i += 2)
    {
        std::cout << std::setw(6) << std::left << i
                  << sumTo(i) << std::endl;
    }
}