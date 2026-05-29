#include "HangmanGame.h"
#include "HangmanWord.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

HangmanGame::HangmanGame(const char *filename)
{
    this->filename = filename;
}

int HangmanGame::run() const
{
    std::vector<std::string> words;

    if (!readWords(words))
    {
        std::cout << filename << " does not exist" << std::endl;
        return 0;
    }

    if (words.size() == 0)
    {
        std::cout << filename << " does not contain any words" << std::endl;
        return 0;
    }

    std::srand(std::time(0));
    bool gameFinished = false;
    std::cout << "Lets play hangman..." << std::endl;

    while (!gameFinished)
    {
        playOneWord(getRandomWord(words));

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

bool HangmanGame::readWords(std::vector<std::string> &words) const
{
    std::ifstream input(filename);

    if (input.fail())
    {
        return false;
    }

    std::string word;
    while (input >> word)
    {
        words.push_back(word);
    }

    input.close();
    return true;
}

std::string HangmanGame::getRandomWord(const std::vector<std::string> &words) const
{
    int index = std::rand() % words.size();
    return words[index];
}

void HangmanGame::playOneWord(const std::string &word) const
{
    HangmanWord hangmanWord(word);

    while (!hangmanWord.isComplete())
    {
        std::cout << "(Guess) Enter a letter in word ";
        hangmanWord.display();
        std::cout << " > ";

        char guess;
        std::cin >> guess;

        if (hangmanWord.wasGuessed(guess))
        {
            std::cout << guess << " is already in the word." << std::endl;
        }
        else
        {
            hangmanWord.guess(guess);

            if (hangmanWord.wasIncorrect(guess))
            {
                std::cout << guess << " is NOT in word." << std::endl;
            }
        }
    }

    std::cout << "The word is ";
    hangmanWord.display();
    std::cout << ". You missed " << hangmanWord.getMisses()
              << " time(s)." << std::endl;
}
