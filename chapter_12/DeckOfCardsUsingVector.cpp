#include <iostream>
#include <vector>
#include <string>
#include <ctime>

const int NUMBER_OF_CARDS = 52;
std::string suits[4] = {"Spades", "Hearts", "Diamonds", "Clubs"};
std::string ranks[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

int main()
{
    std::vector<int> deck(NUMBER_OF_CARDS);

    // Initialize cards
    for (int i = 0; i < NUMBER_OF_CARDS; i++)
    {
        deck[i] = i;
    }

    // Shuffle the cards
    srand(time(0));
    for (int i = 0; i < NUMBER_OF_CARDS; i++)
    {
        // Generate an index randomly
        int index = rand() % NUMBER_OF_CARDS;
        int temp = deck[i];
        deck[i] = deck[index];
        deck[index] = temp;
    }

    // Display the first four cards
    for (int i = 0; i < 4; i++)
    {
        std::cout << ranks[deck[i] % 13] << " of " << suits[deck[i] / 13] << std::endl;
    }

    return 0;
}