// Exercise 7.43 - Octal to Binary
// Revision: Exercise 6.41 - octal2Binary

#include <iostream>
#include <cstring>
#include <cmath>

void octal2Binary(int octalNumber, char binaryString[])
{
    int n = 0;
    int total = 0;
    while (octalNumber > 0)
    {
        total += (octalNumber % 10 * pow(8, n++));
        octalNumber /= 10;
    }
    itoa(total, binaryString, 2);
}

int main()
{
    std::cout << "Enter an octal number: ";
    int octalNumber;
    std::cin >> octalNumber;

    char binaryString[100];

    octal2Binary(octalNumber, binaryString);
    std::cout << "The binary Equivalent is: " << binaryString << std::endl;
    return 0;
}