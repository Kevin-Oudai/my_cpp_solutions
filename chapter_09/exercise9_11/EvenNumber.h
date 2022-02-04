#ifndef EVENNUMBER_H
#define EVENNUMBER_H

class EvenNumber
{
public:
    EvenNumber();
    EvenNumber(int n);
    int getValue();
    int getNext();
    int getPrevious();

private:
    int value;
};
#endif