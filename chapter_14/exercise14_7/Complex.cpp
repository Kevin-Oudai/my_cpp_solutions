#include "Complex.h"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

Complex::Complex()
{
    parts[0] = 0;
    parts[1] = 0;
}

Complex::Complex(double realPart)
{
    parts[0] = realPart;
    parts[1] = 0;
}

Complex::Complex(double realPart, double imaginaryPart)
{
    parts[0] = realPart;
    parts[1] = imaginaryPart;
}

double Complex::getRealPart() const
{
    return parts[0];
}

double Complex::getImaginaryPart() const
{
    return parts[1];
}

Complex Complex::add(const Complex &secondComplex) const
{
    return Complex(parts[0] + secondComplex.parts[0],
                   parts[1] + secondComplex.parts[1]);
}

Complex Complex::subtract(const Complex &secondComplex) const
{
    return Complex(parts[0] - secondComplex.parts[0],
                   parts[1] - secondComplex.parts[1]);
}

Complex Complex::multiply(const Complex &secondComplex) const
{
    return Complex(parts[0] * secondComplex.parts[0] - parts[1] * secondComplex.parts[1],
                   parts[1] * secondComplex.parts[0] + parts[0] * secondComplex.parts[1]);
}

Complex Complex::divide(const Complex &secondComplex) const
{
    double denominator = secondComplex.parts[0] * secondComplex.parts[0] +
                         secondComplex.parts[1] * secondComplex.parts[1];
    if (denominator == 0)
    {
        return Complex();
    }

    return Complex((parts[0] * secondComplex.parts[0] + parts[1] * secondComplex.parts[1]) / denominator,
                   (parts[1] * secondComplex.parts[0] - parts[0] * secondComplex.parts[1]) / denominator);
}

double Complex::abs() const
{
    return std::sqrt(parts[0] * parts[0] + parts[1] * parts[1]);
}

std::string Complex::toString() const
{
    if (parts[1] == 0)
    {
        return formatDouble(parts[0]);
    }
    return formatDouble(parts[0]) + " + " + formatDouble(parts[1]) + "i";
}

double &Complex::operator[](int index)
{
    return parts[index == 0 ? 0 : 1];
}

double Complex::operator[](int index) const
{
    return parts[index == 0 ? 0 : 1];
}

Complex &Complex::operator+=(const Complex &secondComplex)
{
    *this = add(secondComplex);
    return *this;
}

Complex &Complex::operator-=(const Complex &secondComplex)
{
    *this = subtract(secondComplex);
    return *this;
}

Complex &Complex::operator*=(const Complex &secondComplex)
{
    *this = multiply(secondComplex);
    return *this;
}

Complex &Complex::operator/=(const Complex &secondComplex)
{
    *this = divide(secondComplex);
    return *this;
}

Complex Complex::operator+() const
{
    return *this;
}

Complex Complex::operator-() const
{
    return Complex(-parts[0], -parts[1]);
}

Complex &Complex::operator++()
{
    parts[0]++;
    return *this;
}

Complex Complex::operator++(int)
{
    Complex temp(*this);
    parts[0]++;
    return temp;
}

Complex &Complex::operator--()
{
    parts[0]--;
    return *this;
}

Complex Complex::operator--(int)
{
    Complex temp(*this);
    parts[0]--;
    return temp;
}

std::istream &operator>>(std::istream &input, Complex &complex)
{
    input >> complex.parts[0] >> complex.parts[1];
    return input;
}

std::ostream &operator<<(std::ostream &output, const Complex &complex)
{
    output << complex.toString();
    return output;
}

std::string Complex::formatDouble(double value)
{
    if (value > -0.000000000000001 && value < 0.000000000000001)
    {
        value = 0;
    }

    std::ostringstream output;
    output << std::fixed << std::setprecision(15) << value;
    std::string text = output.str();

    while (text.length() > 0 && text[text.length() - 1] == '0')
    {
        text.erase(text.length() - 1, 1);
    }
    if (text.length() > 0 && text[text.length() - 1] == '.')
    {
        text += "0";
    }
    return text;
}

Complex operator+(const Complex &firstComplex, const Complex &secondComplex)
{
    return firstComplex.add(secondComplex);
}

Complex operator-(const Complex &firstComplex, const Complex &secondComplex)
{
    return firstComplex.subtract(secondComplex);
}

Complex operator*(const Complex &firstComplex, const Complex &secondComplex)
{
    return firstComplex.multiply(secondComplex);
}

Complex operator/(const Complex &firstComplex, const Complex &secondComplex)
{
    return firstComplex.divide(secondComplex);
}
