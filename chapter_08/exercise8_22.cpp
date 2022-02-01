#include <iostream>

void fillBoard(char board[][7])
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void drawBoard(char board[][7])
{
    for (int i = 0; i < 6; i++)
    {
        std::cout << "|";
        for (int j = 0; j < 7; j++)
        {
            std::cout << board[i][j] << "|";
        }
        std::cout << std::endl;
    }
    std::cout << "----------------------" << std::endl;
}

bool checkWin(char values[][7])
{
    bool consecutive = false;

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            // Check North
            if (i - 3 >= 0 && values[i][j] != ' ' &&
                values[i - 3][j] == values[i - 2][j] &&
                values[i - 2][j] == values[i - 1][j] &&
                values[i - 1][j] == values[i][j])
            {
                return true;
            }
            // Check Northeast
            else if (i - 3 < 0 && j + 3 < 7 && values[i][j] != ' ' &&
                     values[i - 3][j + 3] == values[i - 2][j + 2] &&
                     values[i - 2][j + 2] == values[i - 1][j + 1] &&
                     values[i - 1][j + 1] == values[i][j])
            {
                return true;
            }
            // Check East
            else if (j + 3 <= 7 && values[i][j] != ' ' &&
                     values[i][j + 3] == values[i][j + 2] &&
                     values[i][j + 2] == values[i][j + 1] &&
                     values[i][j + 1] == values[i][j])
            {
                return true;
            }
            // Check Southeast
            else if (i + 3 <= 6 && j + 3 <= 7 && values[i][j] != ' ' &&
                     values[i + 3][j + 3] == values[i + 2][j + 2] &&
                     values[i + 2][j + 2] == values[i + 1][j + 1] &&
                     values[i + 1][j + 1] == values[i][j])
            {
                return true;
            }
            // Check South
            else if (i + 3 <= 7 && values[i][j] != ' ' &&
                     values[i + 3][j] == values[i + 2][j] &&
                     values[i + 2][j] == values[i + 1][j] &&
                     values[i + 1][j] == values[i][j])
            {
                return true;
            }
            // Check Southwest
            else if (i + 3 < 6 && j - 3 > 0 && values[i][j] != ' ' &&
                     values[i + 3][j - 3] == values[i + 2][j - 2] &&
                     values[i + 2][j - 2] == values[i + 1][j - 1] &&
                     values[i + 1][j - 1] == values[i][j])
            {
                return true;
            }
            // Check West
            else if (j - 3 >= 7 && values[i][j] != ' ' &&
                     values[i][j - 3] == values[i][j - 2] &&
                     values[i][j - 2] == values[i][j - 1] &&
                     values[i][j - 1] == values[i][j])
            {
                return true;
            }
            // Check Northwest
            else if (i - 3 >= 0 && j - 3 >= 0 && values[i][j] != ' ' &&
                     values[i - 3][j - 3] == values[i - 2][j - 2] &&
                     values[i - 2][j - 2] == values[i - 1][j - 1] &&
                     values[i - 1][j - 1] == values[i][j])
            {
                return true;
            }
        }
    }
    return false;
}

void makeMove(char board[][7], char token, int move)
{
    if (move == -1)
    {
        std::cout << "Make a valid move (0-6): ";
        std::cin >> move;
        makeMove(board, token, move);
    }

    for (int i = 5; i >= 0; i--)
    {
        if (board[i][move] == 'R' || board[i][move] == 'Y')
        {
            continue;
        }
        else
        {
            board[i][move] = token;
            break;
        }
    }
}

bool checkDraw(char board[][7])
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (board[i][j] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

int checkBoard(char board[][7])
{
    if (checkWin(board))
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

void startGame(char board[][7])
{
    int status = 2;
    int moves = 0;
    int move = -1;
    drawBoard(board);
    while (status == 2)
    {
        if (moves % 2 == 0)
        {
            std::cout << "Drop a red disk at column (0-6): ";
            std::cin >> move;
            makeMove(board, 'R', move);
            drawBoard(board);
            status = checkBoard(board);
        }
        else
        {
            std::cout << "Drop a yellow disk at column (0-6): ";
            std::cin >> move;
            makeMove(board, 'Y', move);
            drawBoard(board);
            status = checkBoard(board);
        }
        if (status == 0)
        {
            (moves % 2 == 0) ? std::cout << "Yellow Player wins" << std::endl : std::cout << "Red Player wins" << std::endl;
        }
        if (status == 1)
        {
            std::cout << "The game is a draw" << std::endl;
        }
        moves++;
    }
}

int main()
{
    char board[6][7];
    fillBoard(board);
    startGame(board);
    return 0;
}