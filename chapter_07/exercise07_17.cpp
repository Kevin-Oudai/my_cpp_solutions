// Exercise 7.17 - Game: Bean Machine

#include <iostream>
#include <cstdlib>
#include <ctime>

void initializeSlots(int slots[], int size)
{
    for (int i = 0; i < size; i++)
    {
        slots[i] = 0;
    }
}

void displayResults(int slots[], int maxNumberOfBalls, int numberOfSlots)
{
    for (int i = maxNumberOfBalls; i > 0; i--)
    {
        for (int j = 0; j < numberOfSlots; j++)
        {
            (slots[j] >= i)
                ? std::cout << "0"
                : std::cout << " ";
        }
        std::cout << std::endl;
    }
}

int max(int slots[], int size)
{
    int max = slots[0];
    for (int i = 1; i < size; i++)
    {
        if (max < slots[i])
        {
            max = slots[i];
        }
    }
    return max;
}

void runGame(int slots[], int numberOfBalls, int numberOfSlots)
{
    int position;
    for (int i = 0; i < numberOfBalls; i++)
    {
        position = 0;
        for (int j = 0; j < numberOfSlots - 1; j++)
        {
            if (rand() % 2 == 0)
            {
                std::cout << "R";
                position++;
            }
            else
            {
                std::cout << "L";
            }
        }
        std::cout << std::endl;
        slots[position]++;
    }
    int highestValue = max(slots, numberOfSlots);
    displayResults(slots, highestValue, numberOfSlots);
}

int main()
{
    srand(time(0));
    std::cout << "Enter the number of balls to drop: ";
    int numberOfBalls;
    std::cin >> numberOfBalls;

    const int SIZE = 50;
    int slots[SIZE];
    initializeSlots(slots, SIZE);
    std::cout << "Enter the number of slots in the bean machine: ";
    int numberOfSlots;
    std::cin >> numberOfSlots;

    runGame(slots, numberOfBalls, numberOfSlots);
}