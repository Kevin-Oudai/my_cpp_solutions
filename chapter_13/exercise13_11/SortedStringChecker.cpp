#include "SortedStringChecker.h"
#include <fstream>
#include <iostream>

SortedStringChecker::SortedStringChecker(const char *filename)
{
    this->filename = filename;
}

int SortedStringChecker::run() const
{
    bool fileExists = false;
    std::string first;
    std::string second;
    bool sorted = isSorted(fileExists, first, second);

    if (!fileExists)
    {
        std::cout << filename << " does not exist" << std::endl;
        return 0;
    }

    if (sorted)
    {
        std::cout << "The strings are sorted in ascending order." << std::endl;
    }
    else
    {
        std::cout << "The strings are not sorted in ascending order." << std::endl;
        std::cout << "The first two out-of-order strings are "
                  << first << " and " << second << std::endl;
    }

    return 0;
}

bool SortedStringChecker::isSorted(bool &fileExists, std::string &first,
                                   std::string &second) const
{
    std::ifstream input(filename);
    if (input.fail())
    {
        fileExists = false;
        return false;
    }

    fileExists = true;
    std::string previous;
    std::string current;

    if (input >> previous)
    {
        while (input >> current)
        {
            if (previous > current)
            {
                first = previous;
                second = current;
                input.close();
                return false;
            }

            previous = current;
        }
    }

    input.close();
    return true;
}
