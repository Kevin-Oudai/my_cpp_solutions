#include <iostream>

int main()
{
    // Receive the amount
    std::cout << "Enter an amount of money as an integer where the last 2 digits represent the cents: ";
    int remainingAmount;
    std::cin >> remainingAmount;
    double amount = remainingAmount / 100.0;

    // Find the number of one dollars
    int numberOfOneDollars = remainingAmount / 100;
    remainingAmount = remainingAmount % 100;

    // Find the number of quarters in the remaining amount
    int numberOfQuarters = remainingAmount / 25;
    remainingAmount = remainingAmount % 25;

    // Find the number of dimes in the remaining amount
    int numberOfDimes = remainingAmount / 10;
    remainingAmount = remainingAmount % 10;

    // Find the number of nickels in the remaining amount
    int numberOfNickels = remainingAmount / 5;
    remainingAmount = remainingAmount % 5;

    // Find the number of pennies in the remaining amount
    int numberOfPennies = remainingAmount;

    // Display results
    std::cout << "Your amount $" << amount << " consists of " << std::endl
              << "   " << numberOfOneDollars << " dollars" << std::endl
              << "   " << numberOfQuarters << " quarters" << std::endl
              << "   " << numberOfDimes << " dimes" << std::endl
              << "   " << numberOfNickels << " nickels" << std::endl
              << "   " << numberOfPennies << " pennies" << std::endl;

    return 0;
}