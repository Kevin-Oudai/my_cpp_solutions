// Exercise 5.20 - Display pattern D using loops

#include <iostream>
#include <iomanip>

int main()
{
    int upCount = 6, count = 1;
    while (count <= upCount)
    {
        for (int i = 0; i < upCount - count; i++)
        {
            std::cout << std::setw(2) << " ";
        }
        for (int i = 1; i <= count; i++)
        {
            std::cout << std::setw(2) << i;
        }
        std::cout << std::endl;
        count++;
    }
}