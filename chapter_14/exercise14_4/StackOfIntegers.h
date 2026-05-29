#ifndef STACKOFINTEGERS_H
#define STACKOFINTEGERS_H

class StackOfIntegers
{
public:
    StackOfIntegers();

    bool isEmpty() const;
    int peek() const;
    void push(int value);
    int pop();
    int getSize() const;

    int &operator[](int index);
    int operator[](int index) const;

private:
    int elements[100];
    int size;
};

#endif
