// Exercise 4.19 - Order three cities
#include <iostream>
#include <string>

int main()
{
    std::string firstCity, secondCity, thirdCity, tempCity;
    std::cout << "Enter the first city: ";
    std::getline(std::cin, firstCity);
    std::cout << "Enter the second city: ";
    std::getline(std::cin, secondCity);
    std::cout << "Enter the third city: ";
    std::getline(std::cin, thirdCity);
    if (firstCity > secondCity)
    {
        tempCity = secondCity;
        secondCity = firstCity;
        firstCity = tempCity;
    }
    if (secondCity > thirdCity)
    {
        tempCity = thirdCity;
        thirdCity = secondCity;
        secondCity = tempCity;
    }
    if (firstCity > secondCity)
    {
        tempCity = firstCity;
        firstCity = secondCity;
        secondCity = tempCity;
    }
    std::cout << "The three cities in alphabetical order are " << firstCity << ", " << secondCity << ", and " << thirdCity << std::endl;
    return 0;
}