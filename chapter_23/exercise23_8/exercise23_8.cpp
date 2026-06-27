#include "../AlgorithmUtilities.h"
#include <iostream>

int main()
{
    int values[] = {1, 2, 3, 4, 5};

    exercise23::fill(values, values + 5, 8);
    std::cout << "After custom fill: ";
    exercise23::printRange(values, values + 5);

    exercise23::fill_n(values, 3, 2);
    std::cout << "After custom fill_n: ";
    exercise23::printRange(values, values + 5);

    return 0;
}
