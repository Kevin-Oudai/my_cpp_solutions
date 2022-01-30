#include <iostream>

void displayBoard(char board[][3])
{
    for (int i = 0; i < 3; i++)
    {
        std::cout << "-------------" << std::endl;
        std::cout << "| " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " |" << std::endl;
    }
    std::cout << "-------------" << std::endl;
}

bool checkWin(char board[][3], int moveCount)
{
    if (moveCount >= 5)
    {
        for (int i = 0; i < 3; i++)
        {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            {
                return true;
            }
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            {
                return true;
            }
        }
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        {
            return true;
        }
        if (board[2][0] == board[1][1] && board[1][1] == board[0][2])
        {
            return true;
        }
    }
    return false;
}

bool checkDraw(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

int boardStatus(char board[3][3], int moveCount)
{
    if (checkWin(board, moveCount))
    {
        return 0;
    }
    else if (checkDraw(board))
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

int move(char board[][3], char player, int moveCount)
{
    int row, col;
    std::cout << "Enter a row (0, 1, or 2) for player " << player << ": ";
    std::cin >> row;
    std::cout << "Enter a column (0, 1, or 2) for player " << player << ": ";
    std::cin >> col;
    if (board[row][col] == ' ')
    {
        board[row][col] = player;
    }
    else
    {
        move(board, player, moveCount);
    }
    displayBoard(board);
    return boardStatus(board, moveCount);
}

void startGame(char board[][3])
{
    displayBoard(board);
    int status = 2, count = 0;
    while (status == 2)
    {
        status = (count % 2 == 0) ? move(board, 'X', count) : move(board, 'O', count);
        if (status == 0)
        {
            std::cout << ((count % 2 == 0) ? 'X' : 'O') << " player won" << std::endl;
        }
        if (status == 1)
        {
            std::cout << "The game was a draw" << std::endl;
        }
        count++;
    }
}

int main()
{
    char board[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }

    startGame(board);
    return 0;
}