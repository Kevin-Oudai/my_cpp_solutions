// Exercise 5.43 - Simulation: Clock countdown

#include <iostream>
#include <ctime>

int main()
{
    std::cout << "Enter the number of seconds: ";
    int startValue;
    std::cin >> startValue;

    long startTime = time(0);
    long endTime = startTime;
    for (int i = 1; i <= startValue; i++)
    {
        while (endTime - startTime < i)
        {
            endTime = time(0);
        }
        (startValue - i != 0) ? std::cout << startValue - i << " seconds remaining" << std::endl
                              : std::cout << "Stopped\n";
    }
    return 0;
}