// Listing 5.14 - TestBreak.cpp
#include <iostream>

int main()
{
    int sum = 0;
    int number = 0;

    while (number < 20)
    {
        number++;
        sum += number;
        if (sum >= 100)
            break;
    }
    std::cout << "The number is " << number << std::endl;
    std::cout << "The sum is " << sum << std::endl;

    return 0;
}