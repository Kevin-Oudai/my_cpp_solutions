// Exercise 3.14 - Game: Prediction
#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
    // Variables
    int num, guess, n1, n2, g1, g2;
    srand(time(0));

    // Input
    // Accept a guess
    std::cout << "Enter a 2-digit guess: ";
    std::cin >> guess;

    // Process
    // Generate a random 2 digit number
    num = rand() % 100;
    // Extract the digits of the guess
    g1 = guess % 10;
    g2 = guess / 10;
    // Extract the digits of the random number
    n1 = num % 10;
    n2 = num / 10;

    // Output
    // Display for both digits matching
    if ((n1 == g1 && n2 == g2) || (n1 == g2 && n2 == g1))
        std::cout << "100% match" << std::endl;
    // Display for one digit matching
    else if ((n1 == g1 || n2 == g2) || (n1 == g2 || n2 == g1))
        std::cout << "50% match" << std::endl;
    // Display for no matches
    else
        std::cout << "0% match" << std::endl;

    return 0;
}