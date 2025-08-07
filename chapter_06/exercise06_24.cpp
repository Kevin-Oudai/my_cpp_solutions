// Exercise 6.24 - Game: Win to lose ratio at craps

#include <iostream>
#include <ctime>
#include <cstdlib>

void toss(int &num1, int &num2, int &sum)
{
    num1 = (rand() % 6) + 1;
    num2 = (rand() % 6) + 1;
    sum = num1 + num2;
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

void pointCheck(int &firstDice, int &secondDice, int &sum, int &state, int &win, int &lose)
{
    int point = sum;
    toss(firstDice, secondDice, sum);
    if (point == sum)
    {
        state = 1;
        win++;
    }
    else
    {
        state = 0;
        lose++;
    }
}

void runGame(int &win, int &lose)
{
    int firstDice, secondDice, sum, state = 0, point = 0;
    toss(firstDice, secondDice, sum);
    state = status(firstDice, secondDice, sum);
    if (state == 0)
    {
        lose++;
    }
    else if (state == 1)
    {
        win++;
    }
    else
    {
        pointCheck(firstDice, secondDice, sum, state, win, lose);
    }
}

double percent(double num, double total)
{
    return (num / total * 100);
}
int main()
{
    srand(time(0));
    int win = 0, lose = 0;
    for (int i = 0; i < 100000; i++)
    {
        runGame(win, lose);
    }
    std::cout << "Win: " << percent(win, win + lose) << "%\tLose: " << percent(lose, win + lose) << "%\n";
    return 0;
}