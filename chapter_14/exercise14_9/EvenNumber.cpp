#include "EvenNumber.h"

EvenNumber::EvenNumber()
{
    value = 0;
}

EvenNumber::EvenNumber(int n)
{
    value = n;
}

int EvenNumber::getValue() const
{
    return value;
}

int EvenNumber::getNext() const
{
    return value + 2;
}

int EvenNumber::getPrevious() const
{
    return value - 2;
}

EvenNumber &EvenNumber::operator++()
{
    value += 2;
    return *this;
}

EvenNumber EvenNumber::operator++(int)
{
    EvenNumber temp(value);
    value += 2;
    return temp;
}

EvenNumber &EvenNumber::operator--()
{
    value -= 2;
    return *this;
}

EvenNumber EvenNumber::operator--(int)
{
    EvenNumber temp(value);
    value -= 2;
    return temp;
}
