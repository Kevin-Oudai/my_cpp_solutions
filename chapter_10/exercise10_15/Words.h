#ifndef WORDS_H
#define WORDS_H
#include <string>
#include "StackOfCharacters.h"

class Words
{
public:
    Words(std::string word);
    void displayWord();
    void guessLetter(char letter);
    bool wordComplete();
    int getSize();
    int getGuesses();
    bool correctLetter(char letter);
    bool incorrectLetter(char letter);

private:
    char elements[100];
    StackOfCharacters correct;
    StackOfCharacters incorrect;
    int size;
    char word[100];
    int guesses = 0;
};

#endif