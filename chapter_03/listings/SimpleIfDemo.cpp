// Listing 3.1 - SimpleIfDemo.cpp

#include <iostream>

int main()
{
    // Prompt the user to enter an integer
    int number;
    std::cout << "Enter an integer: ";
    std::cin >> number;

    if (number % 5 == 0)
        std::cout << "HiFive" << std::endl;

    if (number % 2 == 0)
        std::cout << "HiEven" << std::endl;

    return 0;
}