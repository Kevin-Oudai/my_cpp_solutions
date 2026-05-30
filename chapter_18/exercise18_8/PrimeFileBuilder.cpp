#include "PrimeFileBuilder.h"
#include <fstream>
#include <iostream>

PrimeFileBuilder::PrimeFileBuilder()
{
    fileName = "Exercise18_8.dat";
}

void PrimeFileBuilder::ensureSeedFile() const
{
    std::ifstream input(fileName.c_str(), std::ios::binary);
    bool hasData = false;
    if (input)
    {
        input.seekg(0, std::ios::end);
        hasData = input.tellg() >= static_cast<std::streamoff>(sizeof(long));
    }
    input.close();

    if (!hasData)
    {
        std::ofstream output(fileName.c_str(), std::ios::binary);
        long firstPrime = 2;
        output.write(reinterpret_cast<char*>(&firstPrime), sizeof(long));
        output.close();
    }
}

long PrimeFileBuilder::countPrimes() const
{
    std::ifstream input(fileName.c_str(), std::ios::binary);
    if (!input)
        return 0;

    input.seekg(0, std::ios::end);
    long bytes = static_cast<long>(input.tellg());
    input.close();

    return bytes / static_cast<long>(sizeof(long));
}

long PrimeFileBuilder::getLastPrime() const
{
    std::ifstream input(fileName.c_str(), std::ios::binary);
    if (!input)
        return 0;

    input.seekg(0, std::ios::end);
    long bytes = static_cast<long>(input.tellg());
    if (bytes < static_cast<long>(sizeof(long)))
    {
        input.close();
        return 0;
    }

    long lastPrime = 0;
    input.seekg(-static_cast<long>(sizeof(long)), std::ios::end);
    input.read(reinterpret_cast<char*>(&lastPrime), sizeof(long));
    input.close();
    return lastPrime;
}

bool PrimeFileBuilder::isPrimeFromFile(long number) const
{
    const int CHUNK_SIZE = 100000;
    long* primes = new long[CHUNK_SIZE];
    std::ifstream input(fileName.c_str(), std::ios::binary);
    bool isPrime = true;

    while (input && isPrime)
    {
        input.read(reinterpret_cast<char*>(primes), CHUNK_SIZE * sizeof(long));
        int valuesRead = static_cast<int>(input.gcount() / sizeof(long));

        for (int i = 0; i < valuesRead; i++)
        {
            if (primes[i] > number / primes[i])
            {
                input.close();
                delete [] primes;
                return true;
            }

            if (number % primes[i] == 0)
            {
                isPrime = false;
                break;
            }
        }
    }

    input.close();
    delete [] primes;
    return isPrime;
}

void PrimeFileBuilder::appendPrime(long number) const
{
    std::ofstream output(fileName.c_str(), std::ios::binary | std::ios::app);
    output.write(reinterpret_cast<char*>(&number), sizeof(long));
    output.close();
}

void PrimeFileBuilder::generateThrough(long limit)
{
    ensureSeedFile();
    long candidate = getLastPrime() + 1;
    if (candidate <= 2)
        candidate = 3;
    if (candidate % 2 == 0)
        candidate++;

    while (candidate <= limit)
    {
        if (isPrimeFromFile(candidate))
            appendPrime(candidate);
        candidate += 2;
    }

    std::cout << countPrimes() << " primes are stored in Exercise18_8.dat" << std::endl;
    std::cout << "The last stored prime is " << getLastPrime() << std::endl;
}
