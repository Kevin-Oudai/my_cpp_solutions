#include <cctype>
#include <fstream>
#include <iostream>
#include <set>
#include <string>

int main()
{
    std::string fileName;
    std::cout << "Enter a text file name: ";

    if (!(std::cin >> fileName))
        fileName = "text.txt";

    std::ifstream input(fileName.c_str());
    if (!input)
    {
        std::cout << "Cannot open " << fileName << std::endl;
        return 0;
    }

    std::set<char> vowels;
    vowels.insert('A');
    vowels.insert('E');
    vowels.insert('I');
    vowels.insert('O');
    vowels.insert('U');

    int vowelCount = 0;
    int consonantCount = 0;
    char ch;

    while (input.get(ch))
    {
        if (std::isalpha(static_cast<unsigned char>(ch)))
        {
            char upper = static_cast<char>(std::toupper(static_cast<unsigned char>(ch)));
            if (vowels.find(upper) != vowels.end())
                vowelCount++;
            else
                consonantCount++;
        }
    }

    std::cout << "Vowels: " << vowelCount << std::endl;
    std::cout << "Consonants: " << consonantCount << std::endl;

    return 0;
}
