// Exercise 6.47 - Phone keypads
#include <iostream>
#include <cctype>
#include <string>

int getNumber(char uppercaseLetter)
{
    if (uppercaseLetter == 'A' || uppercaseLetter == 'B' || uppercaseLetter == 'C')
    {
        return 2;
    }
    else if (uppercaseLetter == 'D' || uppercaseLetter == 'E' || uppercaseLetter == 'F')
    {
        return 3;
    }
    else if (uppercaseLetter == 'G' || uppercaseLetter == 'H' || uppercaseLetter == 'I')
    {
        return 4;
    }
    else if (uppercaseLetter == 'J' || uppercaseLetter == 'K' || uppercaseLetter == 'L')
    {
        return 5;
    }
    else if (uppercaseLetter == 'M' || uppercaseLetter == 'N' || uppercaseLetter == 'O')
    {
        return 6;
    }
    else if (uppercaseLetter == 'P' || uppercaseLetter == 'Q' || uppercaseLetter == 'R' || uppercaseLetter == 'S')
    {
        return 7;
    }
    else if (uppercaseLetter == 'T' || uppercaseLetter == 'U' || uppercaseLetter == 'V')
    {
        return 8;
    }
    else if (uppercaseLetter == 'W' || uppercaseLetter == 'X' || uppercaseLetter == 'Y' || uppercaseLetter == 'Z')
    {
        return 9;
    }
    else
    {
        return 0;
    }
}

int main()
{
    std::cout << "Enter a string: ";
    std::string s, s1 = "";
    std::getline(std::cin, s);

    for (int i = 0; i < s.length(); i++)
    {
        if (isalpha(s.at(i)))
        {
            s1 += static_cast<char>(getNumber(toupper(s.at(i))) + '0');
        }
        else
        {
            s1 += s.at(i);
        }
    }

    std::cout << s1 << std::endl;
    return 0;
}