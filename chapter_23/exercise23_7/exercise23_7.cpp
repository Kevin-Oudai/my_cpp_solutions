#include "../AlgorithmUtilities.h"
#include <algorithm>
#include <iostream>

int main()
{
    double values[] = {2.4, 1.3, 2.4, 2.4, 4.5, 6.7, 4.5, 9.0};

    std::sort(values, values + 8);
    std::cout << "Sorted values: ";
    exercise23::printRange(values, values + 8);

    std::cout << "Contains 6.7: " << (std::binary_search(values, values + 8, 6.7) ? "true" : "false") << std::endl;
    std::cout << "Contains 4.3: " << (std::binary_search(values, values + 8, 4.3) ? "true" : "false") << std::endl;

    return 0;
}
