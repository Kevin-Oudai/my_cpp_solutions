// Exercise 7.15 - Game: Locker Puzzle

#include <iostream>

int main()
{
    const int SIZE = 1000;
    bool lockers[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        lockers[i] = false;
    }

    for (int j = 1; j <= SIZE; j++)
    {
        for (int k = 1; k <= SIZE; k++)
        {
            if (k % j == 0)
            {
                lockers[k - 1] = !(lockers[k - 1]);
            }
        }
    }
    std::cout << "The opened lockers are: " << std::endl;
    for (int m = 0; m < SIZE; m++)
    {
        if (lockers[m] == true)
        {
            std::cout << m + 1 << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}