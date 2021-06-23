// Exercise 6.22 - Game Craps

#include <iostream>
#include <ctime>
#include <cstdlib>

void toss(int &num1, int &num2, int &sum)
{
    num1 = (rand() % 6) + 1;
    num2 = (rand() % 6) + 1;
    sum = num1 + num2;
    std::cout << "You rolled " << num1 << " + " << num2 << " = " << sum << std::endl;
}

int status(int first, int second, int sum)
{
    if (sum == 2 || sum == 3 || sum == 12)
        return 0;
    else if (sum == 7 || sum == 11)
    {
        return 1;
    }
    else
        return 2;
}

void pointCheck(int &firstDice, int &secondDice, int &sum, int &state)
{
    std::cout << "point is " << sum << std::endl;
    int point = sum;
    toss(firstDice, secondDice, sum);
    if (point == sum)
    {
        std::cout << "You win" << std::endl;
        state = 1;
    }
    else
    {
        std::cout << "You lose" << std::endl;
        state = 0;
    }
}

int main()
{
    srand(time(0));
    int firstDice, secondDice, sum, state = 0, point = 0;

    toss(firstDice, secondDice, sum);
    state = status(firstDice, secondDice, sum);
    if (state == 0)
    {
        std::cout << "You lose" << std::endl;
    }
    else if (state == 1)
    {
        std::cout << "You Win" << std::endl;
    }
    else
    {
        pointCheck(firstDice, secondDice, sum, state);
    }
    return 0;
}