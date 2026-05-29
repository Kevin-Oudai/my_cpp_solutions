#include "FileDecryptor.h"
#include <fstream>
#include <iostream>

int FileDecryptor::run() const
{
    std::string inputFilename;
    std::string outputFilename;

    std::cout << "Enter an encrypted file name: ";
    std::cin >> inputFilename;
    std::cout << "Enter an output file name: ";
    std::cin >> outputFilename;

    if (!decryptFile(inputFilename, outputFilename))
    {
        return 0;
    }

    std::cout << "Decryption Done" << std::endl;
    return 0;
}

bool FileDecryptor::decryptFile(const std::string &inputFilename,
                                const std::string &outputFilename) const
{
    std::ifstream input(inputFilename.c_str(), std::ios::binary);
    if (input.fail())
    {
        std::cout << inputFilename << " does not exist" << std::endl;
        return false;
    }

    std::ofstream output(outputFilename.c_str(), std::ios::binary);
    char ch;
    int index = 0;

    while (input.get(ch))
    {
        unsigned char byte = ch;
        byte = byte - index;
        output.put((char)byte);
        index++;
    }

    input.close();
    output.close();

    return true;
}
