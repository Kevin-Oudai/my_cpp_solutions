#include "NumberFileStats.h"
#include <fstream>
#include <iostream>

NumberFileStats::NumberFileStats(const char *filename, int size)
{
    this->filename = filename;
    this->size = size;
    numbers = new int[size];
}

NumberFileStats::~NumberFileStats()
{
    delete[] numbers;
}

int NumberFileStats::run()
{
    if (!readNumbers())
    {
        std::cout << filename << " does not exist" << std::endl;
        return 0;
    }

    int sum = getSum();
    int product = getProduct();
    double average = sum / static_cast<double>(size);

    std::cout << "Sum is " << sum << std::endl;
    std::cout << "Average is " << average << std::endl;
    std::cout << "Product is " << product << std::endl;

    return 0;
}

bool NumberFileStats::readNumbers()
{
    std::ifstream input(filename);
    if (input.fail())
    {
        return false;
    }

    for (int i = 0; i < size; i++)
    {
        input >> numbers[i];
    }

    input.close();
    return true;
}

int NumberFileStats::getSum() const
{
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += numbers[i];
    }

    return sum;
}

int NumberFileStats::getProduct() const
{
    int product = 1;

    for (int i = 0; i < size; i++)
    {
        product *= numbers[i];
    }

    return product;
}
