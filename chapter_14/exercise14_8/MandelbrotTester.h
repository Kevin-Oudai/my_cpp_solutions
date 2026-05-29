#ifndef MANDELBROTTESTER_H
#define MANDELBROTTESTER_H

#include "Complex.h"

class MandelbrotTester
{
public:
    MandelbrotTester(int maximumIterations = 60);

    bool isInSet(const Complex &c) const;
    void run() const;

private:
    int maximumIterations;
};

#endif
