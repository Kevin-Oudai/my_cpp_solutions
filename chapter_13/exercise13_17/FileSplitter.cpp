#include "FileSplitter.h"
#include <fstream>
#include <iostream>
#include <sstream>

int FileSplitter::run() const
{
    std::string sourceFilename;
    int bytesPerFile;

    std::cout << "Enter a source file name: ";
    std::cin >> sourceFilename;
    std::cout << "Enter the number of bytes in each smaller file: ";
    std::cin >> bytesPerFile;

    if (bytesPerFile <= 0)
    {
        std::cout << "The number of bytes must be positive" << std::endl;
        return 0;
    }

    if (!splitFile(sourceFilename, bytesPerFile))
    {
        return 0;
    }

    std::cout << "Split Done" << std::endl;
    return 0;
}

bool FileSplitter::splitFile(const std::string &sourceFilename,
                             int bytesPerFile) const
{
    std::ifstream input(sourceFilename.c_str(), std::ios::binary);
    if (input.fail())
    {
        std::cout << sourceFilename << " does not exist" << std::endl;
        return false;
    }

    char *buffer = new char[bytesPerFile];
    int fileNumber = 0;

    while (!input.eof())
    {
        input.read(buffer, bytesPerFile);
        int bytesRead = input.gcount();

        if (bytesRead > 0)
        {
            std::string outputFilename = getOutputFilename(sourceFilename, fileNumber);
            std::ofstream output(outputFilename.c_str(), std::ios::binary);
            output.write(buffer, bytesRead);
            output.close();

            std::cout << "File " << outputFilename << " produced" << std::endl;
            fileNumber++;
        }
    }

    delete[] buffer;
    input.close();

    return true;
}

std::string FileSplitter::getOutputFilename(const std::string &sourceFilename,
                                            int fileNumber) const
{
    std::ostringstream outputFilename;
    outputFilename << sourceFilename << "." << fileNumber;
    return outputFilename.str();
}
