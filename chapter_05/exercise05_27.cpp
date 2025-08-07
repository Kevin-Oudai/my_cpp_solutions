// Exercise 5.27 - Compute pi
#include <iostream>
#include <cmath>

int main()
{
    double sum;
    for (int n = 100; n <= 600; n += 100)
    {
        sum = 0;
        for (int i = n; i > 0; i--)
        {
            sum += (1.0 / std::pow(i, 2));
        }
        sum *= 6;
        sum = std::sqrt(sum);
        std::cout << "The value of pi when n = " << n << " is " << sum << std::endl;
    }
    return 0;
}