#ifndef LINEAREQUATIONSOLVER_H
#define LINEAREQUATIONSOLVER_H

#include <vector>

std::vector<double> solveLinearEquation(std::vector<std::vector<double>> a, std::vector<double> b);

class LinearEquationSolver
{
public:
    void run() const;
};

#endif
