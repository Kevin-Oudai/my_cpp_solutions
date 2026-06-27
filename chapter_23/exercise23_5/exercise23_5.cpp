#include <algorithm>
#include <iostream>
#include <list>

bool lessThanTwo(double value)
{
    return value < 2.0;
}

template<typename Iterator>
int position(Iterator iterator, Iterator begin, Iterator end)
{
    if (iterator == end)
        return -1;

    return static_cast<int>(iterator - begin);
}

int main()
{
    double values[] = {2.4, 1.3, 2.4, 4.5, 6.7, 4.5, 9.0};
    double sequence[] = {2.4, 4.5};
    std::list<double> listValues;
    listValues.push_back(34);
    listValues.push_back(55);
    listValues.push_back(2.4);
    listValues.push_back(4.5);

    std::cout << "Position of 4.5: " << position(std::find(values, values + 7, 4.5), values, values + 7) << std::endl;
    std::cout << "Position of first value < 2: " << position(std::find_if(values, values + 7, lessThanTwo), values, values + 7) << std::endl;
    std::cout << "Position of last {2.4, 4.5}: " << position(std::find_end(values, values + 7, sequence, sequence + 2), values, values + 7) << std::endl;
    std::cout << "Position of first common value: " << position(std::find_first_of(values, values + 7, listValues.begin(), listValues.end()), values, values + 7) << std::endl;

    return 0;
}
