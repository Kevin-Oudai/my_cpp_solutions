// Exercise 7.19 - Game: Multiple Eight Queens Solutions
// Revision: Exercise 7.18 - Game: Eight Queens
#include <iostream>
#include <cmath>

void setBoard(bool board[], int positions[], int boardSize)
{
    int position = 0;
    for (int i = 0; i < boardSize; i++)
    {
        board[i] = false;
    }
    for (int j = 0; j < 8; j++)
    {
        board[positions[j]] = true;
    }
}

void displayBoard(bool board[], int size)
{
    for (int i = 1; i <= size; i++)
    {
        if (board[i - 1])
        {
            std::cout << "|Q";
        }
        else
        {
            std::cout << "| ";
        }
        if (i % 8 == 0)
        {
            std::cout << "|" << std::endl;
        }
    }
}

void tick(int positions[], int index)
{
    int newPosition = positions[index];
    newPosition += 8;
    int wholeNumber = newPosition / 64;
    int remainder = newPosition % 64;
    if (wholeNumber == 1)
    {
        positions[index] = remainder;
        tick(positions, index + 1);
    }
    else
    {
        positions[index] = remainder;
    }
}

bool hClear(bool board[], int size)
{
    bool hClash;
    for (int i = 7; i < size; i += 8)
    {
        hClash = false;
        for (int j = i; j > i - 8; j--)
        {
            if (board[j] && hClash)
            {
                return false;
            }
            else if (board[j])
            {
                hClash = true;
            }
        }
    }
    return true;
}

bool clearRightDiagonal(bool board[])
{
    bool dClash;
    for (int i = 0; i < 64; i += 8)
    {
        dClash = false;
        for (int j = i; j < 64; j += 9)
        {
            if (board[j] && dClash)
            {
                return false;
            }
            else if (board[j])
            {
                dClash = true;
            }
        }
    }

    for (int i = 55; i > 0; i -= 8)
    {
        dClash = false;
        for (int j = i; j > 0; j -= 9)
        {
            if (board[j] && dClash)
            {
                return false;
            }
            else if (board[j])
            {
                dClash = true;
            }
        }
    }
    return true;
}

bool clearLeftDiagonal(bool board[])
{
    bool dClash;
    for (int i = 56; i >= 0; i -= 8)
    {
        dClash = false;
        for (int j = i; j >= 0; j -= 7)
        {
            if (board[j] && dClash)
            {
                return false;
            }
            else if (board[j])
            {
                dClash = true;
            }
        }
    }

    for (int i = 15; i < 64; i += 8)
    {
        dClash = false;
        for (int j = i; j < 64; j += 7)
        {
            if (board[j] && dClash)
            {
                return false;
            }
            else if (board[j])
            {
                dClash = true;
            }
        }
    }
    return true;
}

bool noEnemies(bool board[], int size)
{
    if (hClear(board, size) && clearLeftDiagonal(board) && clearRightDiagonal(board))
    {
        return true;
    }
    return false;
}

int main()
{
    int positions[8] = {56, 49, 42, 35, 28, 21, 14, 7};
    const int SIZE = 64;
    bool board[SIZE];
    setBoard(board, positions, SIZE);
    int boardCount = 0;
    int solutions = 0;
    while (true)
    {
        if (noEnemies(board, SIZE))
        {
            solutions++;
            displayBoard(board, SIZE);
            std::cout << "*****************" << std::endl;
        }
        tick(positions, 0);
        setBoard(board, positions, SIZE);
        if (16777231 == boardCount)
        {
            break;
        }
        boardCount++;
    }
    std::cout << "There are a total of: " << solutions << " solutions." << std::endl;

    return 0;
}