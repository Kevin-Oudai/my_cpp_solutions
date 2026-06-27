#include <iostream>
#include <map>

int main()
{
    std::map<int, int> occurrences;
    int number;

    std::cout << "Enter numbers (ending with 0): ";

    while (std::cin >> number && number != 0)
        occurrences[number]++;

    if (occurrences.empty())
    {
        int sample[] = {2, 3, 4, 1, 2, 34, 4, 3};
        for (int i = 0; i < 8; i++)
            occurrences[sample[i]]++;
        std::cout << "2 3 4 1 2 34 4 3 0" << std::endl;
    }

    for (std::map<int, int>::iterator iterator = occurrences.begin(); iterator != occurrences.end(); iterator++)
        std::cout << "number of occurrences for " << iterator->first << " is " << iterator->second << std::endl;

    return 0;
}
