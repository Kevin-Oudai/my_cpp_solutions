// Listing 5.15 - TestContinue.cpp

#include <iostream>

int main()
{
    int sum = 0;
    int number = 0;

    while (number < 20)
    {
        number++;
        if (number == 10 || number == 11)
            continue;
        sum += number;
    }
    std::cout << "The sum is " << sum << std::endl;

    return 0;
}