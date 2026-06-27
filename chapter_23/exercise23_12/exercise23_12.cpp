#include "../AlgorithmUtilities.h"
#include <iostream>

bool greaterThanFive(int value)
{
    return value > 5;
}

int main()
{
    int values[] = {1, 4, 6, 8, 10};
    int* found = exercise23::find(values, values + 5, 6);
    int* foundIf = exercise23::find_if(values, values + 5, greaterThanFive);

    std::cout << "Custom find 6 position: " << (found - values) << std::endl;
    std::cout << "Custom find_if > 5 position: " << (foundIf - values) << std::endl;

    return 0;
}
