#include "RankingSummary.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

RankingSummary::RankingSummary(int rankCount)
{
    this->rankCount = rankCount;
    boyNames = new std::string[rankCount];
    girlNames = new std::string[rankCount];
}

RankingSummary::~RankingSummary()
{
    delete[] boyNames;
    delete[] girlNames;
}

int RankingSummary::run()
{
    displayHeader();

    for (int year = 2010; year >= 2001; year--)
    {
        if (!readYear(year))
        {
            return 0;
        }

        displayYear(year);
    }

    return 0;
}

std::string RankingSummary::getFilename(int year) const
{
    std::ostringstream filename;
    filename << "Babynameranking" << year << ".txt";
    return filename.str();
}

void RankingSummary::displayHeader() const
{
    std::cout << std::left << std::setw(8) << "Year";

    for (int i = 1; i <= rankCount; i++)
    {
        std::ostringstream label;
        label << "Rank " << i;
        std::cout << std::setw(12) << label.str();
    }

    for (int i = 1; i <= rankCount; i++)
    {
        std::ostringstream label;
        label << "Rank " << i;
        std::cout << std::setw(12) << label.str();
    }

    std::cout << std::endl;
}

bool RankingSummary::readYear(int year)
{
    std::string filename = getFilename(year);
    std::ifstream input(filename.c_str());

    if (input.fail())
    {
        std::cout << filename << " does not exist" << std::endl;
        return false;
    }

    int rank;
    std::string boyCount;
    std::string girlCount;

    for (int i = 0; i < rankCount; i++)
    {
        input >> rank >> boyNames[i] >> boyCount >> girlNames[i] >> girlCount;
    }

    input.close();
    return true;
}

void RankingSummary::displayYear(int year) const
{
    std::cout << std::left << std::setw(8) << year;

    for (int i = 0; i < rankCount; i++)
    {
        std::cout << std::setw(12) << girlNames[i];
    }

    for (int i = 0; i < rankCount; i++)
    {
        std::cout << std::setw(12) << boyNames[i];
    }

    std::cout << std::endl;
}
