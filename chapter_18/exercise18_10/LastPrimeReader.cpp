#include "LastPrimeReader.h"
#include <fstream>

LastPrimeReader::LastPrimeReader()
{
    fileName = "Exercise18_8.dat";
}

bool LastPrimeReader::fileExistsWithData() const
{
    std::ifstream input(fileName.c_str(), std::ios::binary);
    if (!input)
        return false;

    input.seekg(0, std::ios::end);
    bool hasData = input.tellg() >= static_cast<std::streamoff>(sizeof(long));
    input.close();
    return hasData;
}

void LastPrimeReader::createSampleFile() const
{
    long primes[25] = {
        2, 3, 5, 7, 11,
        13, 17, 19, 23, 29,
        31, 37, 41, 43, 47,
        53, 59, 61, 67, 71,
        73, 79, 83, 89, 97
    };

    std::ofstream output(fileName.c_str(), std::ios::binary);
    for (int i = 0; i < 25; i++)
        output.write(reinterpret_cast<char*>(&primes[i]), sizeof(long));
    output.close();
}

std::vector<long> LastPrimeReader::readLastPrimes(int count)
{
    if (!fileExistsWithData())
        createSampleFile();

    std::vector<long> values;
    std::ifstream input(fileName.c_str(), std::ios::binary);
    input.seekg(0, std::ios::end);
    long fileBytes = static_cast<long>(input.tellg());
    long totalValues = fileBytes / static_cast<long>(sizeof(long));
    long valuesToRead = count < totalValues ? count : totalValues;

    input.seekg((totalValues - valuesToRead) * static_cast<long>(sizeof(long)), std::ios::beg);
    for (int i = 0; i < valuesToRead; i++)
    {
        long value;
        input.read(reinterpret_cast<char*>(&value), sizeof(long));
        values.push_back(value);
    }

    input.close();
    return values;
}
