// Exercise 5.45 - Math: combinations

#include <iostream>

int main()
{
    int combinations = 0;
    for (int i = 1; i <= 7; i++)
    {
        for (int j = i + 1; j <= 7; j++)
        {
            if (i != j)
            {
                std::cout << i << " " << j << std::endl;
                combinations++;
            }
        }
    }
    std::cout << "The total number of all combinations is " << combinations << std::endl;
    return 0;
}