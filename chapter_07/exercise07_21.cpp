// Create deck
// Shuffle deck
// Pick cards
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

void createDeck(int deck[])
{
    for (int i = 0; i < 52; i++)
    {
        deck[i] = i;
    }
}

void shuffleDeck(int deck[])
{
    for (int i = 0; i < 52; i++)
    {
        int pos = rand() % 52;
        int temp = deck[i];
        deck[i] = deck[pos];
        deck[pos] = temp;
    }
}

void displayCard(int card)
{
    std::string suit[4] = {"Hearts", "Clubs", "Diamonds", "Spades"};
    std::string rank[13] = {"Ace", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "Jack", "Queen", "King"};
    std::cout << rank[card % 13] << " of " << suit[card / 13] << std::endl;
}

bool allPicked(bool picks[])
{
    for (int i = 0; i < 4; i++)
    {
        if (!picks[i])
        {
            return false;
        }
    }
    return true;
}

int pickCards(int deck[])
{
    bool picked[] = {false, false, false, false};
    int picks = 0;
    while (!allPicked(picked))
    {
        int card = deck[rand() % 52];
        if (card / 13 == 0 && !picked[0])
        {
            picked[0] = true;
            displayCard(card);
        }
        else if (card / 13 == 1 && !picked[1])
        {
            picked[1] = true;
            displayCard(card);
        }
        else if (card / 13 == 2 && !picked[2])
        {
            picked[2] = true;
            displayCard(card);
        }
        else if (card / 13 == 3 && !picked[3])
        {
            picked[3] = true;
            displayCard(card);
        }
        picks++;
    }
    return picks++;
}

int main()
{
    srand(time(0));
    int deck[52];
    createDeck(deck);
    shuffleDeck(deck);
    int picks = pickCards(deck);
    std::cout << "Total picks: " << picks << std::endl;
    return 0;
}