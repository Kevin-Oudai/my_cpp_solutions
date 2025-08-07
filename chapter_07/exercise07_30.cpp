// Exercise 7.30 - Replace: space with underscore
#include <iostream>
#include <string>

int main()
{
    std::string words;
    std::cout << "Enter a string: ";
    std::getline(std::cin, words);
    for (int i = 0; i < words.length(); i++)
    {
        if (words[i] == ' ')
        {
            words[i] = '_';
        }
    }
    std::cout << words << std::endl;
    return 0;
}