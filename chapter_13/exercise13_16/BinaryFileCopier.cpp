#include "BinaryFileCopier.h"
#include <fstream>
#include <iostream>

BinaryFileCopier::BinaryFileCopier(int bufferSize)
{
    this->bufferSize = bufferSize;
    buffer = new char[bufferSize];
}

BinaryFileCopier::~BinaryFileCopier()
{
    delete[] buffer;
}

int BinaryFileCopier::run()
{
    std::string sourceFilename;
    std::string targetFilename;

    std::cout << "Enter a source file name: ";
    std::cin >> sourceFilename;
    std::cout << "Enter a target file name: ";
    std::cin >> targetFilename;

    if (!copyFile(sourceFilename, targetFilename))
    {
        return 0;
    }

    std::cout << "Copy Done" << std::endl;
    return 0;
}

bool BinaryFileCopier::copyFile(const std::string &sourceFilename,
                                const std::string &targetFilename)
{
    std::ifstream input(sourceFilename.c_str(), std::ios::binary);
    if (input.fail())
    {
        std::cout << sourceFilename << " does not exist" << std::endl;
        return false;
    }

    std::ofstream output(targetFilename.c_str(), std::ios::binary);

    while (!input.eof())
    {
        input.read(buffer, bufferSize);
        output.write(buffer, input.gcount());
    }

    input.close();
    output.close();

    return true;
}
