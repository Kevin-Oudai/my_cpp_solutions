#include <iostream>

int main()
{
    double pounds, kilograms;
    double POUND_TO_KILOGRAM = 0.454;
    std::cout << "Enter a number in pounds: ";
    std::cin >> pounds;
    kilograms = pounds * POUND_TO_KILOGRAM;
    std::cout << pounds << " pounds is " << kilograms << " kilograms" << std::endl;
    return 0;
}