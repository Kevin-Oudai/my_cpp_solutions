#include <iostream>

int main()
{
    double US_TO_RMB;
    std::cout << "Enter the exchange rate from dollars to RMB: ";
    std::cin >> US_TO_RMB;

    int choice;
    std::cout << "Enter 0 to convert dollars to RMB and 1 vice versa: ";
    std::cin >> choice;

    double dollar, rmb;
    if (choice == 0)
    {
        std::cout << "Enter the dollar amount: ";
        std::cin >> dollar;
        std::cout << "$" << dollar << " is " << dollar * US_TO_RMB << " yuan." << std::endl;
    }
    else if (choice == 1)
    {
        std::cout << "Enter the RMB amount: ";
        std::cin >> rmb;
        std::cout << rmb << " yuan is $" << rmb / US_TO_RMB << "." << std::endl;
    }
    else
    {
        std::cout << "Incorrect input" << std::endl;
    }

    return 0;
}