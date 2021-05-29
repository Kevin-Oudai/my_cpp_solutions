// Exercise 4.15 - Phone key pads

#include <iostream>
#include <cctype>

int main()
{
    std::cout << "Enter a letter: ";
    char letter;
    std::cin >> letter;

    letter = toupper(letter);
    if (letter == 'A' || letter == 'B' || letter == 'C')
    {
        std::cout << "The corresponding number is 2" << std::endl;
    }
    else if (letter == 'D' || letter == 'E' || letter == 'F')
    {
        std::cout << "The corresponding number is 3" << std::endl;
    }
    else if (letter == 'G' || letter == 'H' || letter == 'I')
    {
        std::cout << "The corresponding number is 4" << std::endl;
    }
    else if (letter == 'J' || letter == 'K' || letter == 'L')
    {
        std::cout << "The corresponding number is 5" << std::endl;
    }
    else if (letter == 'M' || letter == 'N' || letter == 'O')
    {
        std::cout << "The corresponding number is 6" << std::endl;
    }
    else if (letter == 'P' || letter == 'Q' || letter == 'R' || letter == 'S')
    {
        std::cout << "The corresponding number is 7" << std::endl;
    }
    else if (letter == 'T' || letter == 'U' || letter == 'V')
    {
        std::cout << "The corresponding number is 8" << std::endl;
    }
    else if (letter == 'W' || letter == 'X' || letter == 'Y' || letter == 'Z')
    {
        std::cout << "The corresponding number is 9" << std::endl;
    }
    else
    {
        std::cout << letter << " is an invalid input" << std::endl;
    }
    return 0;
}