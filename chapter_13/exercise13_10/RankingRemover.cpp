#include "RankingRemover.h"
#include <fstream>
#include <iostream>

int RankingRemover::run() const
{
    std::string filename;
    std::string newFilename;

    std::cout << "Enter a file name for baby name ranking: ";
    std::cin >> filename;

    if (!removeRanking(filename, newFilename))
    {
        std::cout << filename << " does not exist" << std::endl;
        return 0;
    }

    std::cout << "The new file is " << newFilename << std::endl;
    return 0;
}

bool RankingRemover::removeRanking(const std::string &filename,
                                   std::string &newFilename) const
{
    std::ifstream input(filename.c_str());
    if (input.fail())
    {
        return false;
    }

    newFilename = filename + ".new";
    std::ofstream output(newFilename.c_str());

    int rank;
    std::string boyName;
    std::string boyCount;
    std::string girlName;
    std::string girlCount;

    while (input >> rank >> boyName >> boyCount >> girlName >> girlCount)
    {
        output << boyName << " " << boyCount << " "
               << girlName << " " << girlCount << std::endl;
    }

    input.close();
    output.close();
    return true;
}
