// Exercise 7.4 - Count the number of Vowels and Consonants

#include <iostream>

bool letterIsVowel(char vowels[], char vowel)
{

    for (int i = 0; i < 10; i++)
    {
        if (vowel == vowels[i])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    char vowels[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int vowelCount = 0, consonantCount = 0, letterValue = 0;
    std::cout << "Enter a letters (input stops with 0): ";
    char letter;
    do
    {
        std::cin >> letter;
        letterValue = static_cast<int>(letter);
        if ((letter >= 65 && letter <= 90) || (letter >= 97 && letter <= 122))
        {
            letterIsVowel(vowels, letter)
                ? vowelCount++
                : consonantCount++;
        }

    } while (letter != '0');

    std::cout << "Number of vowels: " << vowelCount << std::endl;
    std::cout << "Number of consonants: " << consonantCount << std::endl;
    return 0;
}