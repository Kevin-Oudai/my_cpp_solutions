#include "../ContainerUtilities.h"
#include <fstream>
#include <iostream>
#include <set>
#include <string>

int main()
{
    std::ifstream input("words.txt");
    std::multiset<std::string> words;
    std::string word;

    while (input >> word)
    {
        word = exercise22::cleanWord(word);
        if (!word.empty())
            words.insert(word);
    }

    std::cout << "Words with duplicates: ";
    exercise22::printContainer(words);

    return 0;
}
