// Exercise 7.9 - Find the smallest element

#include <iostream>

double min(double array[], int size)
{
    double min = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }
    return min;
}

int main()
{
    std::cout << "Enter 10 numbers: ";
    double array[10];
    for (int i = 0; i < 10; i++)
    {
        std::cin >> array[i];
    }
    double minimum = min(array, 10);
    std::cout << "The minimum number is " << minimum << std::endl;
    return 0;
}