#include <iostream>
#include <string>

int returnCents(std::string cents)
{
    std::string numbers[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    int value = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (cents.substr(i, 1).compare(numbers[j]) == 0)
            {
                value = value * 10 + j;
            }
        }
    }
    return value;
}

int main()
{
    // Receive the amount
    std::cout << "Enter an amount in double, for example 11.56: ";
    std::string amount, dollars, cents;
    std::cin >> amount;
    dollars = amount.substr(0, amount.find("."));
    cents = amount.substr(amount.find(".") + 1, amount.length());

    int remainingAmount = returnCents(cents);
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
    std::cout << "Your amount " << amount << " consists of " << std::endl
              << "   " << dollars << " dollars" << std::endl
              << "   " << numberOfQuarters << " quarters" << std::endl
              << "   " << numberOfDimes << " dimes" << std::endl
              << "   " << numberOfNickels << " nickels" << std::endl
              << "   " << numberOfPennies << " pennies" << std::endl;

    return 0;
}