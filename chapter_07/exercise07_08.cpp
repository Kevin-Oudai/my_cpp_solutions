// Exercise 7.8 - Product of an array

#include <iostream>

int product(const int array[], int size);
double product(const double array[], int size);

int main()
{
    double values[3] = {3.2, 5.7, 29.0};
    double result = product(values, 3);
    std::cout << "The product of the array is: " << result << std::endl;
    return 0;
}

int product(const int array[], int size)
{
    int total = 1;
    for (int i = 0; i < size; i++)
    {
        total *= array[i];
    }
    return total;
}

double product(const double array[], int size)
{
    double total = 1;
    for (int i = 0; i < size; i++)
    {
        total *= array[i];
    }
    return total;
}