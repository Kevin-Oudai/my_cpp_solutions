// Listing 5.6 - ReadAllData.cpp

#include <iostream>
#include <fstream>

int main()
{
    std::ifstream input("score.txt");

    double sum = 0;
    double number;
    while (!input.eof())
    {
        input >> number;
        std::cout << number << " ";
        sum += number;
    }

    input.close();

    std::cout << "\nSum is " << sum << std::endl;

    return 0;
}