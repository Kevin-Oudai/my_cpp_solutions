// Exercise 7.3 - Count Occurence of numbers
#include <iostream>

void displayCount(int integers[], int integer)
{
    int count = 0;
    for (int i = 0; i < 100; i++)
    {
        if (integers[i] == 0)
        {
            break;
        }
        if (integers[i] == integer)
        {
            count++;
        }
    }
    if (count > 0)
    {
        std::cout << integer << " occurs " << count << " time";
        (count > 1) ? std::cout << "s." << std::endl : std::cout << "." << std::endl;
    }
}

void initializeList(int integers[])
{
    for (int i = 0; i < 100; i++)
    {
        integers[i] = 0;
    }
}

int main()
{
    std::cout << "Enter the integers between 1 and 100: ";
    int integers[100], integer;
    initializeList(integers);
    for (int i = 0; i < 100; i++)
    {
        std::cin >> integer;
        if (integer == 0)
        {
            break;
        }
        integers[i] = integer;
    }

    for (int i = 1; i <= 100; i++)
    {
        displayCount(integers, i);
    }

    return 0;
}