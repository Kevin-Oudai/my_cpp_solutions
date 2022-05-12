// Exercise 5.50 - Reverse a string

#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter a string: ";
    std::string message, newMessage;
    std::getline(std::cin, message);

    int count = message.length();
    for (int i = 0; i < count; i++)
    {
        newMessage = message.at(i) + newMessage;
    }
    std::cout << "The reversed string is " << newMessage << std::endl;
    return 0;
}