// Listing 5.5 - SentinelValue.cpp
#include <iostream>

int main()
{
    std::cout << "Enter an integer (the input ends "
              << "if it is 0): ";
    int data;
    std::cin >> data;

    int sum = 0;
    while (data != 0)
    {
        sum += data;

        std::cout << "Enter an integer (the input ends "
                  << "if it is 0): ";
        std::cin >> data;
    }

    std::cout << "The sum is " << sum << std::endl;

    return 0;
}