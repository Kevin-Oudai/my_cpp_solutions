#include "../AlgorithmUtilities.h"
#include <iostream>

bool lessThanThree(int value)
{
    return value < 3;
}

int main()
{
    int values[] = {1, 2, 3, 2, 5};

    exercise23::replace(values, values + 5, 2, 9);
    std::cout << "After custom replace: ";
    exercise23::printRange(values, values + 5);

    exercise23::replace_if(values, values + 5, lessThanThree, 7);
    std::cout << "After custom replace_if: ";
    exercise23::printRange(values, values + 5);

    return 0;
}
