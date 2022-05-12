// Listing 7.3 - DeckOfCards.cpp

#include <iostream>
#include <ctime>
#include <string>

int main()
{
    const int NUMBER_OF_CARDS = 52;
    int deck[NUMBER_OF_CARDS];
    std::string suits[] = {"Spades", "Hearts", "Diamonds", "Clubs"};
    std::string ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

    for (int i = 0; i < NUMBER_OF_CARDS; i++)
    {
        deck[i] = i;
    }

    srand(time(0));
    for (int i = 0; i < NUMBER_OF_CARDS; i++)
    {
        int index = rand() % NUMBER_OF_CARDS;
        int temp = deck[i];
        deck[i] = deck[index];
        deck[index] = temp;
    }

    for (int i = 0; i < 4; i++)
    {
        std::string suit = suits[deck[i] / 13];
        std::string rank = ranks[deck[i] % 13];
        std::cout << "Card number " << deck[i] << ": " << rank << " of " << suit << std::endl;
    }
    return 0;
}