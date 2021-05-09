#include <iostream>

int main()
{
    double subtotal, gratuity, total, gratuityValue;
    std::cout << "Enter the subtotal and a gratuity rate: ";
    std::cin >> subtotal >> gratuity;
    gratuityValue = subtotal * gratuity / 100.0;
    total = gratuityValue + subtotal;
    std::cout << "The gratuity is $" << gratuityValue
              << " and total is $" << total << "." << std::endl;
    return 0;
}