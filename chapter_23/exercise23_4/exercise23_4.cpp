#include "../AlgorithmUtilities.h"
#include <algorithm>
#include <iostream>
#include <vector>

bool lessThanTwo(double value)
{
    return value < 2.0;
}

bool greaterOrEqualOnePointThree(double value)
{
    return value >= 1.3;
}

int main()
{
    double values[] = {2.4, 1.3, 2.4, 4.5, 6.7, 4.5, 9.0};

    std::replace(values, values + 7, 2.4, 9.9);
    std::cout << "After replace 2.4: ";
    exercise23::printRange(values, values + 7);

    std::replace_if(values, values + 7, lessThanTwo, 12.5);
    std::cout << "After replace_if < 2.0: ";
    exercise23::printRange(values, values + 7);

    double original[] = {2.4, 1.3, 2.4, 4.5, 6.7, 4.5, 9.0};
    std::vector<double> copied(7);
    std::replace_copy(original, original + 7, copied.begin(), 6.7, 9.7);
    std::cout << "replace_copy 6.7: ";
    exercise23::printContainer(copied);

    std::replace_copy_if(original, original + 7, copied.begin(), greaterOrEqualOnePointThree, 747);
    std::cout << "replace_copy_if >= 1.3: ";
    exercise23::printContainer(copied);

    return 0;
}
