// Exercise 5.48 - Count Uppercase letters

#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter a string: ";
    std::string message;
    std::getline(std::cin, message);
    int count = message.length();
    int upper = 0;
    for (int i = 0; i < count; i++)
    {
        if (isupper(message.at(i)))
        {
            upper++;
        }
    }
    std::cout << "The number of uppercase letters is " << upper << std::endl;
    return 0;
}