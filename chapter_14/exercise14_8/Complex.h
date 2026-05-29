#ifndef COMPLEX_H
#define COMPLEX_H

#include <iosfwd>
#include <string>

class Complex
{
public:
    Complex();
    Complex(double realPart);
    Complex(double realPart, double imaginaryPart);

    double getRealPart() const;
    double getImaginaryPart() const;

    Complex add(const Complex &secondComplex) const;
    Complex subtract(const Complex &secondComplex) const;
    Complex multiply(const Complex &secondComplex) const;
    Complex divide(const Complex &secondComplex) const;
    double abs() const;
    std::string toString() const;

    double &operator[](int index);
    double operator[](int index) const;

    Complex &operator+=(const Complex &secondComplex);
    Complex &operator-=(const Complex &secondComplex);
    Complex &operator*=(const Complex &secondComplex);
    Complex &operator/=(const Complex &secondComplex);

    Complex operator+() const;
    Complex operator-() const;
    Complex &operator++();
    Complex operator++(int);
    Complex &operator--();
    Complex operator--(int);

    friend std::istream &operator>>(std::istream &input, Complex &complex);
    friend std::ostream &operator<<(std::ostream &output, const Complex &complex);

private:
    double parts[2];

    static std::string formatDouble(double value);
};

Complex operator+(const Complex &firstComplex, const Complex &secondComplex);
Complex operator-(const Complex &firstComplex, const Complex &secondComplex);
Complex operator*(const Complex &firstComplex, const Complex &secondComplex);
Complex operator/(const Complex &firstComplex, const Complex &secondComplex);

#endif
