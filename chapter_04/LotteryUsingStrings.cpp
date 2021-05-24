// Listing 4.8 - LotteryUsingStrings.cpp

#include <iostream>
#include <string>  // for using strings
#include <ctime>   // for using time
#include <cstdlib> // for rand and srand functions

int main()
{
    std::string lottery;
    srand(time(0));
    int digit = rand() % 10; // Generate first digit
    lottery += static_cast<char>(digit + '0');
    digit = rand() % 10; // Generate second digit
    lottery += static_cast<char>(digit + '0');

    // Prompt the user to enter a guess
    std::cout << "Enter your lottery pick (two digits): ";
    std::string guess;
    std::cin >> guess;

    std::cout << "The lotter number is " << lottery << std::endl;

    // Check the guess
    if (guess == lottery)
        std::cout << "Exact match: you win $10,000" << std::endl;
    else if (guess[1] == lottery[0] && guess[0] == lottery[1])
    {
        std::cout << "Match all digits: you win $3,000" << std::endl;
    }
    else if (guess[0] == lottery[0] || guess[0] == lottery[1] || guess[1] == lottery[0] || guess[1] == lottery[1])
    {
        std::cout << "Match one digit: you win $1,000" << std::endl;
    }
    else
        std::cout << "Sorry, no match" << std::endl;

    return 0;
}