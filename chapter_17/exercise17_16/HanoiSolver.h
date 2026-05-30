#ifndef HANOISOLVER_H
#define HANOISOLVER_H

class HanoiSolver
{
public:
    HanoiSolver();

    void moveDisks(int n, char fromTower, char toTower, char auxTower);
    int getMoveCount() const;

private:
    int moveCount;
};

#endif
