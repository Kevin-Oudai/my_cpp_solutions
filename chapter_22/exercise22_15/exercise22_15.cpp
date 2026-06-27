#include "../ContainerUtilities.h"
#include <iostream>
#include <map>
#include <string>

int main()
{
    std::string fileName;
    std::cout << "Enter a C++ source file name: ";

    if (!(std::cin >> fileName))
        fileName = "SampleCode.txt";

    std::map<std::string, int> counts = exercise22::countEachCppKeywordInFile(fileName);

    if (counts.empty())
    {
        std::cout << "No keywords found or file could not be opened" << std::endl;
        return 0;
    }

    for (std::map<std::string, int>::iterator iterator = counts.begin(); iterator != counts.end(); iterator++)
        std::cout << iterator->first << " occurs " << iterator->second << " times" << std::endl;

    return 0;
}
