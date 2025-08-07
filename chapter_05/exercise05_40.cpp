// Exercise 5.40 - Simulation: Even or Odd

#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    int num, even = 0, odd = 0;
    srand(time(0));
    for (int i = 0; i < 100000; i++)
    {
        num = rand();
        (num % 2 == 0) ? even++ : odd++;
    }
    std::cout << "Even: " << even << "\tOdd: " << odd << std::endl;
    return 0;
}