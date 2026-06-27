#include "../AlgorithmUtilities.h"
#include <iostream>
#include <vector>

int main()
{
    int values[] = {1, 2, 3, 4, 5};
    std::vector<int> copied(5);

    exercise23::reverse_copy(values, values + 5, copied.begin());
    std::cout << "Reverse copy: ";
    exercise23::printContainer(copied);

    exercise23::reverse(values, values + 5);
    std::cout << "After custom reverse: ";
    exercise23::printRange(values, values + 5);

    return 0;
}
