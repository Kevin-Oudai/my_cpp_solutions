#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Words.h"

int main()
{
    srand(time(0));
    bool gameFinished = false;
    std::cout << "Lets play hangman..." << std::endl;
    std::string words[] = {
        "hello",
        "kevin",
        "mascot",
        "dreams",
        "topic",
        "athena",
        "venita",
        "tropical",
        "sawdust",
        "roulette",
        "trees"};
    int index;
    while (!gameFinished)
    {
        index = rand() % 11;
        Words word(words[index]);
        while (!word.wordComplete())
        {
            std::cout << "(Guess) Enter a letter in word ";
            word.displayWord();
            std::cout << " > ";
            char guess;
            std::cin >> guess;
            if (word.correctLetter(guess))
            {
                std::cout << guess << " is already in the word." << std::endl;
            }
            else
            {
                word.guessLetter(guess);
            }
            if (word.incorrectLetter(guess))
            {
                std::cout << guess << " is NOT in word." << std::endl;
            }
        }
        std::cout << "The word is ";
        word.displayWord();
        std::cout << ". You missed " << word.getGuesses() << " time(s)." << std::endl;
        std::cout << "Would you like to play again?" << std::endl;
        char answer;
        std::cin >> answer;
        if (answer == 'n' || answer == 'N')
        {
            gameFinished = true;
        }
    }

    return 0;
}