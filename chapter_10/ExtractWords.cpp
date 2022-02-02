// Listing 10.1 - ExtractWords.cpp
#include <iostream>
#include <sstream>
#include <string>

int main()
{
    std::string text("Programming is fun");
    std::stringstream ss(text);
    std::cout << "The words in the text are " << std::endl;
    std::string word;
    while (!ss.eof())
    {
        ss >> word;
        std::cout << word << std::endl;
    }

    return 0;
}