#include "UniqueNameSorter.h"
#include <fstream>
#include <iostream>
#include <sstream>

UniqueNameSorter::UniqueNameSorter(int capacity, const char *outputFilename)
{
    this->capacity = capacity;
    this->outputFilename = outputFilename;
    size = 0;
    names = new std::string[capacity];
}

UniqueNameSorter::~UniqueNameSorter()
{
    delete[] names;
}

int UniqueNameSorter::run()
{
    if (!readNames())
    {
        return 0;
    }

    sortNames();
    writeNames();

    std::cout << size << " names are written to " << outputFilename << std::endl;
    return 0;
}

std::string UniqueNameSorter::getFilename(int year) const
{
    std::ostringstream filename;
    filename << "Babynameranking" << year << ".txt";
    return filename.str();
}

bool UniqueNameSorter::contains(const std::string &name) const
{
    for (int i = 0; i < size; i++)
    {
        if (names[i] == name)
        {
            return true;
        }
    }

    return false;
}

void UniqueNameSorter::addName(const std::string &name)
{
    if (size < capacity && !contains(name))
    {
        names[size] = name;
        size++;
    }
}

bool UniqueNameSorter::readNames()
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
        std::string boyCount;
        std::string girlName;
        std::string girlCount;

        while (input >> rank >> boyName >> boyCount >> girlName >> girlCount)
        {
            addName(boyName);
            addName(girlName);
        }

        input.close();
    }

    return true;
}

void UniqueNameSorter::sortNames()
{
    for (int i = 0; i < size - 1; i++)
    {
        std::string currentMin = names[i];
        int currentMinIndex = i;

        for (int j = i + 1; j < size; j++)
        {
            if (currentMin > names[j])
            {
                currentMin = names[j];
                currentMinIndex = j;
            }
        }

        if (currentMinIndex != i)
        {
            names[currentMinIndex] = names[i];
            names[i] = currentMin;
        }
    }
}

void UniqueNameSorter::writeNames() const
{
    std::ofstream output(outputFilename);

    for (int i = 0; i < size; i++)
    {
        output << names[i];
        if ((i + 1) % 10 == 0)
        {
            output << std::endl;
        }
        else
        {
            output << " ";
        }
    }

    if (size % 10 != 0)
    {
        output << std::endl;
    }

    output.close();
}
