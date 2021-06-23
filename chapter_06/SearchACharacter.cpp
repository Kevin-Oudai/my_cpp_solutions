// Exercise 6.30 - Search a Character

#include <iostream>
#include <string>

void search(std::string &s, char &key)
{
    int numberOfChars = s.length(), status = 0, i;
    for (i = 0; i < numberOfChars; i++)
    {
        if (s.at(i) == key)
        {
            status = 1;
            break;
        }
        status = 0;
    }

    (status == 1) ? std::cout << key << " was found at index: " << i << std::endl : std::cout << key << " was not found." << std::endl;
}

int main()
{
    std::cout << "Enter a string: ";
    std::string message;
    std::getline(std::cin, message);

    std::cout << "Enter a character: ";
    char character;
    std::cin >> character;

    search(message, character);

    return 0;
}