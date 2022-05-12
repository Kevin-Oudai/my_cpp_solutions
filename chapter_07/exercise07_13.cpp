// Exercise 7.13 - Game: Rolling a die

#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    const int TRIALS = 10000;
    int results[6] = {0, 0, 0, 0, 0, 0};
    int count = 0;
    srand(time(0));
    while (count < TRIALS)
    {
        results[rand() % 6] += 1;
        count++;
    }
    for (int i = 0; i < 6; i++)
    {
        std::cout << "The value " << i + 1 << " occured " << results[i] << " times." << std::endl;
    }

    return 0;
}