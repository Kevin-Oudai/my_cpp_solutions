// Exercise 5.39 - Revision of Exercise 3.36 - Palindrome Number
#include <iostream>

int main()
{
    std::cout << "Enter an integer: ";
    int number, reverseNumber = 0, extract;
    std::cin >> number;

    extract = number;
    while (extract > 0)
    {
        reverseNumber = (reverseNumber * 10) + (extract % 10);
        extract /= 10;
    }

    if (number == reverseNumber)
    {
        std::cout << number << " is a palindrome." << std::endl;
    }
    else
    {
        std::cout << number << " is not a palindrome." << std::endl;
    }
    return 0;
}