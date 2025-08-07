#include <iostream>

int main()
{
    double weight1, cost1, weight2, cost2, rate1, rate2;

    std::cout << "Enter weight and price for package 1: ";
    std::cin >> weight1 >> cost1;
    rate1 = weight1 / cost1;

    std::cout << "Enter weight and price for package 2: ";
    std::cin >> weight2 >> cost2;
    rate2 = weight2 / cost2;

    if (rate2 > rate1)
    {
        std::cout << "Package 2 has a better price." << std::endl;
    }
    else if (rate1 > rate2)
    {
        std::cout << "Package 1 has a better price." << std::endl;
    }
    else
    {
        std::cout << "Two packages have the same price." << std::endl;
    }

    return 0;
}