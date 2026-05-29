#include "BothGenderNameFinder.h"
#include <fstream>
#include <iostream>

BothGenderNameFinder::BothGenderNameFinder(int capacity)
{
    this->capacity = capacity;
    size = 0;
    bothGenderSize = 0;
    boyNames = new std::string[capacity];
    girlNames = new std::string[capacity];
    bothGenderNames = new std::string[capacity];
}

BothGenderNameFinder::~BothGenderNameFinder()
{
    delete[] boyNames;
    delete[] girlNames;
    delete[] bothGenderNames;
}

int BothGenderNameFinder::run()
{
    std::string filename;

    std::cout << "Enter a file name for baby name ranking: ";
    std::cin >> filename;

    if (!readNames(filename))
    {
        std::cout << filename << " does not exist" << std::endl;
        return 0;
    }

    findBothGenderNames();
    display();

    return 0;
}

bool BothGenderNameFinder::readNames(const std::string &filename)
{
    std::ifstream input(filename.c_str());
    if (input.fail())
    {
        return false;
    }

    int rank;
    std::string boyCount;
    std::string girlCount;

    while (size < capacity &&
           input >> rank >> boyNames[size] >> boyCount >> girlNames[size] >> girlCount)
    {
        size++;
    }

    input.close();
    return true;
}

bool BothGenderNameFinder::contains(const std::string *list, int size,
                                    const std::string &name) const
{
    for (int i = 0; i < size; i++)
    {
        if (list[i] == name)
        {
            return true;
        }
    }

    return false;
}

void BothGenderNameFinder::findBothGenderNames()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (boyNames[i] == girlNames[j] &&
                !contains(bothGenderNames, bothGenderSize, boyNames[i]))
            {
                bothGenderNames[bothGenderSize] = boyNames[i];
                bothGenderSize++;
            }
        }
    }
}

void BothGenderNameFinder::display() const
{
    std::cout << bothGenderSize << " names used for both genders" << std::endl;
    std::cout << "They are ";

    for (int i = 0; i < bothGenderSize; i++)
    {
        std::cout << bothGenderNames[i] << " ";
    }

    std::cout << std::endl;
}
