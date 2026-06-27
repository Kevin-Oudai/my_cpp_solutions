#include "../ContainerUtilities.h"
#include <iostream>
#include <string>

int main()
{
    std::string fileName;
    std::cout << "Enter a C++ source file name: ";

    if (!(std::cin >> fileName))
        fileName = "SampleCode.txt";

    int count = exercise22::countCppKeywordsInFile(fileName);

    if (count < 0)
        std::cout << "Cannot open " << fileName << std::endl;
    else
        std::cout << "The number of keywords is " << count << std::endl;

    return 0;
}
