#ifndef DECIMALTOFRACTIONCONVERTER_H
#define DECIMALTOFRACTIONCONVERTER_H

#include "Rational.h"
#include <string>

class DecimalToFractionConverter
{
public:
    Rational convert(const std::string &decimal) const;

private:
    static long long toNumber(const std::string &text, int start, int end);
};

#endif
