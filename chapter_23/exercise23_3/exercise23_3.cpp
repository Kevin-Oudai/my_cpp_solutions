#include "../AlgorithmUtilities.h"
#include <algorithm>
#include <iostream>
#include <list>

bool lessThanTwo(double value)
{
    return value < 2.0;
}

bool greaterThanFour(double value)
{
    return value > 4.0;
}

int main()
{
    double values[] = {1.3, 2.4, 4.5, 6.7, 4.5, 9.0};

    double* endAfterRemove = std::remove(values, values + 6, 4.5);
    std::cout << "After remove 4.5: ";
    exercise23::printRange(values, endAfterRemove);

    endAfterRemove = std::remove_if(values, endAfterRemove, lessThanTwo);
    std::cout << "After remove_if < 2.0: ";
    exercise23::printRange(values, endAfterRemove);

    double original[] = {1.3, 2.4, 4.5, 6.7, 4.5, 9.0};
    std::list<double> copied;
    std::remove_copy(original, original + 6, back_inserter(copied), 6.7);
    std::cout << "remove_copy except 6.7: ";
    exercise23::printContainer(copied);

    copied.clear();
    std::remove_copy_if(original, original + 6, back_inserter(copied), greaterThanFour);
    std::cout << "remove_copy_if not greater than 4.0: ";
    exercise23::printContainer(copied);

    return 0;
}
