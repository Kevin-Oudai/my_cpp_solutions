// Listing 7.8 - CountLettersInArray.cpp
#include <iostream>
#include <ctime>

const int NUMBER_OF_LETTERS = 26;
const int NUMBER_OF_RANDOM_LETTERS = 100;
void createArray(char[]);
void displayArray(const char[]);
void countLetters(const char[], int[]);
void displayCounts(const int[]);

int main()
{
    char chars[NUMBER_OF_RANDOM_LETTERS];

    createArray(chars);

    std::cout << "The lowercase letters are: " << std::endl;
    displayArray(chars);
    int counts[NUMBER_OF_LETTERS];
    countLetters(chars, counts);

    std::cout << "\nThe occurrences of each letter are: " << std::endl;
    displayCounts(counts);

    return 0;
}

void createArray(char chars[])
{
    srand(time(0));
    for (int i = 0; i < NUMBER_OF_RANDOM_LETTERS; i++)
    {
        chars[i] = static_cast<char>('a' + rand() % ('z' - 'a' + 1));
    }
}

void displayArray(const char chars[])
{
    for (int i = 0; i < NUMBER_OF_RANDOM_LETTERS; i++)
    {
        if ((i + 1) % 20 == 0)
        {
            std::cout << chars[i] << " " << std::endl;
        }
        else
        {
            std::cout << chars[i] << " ";
        }
    }
}

void countLetters(const char chars[], int counts[])
{
    for (int i = 0; i < NUMBER_OF_LETTERS; i++)
    {
        counts[i] = 0;
    }

    for (int i = 0; i < NUMBER_OF_RANDOM_LETTERS; i++)
    {
        counts[chars[i] - 'a']++;
    }
}

void displayCounts(const int counts[])
{
    for (int i = 0; i < NUMBER_OF_LETTERS; i++)
    {
        if ((i + 1) % 10 == 0)
        {
            std::cout << counts[i] << " " << static_cast<char>(i + 'a') << std::endl;
        }
        else
            std::cout << counts[i] << " " << static_cast<char>(i + 'a') << " ";
    }
}