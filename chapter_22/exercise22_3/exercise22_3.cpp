#include "../ContainerUtilities.h"
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> numbers;
    int values[] = {2, 4, 2, 8, 2, 16, 4};

    for (int i = 0; i < 7; i++)
        numbers.push_back(values[i]);

    std::cout << "Occurrences of 2: " << exercise22::countElement<int>(numbers, 2) << std::endl;
    std::cout << "Occurrences of 4: " << exercise22::countElement<int>(numbers, 4) << std::endl;

    return 0;
}
