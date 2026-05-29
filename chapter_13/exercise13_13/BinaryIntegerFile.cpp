#include "BinaryIntegerFile.h"
#include <fstream>
#include <iostream>

BinaryIntegerFile::BinaryIntegerFile(const char *filename, int size)
{
    this->filename = filename;
    this->size = size;
    numbers = new int[size];
    inputNumbers = new int[size];
}

BinaryIntegerFile::~BinaryIntegerFile()
{
    delete[] numbers;
    delete[] inputNumbers;
}

int BinaryIntegerFile::run()
{
    readFromKeyboard();
    writeFile();
    readFile();
    display();

    return 0;
}

void BinaryIntegerFile::readFromKeyboard()
{
    std::cout << "Enter five integers: ";

    for (int i = 0; i < size; i++)
    {
        std::cin >> numbers[i];
    }
}

void BinaryIntegerFile::writeFile() const
{
    std::ofstream output(filename, std::ios::binary);
    output.write((char *)numbers, sizeof(int) * size);
    output.close();
}

void BinaryIntegerFile::readFile()
{
    std::ifstream input(filename, std::ios::binary);
    input.read((char *)inputNumbers, sizeof(int) * size);
    input.close();
}

void BinaryIntegerFile::display() const
{
    std::cout << "The integers read from " << filename << " are: ";

    for (int i = 0; i < size; i++)
    {
        std::cout << inputNumbers[i] << " ";
    }

    std::cout << std::endl;
}
