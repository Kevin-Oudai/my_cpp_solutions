#include "ReverseNumberFileSorter.h"
#include <fstream>
#include <iostream>

ReverseNumberFileSorter::ReverseNumberFileSorter(const char *filename, int size)
{
    this->filename = filename;
    this->size = size;
    numbers = new int[size];
}

ReverseNumberFileSorter::~ReverseNumberFileSorter()
{
    delete[] numbers;
}

int ReverseNumberFileSorter::run()
{
    if (!readNumbers())
    {
        std::cout << filename << " does not exist" << std::endl;
        return 0;
    }

    sortDescending();
    writeNumbers();

    std::cout << "The numbers are sorted in reverse order." << std::endl;
    return 0;
}

bool ReverseNumberFileSorter::readNumbers()
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

void ReverseNumberFileSorter::sortDescending()
{
    for (int i = 0; i < size - 1; i++)
    {
        int currentMax = numbers[i];
        int currentMaxIndex = i;

        for (int j = i + 1; j < size; j++)
        {
            if (currentMax < numbers[j])
            {
                currentMax = numbers[j];
                currentMaxIndex = j;
            }
        }

        if (currentMaxIndex != i)
        {
            numbers[currentMaxIndex] = numbers[i];
            numbers[i] = currentMax;
        }
    }
}

void ReverseNumberFileSorter::writeNumbers() const
{
    std::ofstream output(filename);

    for (int i = 0; i < size; i++)
    {
        output << numbers[i];
        if (i < size - 1)
        {
            output << " ";
        }
    }

    output << std::endl;
    output.close();
}
