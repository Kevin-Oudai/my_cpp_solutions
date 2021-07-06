// Exercise 7.11 - Statistics: Compute Deviation

#include <iostream>
#include <cmath>

double mean(const double x[], int size)
{
    double total = x[0];
    for (int i = 1; i < size; i++)
    {
        total += x[i];
    }
    double mean = total / size;
    return mean;
}

double deviation(const double x[], int size)
{
    double average = mean(x, size);
    double total = std::pow(x[0] - average, 2);
    for (int i = 1; i < size; i++)
    {
        total += (std::pow(x[i] - average, 2));
    }
    total /= (size - 1);
    total = std::sqrt(total);
    return total;
}

int main()
{
    double numbers[10];
    std::cout << "Enter ten numbers: ";
    for (int i = 0; i < 10; i++)
    {
        std::cin >> numbers[i];
    }
    double average = mean(numbers, 10);
    double stdDeviation = deviation(numbers, 10);
    std::cout << "The mean is " << average << std::endl;
    std::cout << "The standard deviation is " << stdDeviation << std::endl;
    return 0;
}