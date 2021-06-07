#include <iostream>
#include <string>
#include <iomanip>

int main()
{
    std::cout << "Enter the number of items: ";
    int numberOfItems;
    std::cin >> numberOfItems;
    std::string lowestName, name, trash;
    double lowestPrice, price;
    int count = 0;

    while (count < numberOfItems)
    {
        std::getline(std::cin, trash);
        std::cout << "Item Name: ";
        std::getline(std::cin, name);
        std::cout << "Item Price: ";
        std::cin >> price;
        if (count == 0)
        {
            lowestName = name;
            lowestPrice = price;
        }
        else
        {
            if (price < lowestPrice)
            {
                lowestName = name;
                lowestPrice = price;
            }
        }

        count++;
    }
    std::cout << "The item with the lowest price is: " << lowestName << std::endl;
    std::cout << "The corresponding price is: $" << std::setprecision(2)
              << std::showpoint << std::fixed << lowestPrice << std::endl;

    return 0;
}