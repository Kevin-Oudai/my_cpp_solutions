// Exercise 5.20 - Display Pattern C using loops
#include <iostream>
#include <iomanip>

int main()
{
    int upCount = 3, downCount = 2, count = 0;
    while (count <= upCount)
    {
        for (int i = 0; i < upCount - count; i++)
        {
            std::cout << std::setw(2) << " ";
        }
        for (int i = 0; i < count; i++)
        {
            std::cout << std::setw(2) << "3";
        }
        std::cout << std::endl;
        count++;
    }
    count = 0;
    while (count < downCount)
    {
        for (int i = count; i >= 0; i--)
        {
            std::cout << std::setw(2) << " ";
        }
        for (int i = downCount - count; i > 0; i--)
        {
            std::cout << std::setw(2) << "3";
        }
        std::cout << std::endl;
        count++;
    }
    return 0;
}