#include <iostream>
#include <cstdlib>
#include <ctime>
#include "StopWatch.h"

void sortRandom(int random[])
{
    int sm, smi, temp;
    for (int i = 0; i < 100000; i++)
    {
        sm = random[i];
        smi = i;
        for (int j = i + 1; j < 100000; j++)
        {
            if (random[j] < sm)
            {
                sm = random[j];
                smi = j;
            }
        }
        temp = random[i];
        random[i] = random[smi];
        random[smi] = temp;
    }
}

int main()
{
    srand(time(0));
    int random[100000] = {};
    std::cout << "Generating random numbers..." << std::endl;
    for (int i = 0; i < 100000; i++)
    {
        random[i] = rand() % 1000;
    }
    std::cout << "Starting timer... " << std::endl;
    StopWatch timer;
    std::cout << "Sorting random list..." << std::endl;
    sortRandom(random);
    std::cout << "Stopping timer..." << std::endl;
    timer.stop();
    std::cout << "Sorting 100000 integers took " << timer.getElapsedTime() << " milliseconds." << std::endl;
    return 0;
}