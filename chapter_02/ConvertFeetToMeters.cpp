#include <iostream>

int main()
{
    double feet, meters;
    double FOOT_TO_METRES = 0.305;
    std::cout << "Enter the value for feet: ";
    std::cin >> feet;
    meters = feet * FOOT_TO_METRES;
    std::cout << feet << " feet is " << meters << " meters." << std::endl;
    return 0;
}