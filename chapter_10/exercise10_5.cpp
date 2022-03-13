#include <iostream>
#include <string>

std::string toLower(std::string input)
{
    std::string output = "";
    for (int i = 0; i < input.length(); i++)
    {
        if (static_cast<int>(input.at(i)) < 97)
        {
            output.append(1, static_cast<char>('a' + (input.at(i) - 'A')));
        }
        else
        {
            output.append(1, input.at(i));
        }
    }
    return output;
}

std::string reverseString(std::string input)
{
    std::string reverse = "";
    for (int i = input.length() - 1; i >= 0; i--)
    {
        reverse.append(1, input.at(i));
    }
    return reverse;
}

std::string capitalize(std::string input)
{
    std::string output = "";
    if (static_cast<int>(input.at(0)) >= 97)
    {
        output.append(1, static_cast<char>('A' + input.at(0) - 'a'));
    }
    else
    {
        output.append(1, input.at(0));
    }

    for (int i = 1; i < input.length(); i++)
    {
        if (static_cast<int>(input.at(i)) < 97)
        {
            output.append(1, static_cast<char>('a' + (input.at(i) - 'A')));
        }
        else
        {
            output.append(1, input.at(i));
        }
    }
    return output;
}

bool isPalindrome(const std::string &s)
{
    std::string forward, reverse;
    forward = toLower(s);
    reverse = reverseString(forward);
    if (forward.compare(reverse) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    std::string input;
    std::cout << "Enter a string s: ";
    std::cin >> input;
    if (isPalindrome(input))
    {
        std::cout << capitalize(input) << " is a palindrome." << std::endl;
    }
    else
    {
        std::cout << capitalize(input) << " is NOT a palindrome." << std::endl;
    }

    return 0;
}