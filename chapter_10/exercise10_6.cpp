#include <iostream>
#include <string>

bool isVowel(std::string letter)
{
    std::string vowels[10] = {"a", "e", "i", "o", "u", "A", "E", "I", "O", "U"};
    for (int i = 0; i < 10; i++)
    {
        if (letter.compare(vowels[i]) == 0)
        {
            std::cout << "letter: " << letter << "is a vowel." << std::endl;
            return true;
        }
    }
    return false;
}

int countVowels(const std::string &s)
{
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (isVowel(s.substr(i, 1)))
        {
            count++;
        }
    }
    return count;
}

int main()
{
    std::string line;
    std::cout << "Enter a string s: ";
    std::cin >> line;
    int vowels = countVowels(line);
    std::cout << line << "\n has " << vowels << " vowels." << std::endl;
    return 0;
}