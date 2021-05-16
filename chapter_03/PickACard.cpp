#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

int main()
{
    srand(time(0));
    int card = rand() % 52;
    std::cout << "The card you picked is ";
    switch (card % 13)
    {
    case 0:
        std::cout << "Ace of ";
        break;
    case 1:
        std::cout << "2 of ";
        break;
    case 2:
        std::cout << "3 of ";
        break;
    case 3:
        std::cout << "4 of ";
        break;
    case 4:
        std::cout << "5 of ";
        break;
    case 5:
        std::cout << "6 of ";
        break;
    case 6:
        std::cout << "7 of ";
        break;
    case 7:
        std::cout << "8 of ";
        break;
    case 8:
        std::cout << "9 of ";
        break;
    case 9:
        std::cout << "10 of ";
        break;
    case 10:
        std::cout << "Jack of ";
        break;
    case 11:
        std::cout << "Queen of ";
        break;
    case 12:
        std::cout << "King of ";
        break;
    default:
        break;
    }

    switch (card / 13)
    {
    case 0:
        std::cout << "Clubs" << std::endl;
        break;
    case 1:
        std::cout << "Diamonds" << std::endl;
        break;
    case 2:
        std::cout << "Hearts" << std::endl;
        break;
    case 3:
        std::cout << "Spades" << std::endl;
        break;
    default:
        break;
    }

    return 0;
}