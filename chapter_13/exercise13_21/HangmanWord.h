#ifndef HANGMANWORD_H
#define HANGMANWORD_H

#include <string>

class HangmanWord
{
public:
    HangmanWord(const std::string &word);
    ~HangmanWord();
    void display() const;
    void guess(char letter);
    bool isComplete() const;
    bool wasGuessed(char letter) const;
    bool wasIncorrect(char letter) const;
    int getMisses() const;

private:
    int size;
    int guessedSize;
    int missCount;
    char *letters;
    char *displayLetters;
    char *guessedLetters;
};

#endif
