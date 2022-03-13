#include <iostream>
#include "Words.h"

int main()
{
    std::cout << "Testing Initialization..." << std::endl;
    Words word("hello");
    std::cout << "\tExpected size: 5" << std::endl;
    std::cout << "\tActual size: " << word.getSize() << std::endl;
    std::cout << "\n\tExpected guesses: 0" << std::endl;
    std::cout << "\tActual guesses: " << word.getGuesses() << "\n\n";

    std::cout << "Testing Functions..." << std::endl;

    std::cout << "\tdisplayWord()" << std::endl;
    std::cout << "\tExpected: *****\tActual: ";
    word.displayWord();

    std::cout << "\n\n\tguessLetter('l')" << std::endl;
    word.guessLetter('l');
    std::cout << "\tExpected: **ll*\tActual: ";
    word.displayWord();

    std::cout << "\n\n\tguessLetter('k')" << std::endl;
    word.guessLetter('k');
    std::cout << "\tExpected: guesses = 1\tActual: guesses = " << word.getGuesses() << std::endl;
    std::cout << "\tExpected: **ll*\tActual: ";
    word.displayWord();

    std::cout << "\n\n\twordComplete()" << std::endl;
    std::cout << "\tExpected: 0\tActual: " << word.wordComplete() << std::endl;
    word.guessLetter('h');
    word.guessLetter('e');
    word.guessLetter('o');
    std::cout << "\tExpected: 1\tActual: " << word.wordComplete() << std::endl;

    return 0;
}