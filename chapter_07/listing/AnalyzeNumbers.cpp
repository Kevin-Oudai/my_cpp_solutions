// Listing 7.1 AnalyzeNumbers.cpp

#include <iostream>

int main()
{
    const int NUMBER_OF_ELEMENTS = 100;
    double numbers[NUMBER_OF_ELEMENTS];
    double sum = 0;

    for (int i = 0; i < NUMBER_OF_ELEMENTS; i++)
    {
        std::cout << "Enter a new number: ";
        std::cin >> numbers[i];
        sum += numbers[i];
    }

    double average = sum / NUMBER_OF_ELEMENTS;

    int count = 0;
    for (int i = 0; i < NUMBER_OF_ELEMENTS; i++)
    {
        if (numbers[i] > average)
            count++;
    }
    std::cout << "Average is " << average << std::endl;
    std::cout << "Number of elements above the average " << count << std::endl;

    return 0;
}