#include "../AlgorithmUtilities.h"
#include <iostream>

int nextValue()
{
    static int value = 0;
    value += 5;
    return value;
}

int main()
{
    int values[] = {1, 2, 3, 4, 5};

    exercise23::generate(values, values + 5, nextValue);
    std::cout << "After custom generate: ";
    exercise23::printRange(values, values + 5);

    exercise23::generate_n(values, 2, nextValue);
    std::cout << "After custom generate_n: ";
    exercise23::printRange(values, values + 5);

    return 0;
}
