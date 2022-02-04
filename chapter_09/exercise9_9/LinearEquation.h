#ifndef LINEAREQUATION_H
#define LINEAREQUATION_H

class LinearEquation
{
public:
    LinearEquation(double g, double h, double i, double j, double k, double l);
    double getA();
    double getB();
    double getC();
    double getD();
    double getE();
    double getF();
    bool isSolvable();
    double getX();
    double getY();

private:
    double a, b, c, d, e, f;
};
#endif