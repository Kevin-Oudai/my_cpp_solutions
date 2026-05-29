#include "CumulativeRanking.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

CumulativeRanking::CumulativeRanking(int capacity)
{
    this->capacity = capacity;
    boySize = 0;
    girlSize = 0;
    boyNames = new std::string[capacity];
    girlNames = new std::string[capacity];
    boyCounts = new int[capacity];
    girlCounts = new int[capacity];
}

CumulativeRanking::~CumulativeRanking()
{
    delete[] boyNames;
    delete[] girlNames;
    delete[] boyCounts;
    delete[] girlCounts;
}

int CumulativeRanking::run()
{
    if (!readFiles())
    {
        return 0;
    }

    sortByCount(boyNames, boyCounts, boySize);
    sortByCount(girlNames, girlCounts, girlSize);

    displayRanking("Boy names", boyNames, boyCounts, boySize);
    std::cout << std::endl;
    displayRanking("Girl names", girlNames, girlCounts, girlSize);

    return 0;
}

std::string CumulativeRanking::getFilename(int year) const
{
    std::ostringstream filename;
    filename << "Babynameranking" << year << ".txt";
    return filename.str();
}

int CumulativeRanking::parseCount(const std::string &text) const
{
    int count = 0;

    for (unsigned i = 0; i < text.length(); i++)
    {
        if (text[i] >= '0' && text[i] <= '9')
        {
            count = count * 10 + text[i] - '0';
        }
    }

    return count;
}

int CumulativeRanking::findName(const std::string *names, int size,
                                const std::string &name) const
{
    for (int i = 0; i < size; i++)
    {
        if (names[i] == name)
        {
            return i;
        }
    }

    return -1;
}

void CumulativeRanking::addName(std::string *names, int *counts, int &size,
                                const std::string &name, int count)
{
    int index = findName(names, size, name);

    if (index == -1 && size < capacity)
    {
        names[size] = name;
        counts[size] = count;
        size++;
    }
    else if (index != -1)
    {
        counts[index] += count;
    }
}

bool CumulativeRanking::readFiles()
{
    for (int year = 2001; year <= 2010; year++)
    {
        std::string filename = getFilename(year);
        std::ifstream input(filename.c_str());

        if (input.fail())
        {
            std::cout << filename << " does not exist" << std::endl;
            return false;
        }

        int rank;
        std::string boyName;
        std::string boyCountText;
        std::string girlName;
        std::string girlCountText;

        while (input >> rank >> boyName >> boyCountText >> girlName >> girlCountText)
        {
            addName(boyNames, boyCounts, boySize, boyName, parseCount(boyCountText));
            addName(girlNames, girlCounts, girlSize, girlName, parseCount(girlCountText));
        }

        input.close();
    }

    return true;
}

void CumulativeRanking::sortByCount(std::string *names, int *counts, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int currentMax = counts[i];
        int currentMaxIndex = i;

        for (int j = i + 1; j < size; j++)
        {
            if (currentMax < counts[j])
            {
                currentMax = counts[j];
                currentMaxIndex = j;
            }
        }

        if (currentMaxIndex != i)
        {
            int tempCount = counts[i];
            counts[i] = counts[currentMaxIndex];
            counts[currentMaxIndex] = tempCount;

            std::string tempName = names[i];
            names[i] = names[currentMaxIndex];
            names[currentMaxIndex] = tempName;
        }
    }
}

void CumulativeRanking::displayRanking(const char *title, const std::string *names,
                                       const int *counts, int size) const
{
    std::cout << title << std::endl;
    std::cout << std::left << std::setw(8) << "Rank"
              << std::setw(15) << "Name"
              << "Cumulative count" << std::endl;

    for (int i = 0; i < size; i++)
    {
        std::cout << std::left << std::setw(8) << (i + 1)
                  << std::setw(15) << names[i]
                  << counts[i] << std::endl;
    }
}
