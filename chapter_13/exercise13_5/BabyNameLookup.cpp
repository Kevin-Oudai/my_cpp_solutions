#include "BabyNameLookup.h"
#include <fstream>
#include <iostream>
#include <sstream>

int BabyNameLookup::run() const
{
    int year;
    char gender;
    std::string name;

    std::cout << "Enter the year: ";
    std::cin >> year;
    std::cout << "Enter the gender: ";
    std::cin >> gender;
    std::cout << "Enter the name: ";
    std::cin >> name;

    std::string filename = getFilename(year);
    bool fileExists = false;
    int rank = findRank(filename, gender, name, fileExists);

    if (!fileExists)
    {
        std::cout << filename << " does not exist" << std::endl;
        return 0;
    }

    if (rank != -1)
    {
        std::cout << name << " is ranked #" << rank
                  << " in year " << year << std::endl;
    }
    else
    {
        std::cout << "The name " << name << " is not ranked in year "
                  << year << std::endl;
    }

    return 0;
}

std::string BabyNameLookup::getFilename(int year) const
{
    std::ostringstream filename;
    filename << "Babynameranking" << year << ".txt";
    return filename.str();
}

int BabyNameLookup::findRank(const std::string &filename, char gender,
                             const std::string &name, bool &fileExists) const
{
    std::ifstream input(filename.c_str());
    if (input.fail())
    {
        fileExists = false;
        return -1;
    }

    fileExists = true;
    int rank;
    std::string boyName;
    std::string boyCount;
    std::string girlName;
    std::string girlCount;

    while (input >> rank >> boyName >> boyCount >> girlName >> girlCount)
    {
        if ((gender == 'M' || gender == 'm') && boyName == name)
        {
            input.close();
            return rank;
        }

        if ((gender == 'F' || gender == 'f') && girlName == name)
        {
            input.close();
            return rank;
        }
    }

    input.close();
    return -1;
}
