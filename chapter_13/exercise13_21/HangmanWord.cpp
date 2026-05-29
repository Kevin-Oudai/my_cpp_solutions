#include "HangmanWord.h"
#include <iostream>

HangmanWord::HangmanWord(const std::string &word)
{
    size = word.length();
    guessedSize = 0;
    missCount = 0;
    letters = new char[size];
    displayLetters = new char[size];
    guessedLetters = new char[100];

    for (int i = 0; i < size; i++)
    {
        letters[i] = word.at(i);
        displayLetters[i] = '*';
    }
}

HangmanWord::~HangmanWord()
{
    delete[] letters;
    delete[] displayLetters;
    delete[] guessedLetters;
}

void HangmanWord::display() const
{
    for (int i = 0; i < size; i++)
    {
        std::cout << displayLetters[i];
    }
}

void HangmanWord::guess(char letter)
{
    bool found = false;

    guessedLetters[guessedSize] = letter;
    guessedSize++;

    for (int i = 0; i < size; i++)
    {
        if (letters[i] == letter)
        {
            displayLetters[i] = letter;
            found = true;
        }
    }

    if (!found)
    {
        missCount++;
    }
}

bool HangmanWord::isComplete() const
{
    for (int i = 0; i < size; i++)
    {
        if (displayLetters[i] == '*')
        {
            return false;
        }
    }

    return true;
}

bool HangmanWord::wasGuessed(char letter) const
{
    for (int i = 0; i < guessedSize; i++)
    {
        if (guessedLetters[i] == letter)
        {
            return true;
        }
    }

    return false;
}

bool HangmanWord::wasIncorrect(char letter) const
{
    for (int i = 0; i < size; i++)
    {
        if (letters[i] == letter)
        {
            return false;
        }
    }

    return true;
}

int HangmanWord::getMisses() const
{
    return missCount;
}
