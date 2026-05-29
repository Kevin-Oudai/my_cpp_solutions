#include "FileCombiner.h"
#include <fstream>
#include <iostream>

int FileCombiner::run() const
{
    int numberOfFiles;

    std::cout << "Enter the number of source files: ";
    std::cin >> numberOfFiles;

    if (numberOfFiles <= 0)
    {
        std::cout << "The number of source files must be positive" << std::endl;
        return 0;
    }

    std::string *sourceFilenames = new std::string[numberOfFiles];

    for (int i = 0; i < numberOfFiles; i++)
    {
        std::cout << "Enter a source file: ";
        std::cin >> sourceFilenames[i];
    }

    std::string targetFilename;
    std::cout << "Enter a target file: ";
    std::cin >> targetFilename;

    if (combineFiles(sourceFilenames, numberOfFiles, targetFilename))
    {
        std::cout << "Combine Done" << std::endl;
    }

    delete[] sourceFilenames;
    return 0;
}

bool FileCombiner::combineFiles(std::string *sourceFilenames, int numberOfFiles,
                                const std::string &targetFilename) const
{
    std::ofstream output(targetFilename.c_str(), std::ios::binary);

    for (int i = 0; i < numberOfFiles; i++)
    {
        std::ifstream input(sourceFilenames[i].c_str(), std::ios::binary);

        if (input.fail())
        {
            std::cout << sourceFilenames[i] << " does not exist" << std::endl;
            output.close();
            return false;
        }

        copyOneFile(input, output);
        input.close();
    }

    output.close();
    return true;
}

bool FileCombiner::copyOneFile(std::ifstream &input, std::ofstream &output) const
{
    char ch;

    while (input.get(ch))
    {
        output.put(ch);
    }

    return true;
}
