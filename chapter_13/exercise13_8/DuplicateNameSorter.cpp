#include "DuplicateNameSorter.h"
#include <fstream>
#include <iostream>
#include <sstream>

DuplicateNameSorter::DuplicateNameSorter(int capacity, const char *outputFilename)
{
    this->capacity = capacity;
    this->outputFilename = outputFilename;
    size = 0;
    names = new std::string[capacity];
}

DuplicateNameSorter::~DuplicateNameSorter()
{
    delete[] names;
}

int DuplicateNameSorter::run()
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

std::string DuplicateNameSorter::getFilename(int year) const
{
    std::ostringstream filename;
    filename << "Babynameranking" << year << ".txt";
    return filename.str();
}

void DuplicateNameSorter::addName(const std::string &name)
{
    if (size < capacity)
    {
        names[size] = name;
        size++;
    }
}

bool DuplicateNameSorter::readNames()
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

void DuplicateNameSorter::sortNames()
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

void DuplicateNameSorter::writeNames() const
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
