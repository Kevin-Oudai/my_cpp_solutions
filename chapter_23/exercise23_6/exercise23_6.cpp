#include <algorithm>
#include <iostream>

template<typename Iterator>
int position(Iterator iterator, Iterator begin, Iterator end)
{
    if (iterator == end)
        return -1;

    return static_cast<int>(iterator - begin);
}

int main()
{
    double values[] = {2.4, 1.3, 2.4, 2.4, 4.5, 6.7, 4.5, 9.0};
    double sequence[] = {2.4, 4.5};

    std::cout << "Position of sequence {2.4, 4.5}: " << position(std::search(values, values + 8, sequence, sequence + 2), values, values + 8) << std::endl;
    std::cout << "Position of two consecutive 2.4 values: " << position(std::search_n(values, values + 8, 2, 2.4), values, values + 8) << std::endl;

    return 0;
}
