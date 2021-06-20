// Exercise 6.21 - Even Palindrome Number

#include <iostream>
#include <iomanip>

bool isPalindrome(int number)
{
    int reverseNumber = 0, extract;
    extract = number;
    while (extract > 0)
    {
        reverseNumber = (reverseNumber * 10) + (extract % 10);
        extract /= 10;
    }

    if (number == reverseNumber)
    {
        return true;
    }
    return false;
}

bool isEven(int number)
{
    if (number % 2 == 0)
        return true;
    return false;
}

void displayPalindromes(int displayAmount)
{
    int count = 1, displayed = 1;

    while (displayed < displayAmount)
    {
        if (isPalindrome(count) && isEven(count))
        {
            std::cout << std::setw(6) << std::right << count;
            if (displayed % 5 == 0)
                std::cout << std::endl;
            displayed++;
        }
        count++;
    }
}

int main()
{
    displayPalindromes(50);
    return 0;
}