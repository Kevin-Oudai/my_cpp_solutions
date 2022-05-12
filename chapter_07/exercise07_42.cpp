// Exercise 7.42 - Binary to Octal
// Revision: Exercise 6.40 - bin2Octal
// Note:    I added the address number to the octalNumber variable because
//          I do not know any other way to reference it from the main function
//          without returning it.

#include <iostream>
#include <cstring>
#include <cmath>

void bin2Octal(char binaryString[], int &octalNumber)
{
    int total = 0;
    int a;
    int n = 0;

    for (int i = strlen(binaryString) - 1; i >= 0; i--)
    {
        (binaryString[i] == '1') ? a = 1 : a = 0;
        total += (a * pow(2, n++));
    }
    char octStr[100] = {};
    itoa(total, octStr, 8);
    octalNumber = atoi(octStr);
}

int main()
{
    std::cout << "Enter a binary number: ";
    char binaryString[100] = {};
    std::cin.getline(binaryString, 100);

    int octalNumber;
    bin2Octal(binaryString, octalNumber);
    std::cout << "The Octal Equivalent is: " << octalNumber << std::endl;
    return 0;
}