#include <iostream>
#include <string>
#include <iomanip>

int main()
{
    std::cout << "Enter the number of items: ";
    int numberOfItems;
    std::cin >> numberOfItems;
    std::string lowestName, secondLowestName, name, trash;
    double lowestPrice, secondLowestPrice, price;
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
        else if (count == 1 && price > lowestPrice)
        {
            secondLowestName = name;
            secondLowestPrice = price;
        }

        else
        {
            if (price < lowestPrice)
            {
                secondLowestName = lowestName;
                secondLowestPrice = lowestPrice;
                lowestName = name;
                lowestPrice = price;
            }
        }

        count++;
    }
    std::cout << "The item with the lowest price is: " << lowestName << std::endl;
    std::cout << "The corresponding price is: $" << std::setprecision(2)
              << std::showpoint << std::fixed << lowestPrice << std::endl;

    std::cout << "The item with the second lowest price is: " << secondLowestName << std::endl;
    std::cout << "The corresponding price is: $" << secondLowestPrice << std::endl;

    return 0;
}