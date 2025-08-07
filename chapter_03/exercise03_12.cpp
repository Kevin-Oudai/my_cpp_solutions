#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
    srand(time(0));
    int number = rand();

    std::cout << "Guess if the number is even(0) or odd(1): ";
    int choice;
    std::cin >> choice;

    if (number % 2 == choice)
    {
        std::cout << "Your choice is correct." << std::endl;
    }
    else if (number % 2 != choice)
    {
        std::cout << "Your choice is incorrect." << std::endl;
    }
    else
    {
        std::cout << "You made an invalid choice." << std::endl;
    }

    return 0;
}