// Exercise 7.10 - Find the index of the largest element

#include <iostream>

int indexOfLargestElement(double array[], int size)
{
    int index = 0;
    double largest = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] > largest)
        {
            index = i;
            largest = array[i];
        }
    }
    return index;
}

int main()
{
    std::cout << "Enter 15 numbers: ";
    double numbers[15];

    for (int i = 0; i < 15; i++)
    {
        std::cin >> numbers[i];
    }
    int index = indexOfLargestElement(numbers, 15);
    std::cout << "The index of the largest element is: " << index << std::endl;
    return 0;
}