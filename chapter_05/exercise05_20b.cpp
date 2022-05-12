// Exercise 5.20 - Display pattern B using loops
#include <iostream>
#include <iomanip>

int main()
{
    int number = 5, startNumber = 1, count = 0;

    while (count < number)
    {
        for (int i = 0; i < number - count; i++)
        {
            std::cout << std::setw(2) << " ";
        }
        for (int i = 1; i <= startNumber; i++)
        {
            std::cout << std::setw(2) << i;
        }
        std::cout << std::endl;
        startNumber += 2;
        count++;
    }
    return 0;
}