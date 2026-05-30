#include <iostream>
#include <string>
#include "PalindromeChecker.h"

int main()
{
    std::string text;
    std::cout << "Enter a string: ";
    std::getline(std::cin, text);

    PalindromeChecker checker;
    if (checker.isPalindrome(text))
    {
        std::cout << text << " is a palindrome" << std::endl;
    }
    else
    {
        std::cout << text << " is not a palindrome" << std::endl;
    }
    std::cout << "Recursive calls: " << checker.getCallCount() << std::endl;

    return 0;
}
