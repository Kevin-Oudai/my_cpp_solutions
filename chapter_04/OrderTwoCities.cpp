// Listing 4.7 - OrderTwoCities.cpp

#include <iostream>
#include <string>

int main()
{
    std::string city1, city2;
    std::cout << "Enter the first city: ";
    getline(std::cin, city1);
    std::cout << "Enter the second city: ";
    getline(std::cin, city2);

    std::cout << "The cities in alphabetical order are ";
    if (city1 < city2)
        std::cout << city1 << " " << city2 << std::endl;
    else
        std::cout << city2 << " " << city1 << std::endl;

    return 0;
}