#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter a string with five lowercase letters: ";
    std::string word;
    std::getline(std::cin, word);

    if (word.length() <= 5)
    {
        if (word[0] == word[4] && word[1] == word[3])
        {
            std::cout << word << " is a palindrome." << std::endl;
        }
        else
            std::cout << word << " is NOT a palindrome." << std::endl;
    }
    else
        std::cout << word << " is not the correct length." << std::endl;

    return 0;
}