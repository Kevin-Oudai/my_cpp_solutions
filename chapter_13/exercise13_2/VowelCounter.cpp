#include "VowelCounter.h"
#include <fstream>
#include <iostream>

int VowelCounter::run() const
{
    char filename[80];

    std::cout << "Enter a filename: ";
    std::cin >> filename;

    bool fileExists = false;
    int count = countVowels(filename, fileExists);

    if (!fileExists)
    {
        std::cout << filename << " does not exist" << std::endl;
        return 0;
    }

    std::cout << "The number of vowels is " << count << std::endl;
    return 0;
}

int VowelCounter::countVowels(const char *filename, bool &fileExists) const
{
    std::ifstream input(filename);
    if (input.fail())
    {
        fileExists = false;
        return 0;
    }

    fileExists = true;
    int count = 0;
    char ch;

    while (input.get(ch))
    {
        if (isVowel(ch))
        {
            count++;
        }
    }

    input.close();
    return count;
}

bool VowelCounter::isVowel(char ch) const
{
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
           ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
}
