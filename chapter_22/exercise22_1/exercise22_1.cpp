#include "../ContainerUtilities.h"
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> numbers;
    numbers.push_back(12);
    numbers.push_back(4);
    numbers.push_back(31);
    numbers.push_back(9);
    numbers.push_back(18);

    std::cout << "Numbers: ";
    exercise22::printContainer(numbers);
    std::cout << "Maximum: " << exercise22::maxElement<int>(numbers) << std::endl;
    std::cout << "Minimum: " << exercise22::minElement<int>(numbers) << std::endl;

    return 0;
}
