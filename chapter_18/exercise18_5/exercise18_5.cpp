#include <iostream>
#include <vector>
#include "SameNumberSubsequence.h"

int main()
{
    std::cout << "Enter a series of numbers ending with 0: ";
    std::vector<int> values;
    int number;
    std::cin >> number;
    while (number != 0)
    {
        values.push_back(number);
        std::cin >> number;
    }

    SameNumberSubsequence subsequence;
    subsequence.find(values);

    if (subsequence.getLength() == 0)
    {
        std::cout << "No values were entered" << std::endl;
    }
    else
    {
        std::cout << "The longest same number sequence starts at index "
            << subsequence.getStartIndex() << " with "
            << subsequence.getLength() << " values" << std::endl;
        std::cout << "of " << subsequence.getValue() << std::endl;
    }

    return 0;
}
