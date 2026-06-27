#include "../ContainerUtilities.h"
#include <iostream>
#include <list>

int main()
{
    std::list<int> numbers;
    int values[] = {1, 5, 2, 5, 3, 5};

    for (int i = 0; i < 6; i++)
        numbers.push_back(values[i]);

    exercise22::replace<int>(numbers, 5, 50);

    std::cout << "After replacing 5 with 50: ";
    exercise22::printContainer(numbers);

    return 0;
}
