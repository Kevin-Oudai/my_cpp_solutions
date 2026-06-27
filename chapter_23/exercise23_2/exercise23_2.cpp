#include "../AlgorithmUtilities.h"
#include <algorithm>
#include <deque>
#include <iostream>

int nextValue()
{
    static int value = 10;
    value += 7;
    return value;
}

int main()
{
    std::deque<int> values;
    int initial[] = {1, 2, 4, 6, 9};

    for (int i = 0; i < 5; i++)
        values.push_back(initial[i]);

    std::generate(values.begin(), values.end(), nextValue);
    std::cout << "After generate: ";
    exercise23::printContainer(values);

    std::generate_n(values.begin(), 3, nextValue);
    std::cout << "After generate_n: ";
    exercise23::printContainer(values);

    return 0;
}
