#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(0));
    int number = rand() % 101;

    std::cout << "Guess a magic number between 0 and 100";

    std::cout << "\nEnter your guess: ";
    int guess;
    std::cin >> guess;

    if (guess == number)
        std::cout << "Yes, the number is " << number << std::endl;
    else if (guess > number)
    {
        std::cout << "Your guess is too high" << std::endl;
    }
    else
        std::cout << "Your guess is too low" << std::endl;
    return 0;
}