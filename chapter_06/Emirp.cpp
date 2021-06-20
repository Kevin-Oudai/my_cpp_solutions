// Exercise 6.23 - Emirp

#include <iostream>
#include <iomanip>

bool isPrime(int number)
{
    for (int divisor = 2; divisor <= number / 2; divisor++)
    {
        if (number % divisor == 0)
        {
            return false;
        }
    }

    return true;
}

int reverseNumber(int number)
{
    int reverseNumber = 0, extract;
    extract = number;
    while (extract > 0)
    {
        reverseNumber = (reverseNumber * 10) + (extract % 10);
        extract /= 10;
    }
    return reverseNumber;
}

bool hasEmirp(int number)
{
    if (isPrime(reverseNumber(number)))
    {
        return true;
    }
    return false;
}

void displayEmirp(int displayAmount, int amountPerLine)
{
    int count = 2, displayed = 1;

    while (displayed <= displayAmount)
    {
        if (isPrime(count) && hasEmirp(count))
        {
            std::cout << std::setw(6) << std::right << count;
            if (displayed % amountPerLine == 0)
                std::cout << std::endl;
            displayed++;
        }
        count++;
    }
}

int main()
{
    displayEmirp(100, 10);
    return 0;
}