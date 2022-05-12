// Exercise 5.54 - Sum, average and product of numbers

#include <iostream>
#include <fstream>

int main()
{
    std::ifstream input("numbers.txt");

    int count = 0;
    double sum = 0.0, product = 1.0, average, number;
    while (!input.eof())
    {
        input >> number;
        sum += number;
        product *= number;
        count++;
    }
    input.close();
    std::cout << "The sum of the numbers are: " << sum << std::endl;
    std::cout << "The average of the numbers are: " << sum / count << std::endl;
    std::cout << "The product of the numbers are: " << product << std::endl;
    return 0;
}