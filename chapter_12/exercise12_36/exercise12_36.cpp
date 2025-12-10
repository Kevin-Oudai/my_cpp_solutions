#include <iostream>
#include <vector>

const int ROWS = 6;
const int COLS = 7;

void printBoard(const std::vector<std::vector<char>> &board)
{
    for (int r = 0; r < ROWS; r++)
    {
        std::cout << "|";
        for (int c = 0; c < COLS; c++)
        {
            std::cout << board[r][c] << "|";
        }
        std::cout << std::endl;
    }
    for (int c = 0; c < COLS; c++)
    {
        std::cout << " " << c;
    }
    std::cout << std::endl;
}

bool dropDisc(std::vector<std::vector<char>> &board, int col, char symbol)
{
    if (col < 0 || col >= COLS)
    {
        return false;
    }

    for (int r = ROWS - 1; r >= 0; r--)
    {
        if (board[r][col] == ' ')
        {
            board[r][col] = symbol;
            return true;
        }
    }
    return false;
}

bool checkDirection(const std::vector<std::vector<char>> &board, int row, int col, int dr, int dc, char symbol)
{
    int count = 0;
    for (int k = 0; k < 4; k++)
    {
        int r = row + dr * k;
        int c = col + dc * k;
        if (r < 0 || r >= ROWS || c < 0 || c >= COLS)
        {
            return false;
        }
        if (board[r][c] != symbol)
        {
            return false;
        }
        count++;
    }
    return count == 4;
}

bool hasWinner(const std::vector<std::vector<char>> &board, char symbol)
{
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            if (board[r][c] != symbol)
            {
                continue;
            }
            if (checkDirection(board, r, c, 0, 1, symbol) ||
                checkDirection(board, r, c, 1, 0, symbol) ||
                checkDirection(board, r, c, 1, 1, symbol) ||
                checkDirection(board, r, c, 1, -1, symbol))
            {
                return true;
            }
        }
    }
    return false;
}

bool boardFull(const std::vector<std::vector<char>> &board)
{
    for (int c = 0; c < COLS; c++)
    {
        if (board[0][c] == ' ')
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::vector<std::vector<char>> board(ROWS, std::vector<char>(COLS, ' '));
    char current = 'R';

    while (true)
    {
        printBoard(board);
        std::cout << "Drop a " << (current == 'R' ? "red" : "yellow") << " disk at column (0-" << COLS - 1 << "): ";
        int col;
        if (!(std::cin >> col))
        {
            break;
        }

        if (!dropDisc(board, col, current))
        {
            std::cout << "Column full or invalid. Try another column." << std::endl;
            continue;
        }

        if (hasWinner(board, current))
        {
            printBoard(board);
            std::cout << (current == 'R' ? "Red" : "Yellow") << " wins!" << std::endl;
            break;
        }

        if (boardFull(board))
        {
            printBoard(board);
            std::cout << "Draw! Board is full." << std::endl;
            break;
        }

        current = (current == 'R') ? 'Y' : 'R';
    }

    return 0;
}
