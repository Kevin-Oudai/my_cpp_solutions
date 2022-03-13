#include <iostream>
#include <string>
#include "Words.h"

Words::Words(std::string gameWord)
{
    size = gameWord.length();
    for (int i = 0; i < size; i++)
    {
        word[i] = gameWord.at(i);
        elements[i] = '*';
    }
}

void Words::displayWord()
{
    for (int i = 0; i < size; i++)
    {
        std::cout << elements[i];
    }
}

void Words::guessLetter(char letter)
{
    bool letterDiscovered = false;
    for (int i = 0; i < size; i++)
    {
        if (word[i] == letter)
        {
            elements[i] = letter;
            letterDiscovered = true;
            correct.push(letter);
        }
    }
    if (!letterDiscovered)
    {
        guesses++;
        incorrect.push(letter);
    }
}

bool Words::wordComplete()
{
    bool isComplete = true;
    for (int i = 0; i < size; i++)
    {
        if (elements[i] == '*')
        {
            isComplete = false;
        }
    }
    return isComplete;
}

int Words::getSize()
{
    return size;
}

int Words::getGuesses()
{
    return guesses;
}

bool Words::correctLetter(char letter)
{
    return correct.elementInStack(letter);
}

bool Words::incorrectLetter(char letter)
{
    return incorrect.elementInStack(letter);
}