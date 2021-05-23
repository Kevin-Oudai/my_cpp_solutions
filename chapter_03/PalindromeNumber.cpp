#include <iostream>

int main()
{
    std::cout << "Enter a three-digit integer: ";
    int num;
    std::cin >> num;

    if (num / 100 == num % 10)
    {
        std::cout << num << " is a palindrome." << std::endl;
    }
    else
    {
        std::cout << num << " is not a palindrome." << std::endl;
    }
    return 0;
}