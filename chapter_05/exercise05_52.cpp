// Exercise 5.52 - Process String

#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter a string: ";
    std::string message;
    std::getline(std::cin, message);

    int count = message.length();
    for (int i = 0; i < count; i++)
    {
        if (i % 2 == 1)
        {
            std::cout << message.at(i);
        }
    }
    std::cout << std::endl;
    return 0;
}