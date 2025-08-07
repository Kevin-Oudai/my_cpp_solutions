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

int addDigits(int extract)
{
    int addDigits = 0;
    while (extract > 0)
    {
        addDigits += (extract % 10);
        extract /= 10;
    }
    return addDigits;
}

bool isAdditivePrime(int number)
{
    if (isPrime(addDigits(number)))
    {
        return true;
    }
    return false;
}

void displayAdditivePrime(int displayAmount)
{
    int count = 2, displayed = 1;
    std::cout << std::setw(18) << std::left << "Prime Number"
              << "Sum of its digits" << std::endl;
    while (displayed <= displayAmount)
    {
        if (isPrime(count) && isAdditivePrime(count))
        {
            std::cout << std::setw(18) << std::left << count
                      << addDigits(count) << std::endl;
            displayed++;
        }
        count++;
    }
}

int main()
{
    displayAdditivePrime(25);
    return 0;
}