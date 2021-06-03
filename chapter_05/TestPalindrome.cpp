// Listing 5.16 - TestPalindrome.cpp

#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter a string: ";
    std::string s;
    std::getline(std::cin, s);

    int low = 0;

    int high = s.length() - 1;

    bool isPalindrome = true;
    while (low < high)
    {
        if (s[low] != s[high])
        {
            isPalindrome = false;
            break;
        }

        low++;
        high--;
    }

    if (isPalindrome)
    {
        std::cout << s << " is a palindrome" << std::endl;
    }
    else
        std::cout << s << " is not a palindrome" << std::endl;

    return 0;
}