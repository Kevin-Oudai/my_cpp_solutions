#include "../ContainerUtilities.h"
#include <deque>
#include <iostream>

int main()
{
    std::deque<int> numbers;
    for (int i = 1; i <= 6; i++)
        numbers.push_back(i);

    std::cout << "Before reverse: ";
    exercise22::printContainer(numbers);

    exercise22::reverse(numbers);

    std::cout << "After reverse: ";
    exercise22::printContainer(numbers);

    return 0;
}
