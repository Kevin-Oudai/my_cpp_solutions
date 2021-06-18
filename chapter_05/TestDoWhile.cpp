// Listing 5.7 - TestDoWhile.cpp

#include <iostream>

int main()
{
    int sum = 0;
    int data = 0;

    do
    {
        sum += data;

        std::cout << "Enter an integer (the input ends "
                  << "if it is 0): ";
        std::cin >> data;
    } while (data != 0);
    std::cout << "The sum is " << sum << std::endl;

    return 0;
}