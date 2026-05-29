#ifndef EVENNUMBER_H
#define EVENNUMBER_H

class EvenNumber
{
public:
    EvenNumber();
    EvenNumber(int n);

    int getValue() const;
    int getNext() const;
    int getPrevious() const;

    EvenNumber &operator++();
    EvenNumber operator++(int);
    EvenNumber &operator--();
    EvenNumber operator--(int);

private:
    int value;
};

#endif
