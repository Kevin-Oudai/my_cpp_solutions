// Exercise 3.15 - Game: Scissor, Rock, Paper
#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
    // Input
    // Get the user choice
    std::cout << "scissor (0), rock (1), paper (2): ";
    int userChoice;
    std::cin >> userChoice;

    // Process
    // Generate computer choice randomly
    srand(time(0));
    int choice = rand() % 3;
    // User choose paper
    if (userChoice == 0)
    {
        if (choice == 0)
        {
            std::cout << "The computer is scissor. You are scissor. It is a draw." << std::endl;
        }
        else if (choice == 1)
        {
            std::cout << "The computer is rock. You are scissor. You lost." << std::endl;
        }
        else
            std::cout << "The computer is paper. You are scissor. You Won." << std::endl;
    }
    // User choose rock
    else if (userChoice == 1)
    {
        if (choice == 0)
        {
            std::cout << "The computer is scissor. You are rock. You won." << std::endl;
        }
        else if (choice == 1)
        {
            std::cout << "The computer is rock. You are rock. It is a draw." << std::endl;
        }
        else
            std::cout << "The computer is paper. You are rock. You lose." << std::endl;
    }
    // User choose scissor
    else if (userChoice == 2)
    {
        if (choice == 0)
        {
            std::cout << "The computer is scissor. You are paper. You lose." << std::endl;
        }
        else if (choice == 1)
        {
            std::cout << "The computer is rock. You are paper. You won." << std::endl;
        }
        else
            std::cout << "The computer is paper. You are paper. It is a draw." << std::endl;
    }
    else
        std::cout << "An error occured" << std::endl;

    return 0;
}