#ifndef EIGHTQUEENSSOLVER_H
#define EIGHTQUEENSSOLVER_H

class EightQueensSolver
{
public:
    EightQueensSolver();

    void solve(int displayLimit);
    int getSolutionCount() const;

private:
    int queens[8];
    int solutionCount;
    int displayLimit;

    void search(int row);
    bool isSafe(int row, int column) const;
    void printBoard() const;
};

#endif
