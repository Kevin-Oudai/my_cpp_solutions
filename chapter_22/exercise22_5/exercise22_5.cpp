#include "../ContainerUtilities.h"
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> numbers;
    int values[] = {3, 7, 7, 9, 11};

    for (int i = 0; i < 5; i++)
        numbers.push_back(values[i]);

    exercise22::remove<int>(numbers, 7);

    std::cout << "After removing the first 7: ";
    exercise22::printContainer(numbers);

    return 0;
}
