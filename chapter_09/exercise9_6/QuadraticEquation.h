#ifndef QUADRATICEQUATION_H
#define QUADRATICEQUATION_H

class QuadraticEquation
{
public:
    QuadraticEquation(double x, double y, double z);
    double getA();
    double getB();
    double getC();
    double getDiscriminant();
    double getRoot1();
    double getRoot2();

private:
    double a, b, c;
};
#endif