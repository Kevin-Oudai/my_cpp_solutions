#include "../AlgorithmUtilities.h"
#include <algorithm>
#include <iostream>

int main()
{
    double values[] = {1.3, 2.4, 4.5, 6.7, 9.0};

    std::fill(values, values + 3, 5.5);
    std::cout << "After fill: ";
    exercise23::printRange(values, values + 5);

    std::fill_n(values, 4, 6.9);
    std::cout << "After fill_n: ";
    exercise23::printRange(values, values + 5);

    return 0;
}
