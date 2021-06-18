// Exercise 5.53 - Count Vowels and Consonants
#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter a string: ";
    std::string message;
    std::getline(std::cin, message);

    int count = message.length(), vowelCount = 0, consonantCount = 0;
    for (int i = 0; i < count; i++)
    {
        if (
            message.at(i) == 'A' || message.at(i) == 'a' ||
            message.at(i) == 'E' || message.at(i) == 'e' ||
            message.at(i) == 'I' || message.at(i) == 'i' ||
            message.at(i) == 'O' || message.at(i) == 'o' ||
            message.at(i) == 'U' || message.at(i) == 'u')
            vowelCount++;
        else if (isalpha(message.at(i)))
        {
            consonantCount++;
        }
        else
        {
            continue;
        }
    }
    std::cout << "The number of vowels is " << vowelCount << std::endl;
    std::cout << "The number of consonants is " << consonantCount << std::endl;
    return 0;
}