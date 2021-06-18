// Exercise 5.44 - Monte Carlo Simulation (Dart Throw)

#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
    int x, y, odd = 0, even = 0;
    for (int i = 0; i < 1000; i++)
    {
        x = (rand() % 101) - 50;
        y = (rand() % 101) - 50;
        if (x <= 0)
            odd++;
        else if (y >= 0 && y < -x + 50)
        {
            odd++;
        }
        else
        {
            even++;
        }
    }
    std::cout << "The probability of hitting an odd region is: " << odd * 1.0 / (even + odd) << std::endl;
    return 0;
}