// Exercise 7.2 - Largest and Smallest Integers
#include <iostream>

void FindLargest(int values[], int size, int &large)
{
    large = values[0];
    for (int i = 1; i < size; i++)
    {
        if (values[i] > large)
        {
            large = values[i];
        }
    }
}

void FindSmallest(int values[], int size, int &small)
{
    small = values[0];
    for (int i = 1; i < size; i++)
    {
        if (values[i] < small)
        {
            small = values[i];
        }
    }
}

int main()
{
    // Find Largest
    // Find Smallest
    const int SIZE = 6;
    int values[SIZE], small, large;
    std::cout << "Enter 6 integers: ";
    for (int i = 0; i < SIZE; i++)
    {
        std::cin >> values[i];
    }
    FindLargest(values, SIZE, large);
    FindSmallest(values, SIZE, small);

    std::cout << "The largest values entered is: " << large << std::endl;
    std::cout << "The smallest values entered is: " << small << std::endl;
    return 0;
}