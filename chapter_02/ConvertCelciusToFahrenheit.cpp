#include <iostream>

int main()
{
    double celcius, fahrenheit;
    std::cout << "Enter a temperature in degree celcius: ";
    std::cin >> celcius;
    fahrenheit = (9.0 / 5) * celcius + 32;
    std::cout << celcius << " degree celcius is equal to "
              << fahrenheit << " degree fahrenheit" << std::endl;
    return 0;
}