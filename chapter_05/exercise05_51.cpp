// Exercise 5.51 - Business: Check ISBN-13

#include <iostream>

int main()
{
    std::cout << "Enter the first 12 digits of an ISBN-13 as a string: ";
    std::string message;
    std::cin >> message;
    int count = message.length();
    int sum = 0;
    if (count == 12)
    {
        for (int i = 0; i < count; i++)
        {
            if (i % 2 == 0)
            {
                sum += static_cast<int>(message.at(i)) - 48;
            }
            else
            {
                sum += (3 * (static_cast<int>(message.at(i)) - 48));
            }
        }
        sum = (10 - (sum % 10)) % 10;
        std::cout << "The ISBN-13 number is " << message << sum << std::endl;
    }
    else
    {
        std::cout << message << " is an invalid input." << std::endl;
    }

    return 0;
}