#include <iostream>
#include "DigitParityCounter.h"

int main()
{
    int value;
    std::cout << "Enter an integer: ";
    std::cin >> value;

    DigitParityCounter counter;
    counter.evenAndOddCount(value);

    std::cout << "The number of even digits is " << counter.getEvenCount() << std::endl;
    std::cout << "The number of odd digits is " << counter.getOddCount() << std::endl;

    return 0;
}
