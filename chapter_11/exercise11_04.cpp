#include <iostream>

int sumOfEven(const int *array, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i += 2)
    {
        sum += array[i];
    }
    return sum;
}

double sumOfEven(const double *array, int size)
{
    double sum = 0.0;
    for (int i = 0; i < size; i += 2)
    {
        sum += array[i];
    }
    return sum;
}

int main()
{
    int const SIZE = 5;
    int array[SIZE] = {1, 2, 3, 4, 5};
    double array1[SIZE] = {6.7, 8.9, 0.1, 2.3, 4.5};

    int intSum = sumOfEven(array, SIZE);
    double doubleSum = sumOfEven(array1, SIZE);
    std::cout << "The sum of the even indices in array: " << intSum << std::endl;
    std::cout << "The sum of the even indices in array1: " << doubleSum << std::endl;
    return 0;
}