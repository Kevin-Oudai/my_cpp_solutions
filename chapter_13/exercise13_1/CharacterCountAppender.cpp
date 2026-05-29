#include "CharacterCountAppender.h"
#include <fstream>
#include <iostream>

CharacterCountAppender::CharacterCountAppender(const char *filename)
{
    this->filename = filename;
}

int CharacterCountAppender::run() const
{
    bool fileExists = false;
    int count = countCharacters(fileExists);

    if (!fileExists)
    {
        std::cout << filename << " does not exist" << std::endl;
        return 0;
    }

    appendCount(count);

    std::cout << "Number of characters: " << count << std::endl;
    return 0;
}

int CharacterCountAppender::countCharacters(bool &fileExists) const
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
        count++;
    }

    input.close();
    return count;
}

void CharacterCountAppender::appendCount(int count) const
{
    std::ofstream output(filename, std::ios::app);
    output << std::endl
           << "Number of characters: " << count << std::endl;
    output.close();
}
