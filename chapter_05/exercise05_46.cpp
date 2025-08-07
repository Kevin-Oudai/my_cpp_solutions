// Exercise 5.46 - Computer Architecture: Bit-level operations
// I am not sure of this solution it is not mine I need to understand this program.
#include <iostream>

int main()
{
    std::cout << "Enter an integer: ";
    int value, mask = 1, temp, bit;
    std::cin >> value;

    std::cout << "The bits are ";
    for (int i = 15; i >= 0; i--)
    {
        temp = value >> i;
        bit = temp & mask;
        std::cout << bit;
    }

    return 0;
}
