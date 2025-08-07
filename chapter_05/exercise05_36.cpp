// Exercise 5.36 - Revision of Exercise 3.15 - Game: Scissor, Rock, Paper
#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
    // Input
    // Get the user choice

    int userChoice;
    int userWin = 0, compWin = 0, draw = 0, badInput = 0;

    // Process
    // Generate computer choice randomly
    srand(time(0));
    int choice = 0;
    for (int i = 0; i < 10; i++)
    {
        std::cout << "scissor (0), rock (1), paper (2): ";
        std::cin >> userChoice;
        choice = rand() % 3;
        // User choose paper
        if (userChoice == 0)
        {
            if (choice == 0)
            {
                std::cout << "The computer is scissor. You are scissor. It is a draw." << std::endl;
                draw++;
            }
            else if (choice == 1)
            {
                std::cout << "The computer is rock. You are scissor. You lost." << std::endl;
                compWin++;
            }
            else
            {
                std::cout << "The computer is paper. You are scissor. You Won." << std::endl;
                userWin++;
            }
        }
        // User choose rock
        else if (userChoice == 1)
        {
            if (choice == 0)
            {
                std::cout << "The computer is scissor. You are rock. You won." << std::endl;
                userWin++;
            }
            else if (choice == 1)
            {
                std::cout << "The computer is rock. You are rock. It is a draw." << std::endl;
                draw++;
            }
            else
            {
                std::cout << "The computer is paper. You are rock. You lose." << std::endl;
                compWin++;
            }
        }
        // User choose scissor
        else if (userChoice == 2)
        {
            if (choice == 0)
            {
                std::cout << "The computer is scissor. You are paper. You lose." << std::endl;
                compWin++;
            }
            else if (choice == 1)
            {
                std::cout << "The computer is rock. You are paper. You won." << std::endl;
                userWin++;
            }
            else
            {
                std::cout << "The computer is paper. You are paper. It is a draw." << std::endl;
                draw++;
            }
        }
        else
        {
            std::cout << "An error occured" << std::endl;
            badInput++;
        }
    }
    std::cout << "Game Summary" << std::endl;
    std::cout << "++++++++++++" << std::endl;
    std::cout << "Games Won: " << userWin << std::endl;
    std::cout << "Games Lost: " << compWin << std::endl;
    std::cout << "Games Drawn: " << draw << std::endl;
    std::cout << "Bad Inputs: " << badInput << std::endl;
    return 0;
}