#include "../ContainerUtilities.h"
#include <fstream>
#include <iostream>
#include <map>
#include <string>

int main()
{
    std::string fileName;
    std::cout << "Enter a file name: ";

    if (!(std::cin >> fileName))
        fileName = "words.txt";

    std::ifstream input(fileName.c_str());
    if (!input)
    {
        std::cout << "Cannot open " << fileName << std::endl;
        return 0;
    }

    std::map<std::string, int> counts;
    std::string word;

    while (input >> word)
    {
        word = exercise22::cleanWord(word);
        if (!word.empty())
            counts[word]++;
    }

    for (std::map<std::string, int>::iterator iterator = counts.begin(); iterator != counts.end(); iterator++)
        std::cout << "number of occurrences for " << iterator->first << " is " << iterator->second << std::endl;

    return 0;
}
