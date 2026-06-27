#include "../HashUtilities.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>

int main()
{
    int size = std::getenv("QUICK_TEST") == NULL ? 1000000 : 50000;
    std::vector<int> values;
    std::vector<int> queries;
    MySet<int> set;
    std::mt19937 engine(3);

    for (int i = 0; i < size; i++)
        values.push_back(i);

    std::shuffle(values.begin(), values.end(), engine);

    for (int i = 0; i < size; i++)
        set.add(values[i]);

    std::sort(values.begin(), values.end());

    for (int i = 0; i < size; i++)
        queries.push_back(i * 2);

    std::shuffle(queries.begin(), queries.end(), engine);

    clock_t start = clock();
    int vectorFound = 0;
    for (int i = 0; i < size; i++)
    {
        if (std::binary_search(values.begin(), values.end(), queries[i]))
            vectorFound++;
    }
    double vectorTime = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;

    start = clock();
    int setFound = 0;
    for (int i = 0; i < size; i++)
    {
        if (set.contains(queries[i]))
            setFound++;
    }
    double setTime = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;

    std::cout << "Test size: " << size << std::endl;
    std::cout << "Vector found count: " << vectorFound << ", time: " << vectorTime << " seconds" << std::endl;
    std::cout << "MySet found count: " << setFound << ", time: " << setTime << " seconds" << std::endl;

    return 0;
}
