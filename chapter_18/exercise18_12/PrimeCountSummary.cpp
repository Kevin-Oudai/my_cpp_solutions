#include "PrimeCountSummary.h"
#include <fstream>
#include <iostream>
#include <iomanip>

PrimeCountSummary::PrimeCountSummary()
{
    fileName = "Exercise18_8.dat";
}

bool PrimeCountSummary::fileExistsWithData() const
{
    std::ifstream input(fileName.c_str(), std::ios::binary);
    if (!input)
        return false;

    input.seekg(0, std::ios::end);
    bool hasData = input.tellg() >= static_cast<std::streamoff>(sizeof(long));
    input.close();
    return hasData;
}

void PrimeCountSummary::createSampleFile() const
{
    std::ofstream output(fileName.c_str(), std::ios::binary);
    for (long number = 2; number <= 100000; number++)
    {
        bool isPrime = true;
        for (long divisor = 2; divisor <= number / divisor; divisor++)
        {
            if (number % divisor == 0)
            {
                isPrime = false;
                break;
            }
        }

        if (isPrime)
            output.write(reinterpret_cast<char*>(&number), sizeof(long));
    }
    output.close();
}

void PrimeCountSummary::displaySummary() const
{
    bool createdSample = false;
    if (!fileExistsWithData())
    {
        createSampleFile();
        createdSample = true;
    }

    long limits[7] = {10, 100, 1000, 10000, 100000, 1000000, 10000000};
    long counts[7] = {0, 0, 0, 0, 0, 0, 0};
    bool completed[7] = {false, false, false, false, false, false, false};

    std::ifstream input(fileName.c_str(), std::ios::binary);
    long value = 0;
    long count = 0;

    while (input.read(reinterpret_cast<char*>(&value), sizeof(long)))
    {
        count++;
        for (int i = 0; i < 7; i++)
        {
            if (!completed[i] && value > limits[i])
            {
                counts[i] = count - 1;
                completed[i] = true;
            }
        }
    }
    input.close();

    long maxCovered = createdSample ? 100000 : value;
    for (int i = 0; i < 7; i++)
    {
        if (!completed[i] && maxCovered >= limits[i])
        {
            counts[i] = count;
            completed[i] = true;
        }
    }

    std::cout << std::setw(14) << "Number" << std::setw(14) << "Prime count" << std::endl;
    for (int i = 0; i < 7; i++)
    {
        std::cout << std::setw(14) << limits[i];
        if (completed[i])
            std::cout << std::setw(14) << counts[i] << std::endl;
        else
            std::cout << std::setw(14) << "not ready" << std::endl;
    }
}
