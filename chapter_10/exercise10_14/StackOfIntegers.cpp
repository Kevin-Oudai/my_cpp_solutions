#include "StackOfIntegers.h"

StackOfIntegers::StackOfIntegers()
{
    size = 0;
}

bool StackOfIntegers::isEmpty() const
{
    return size == 0;
}

int StackOfIntegers::peek() const
{
    return elements[size - 1];
}

void StackOfIntegers::push(int value)
{
    elements[size++] = value;
}

int StackOfIntegers::pop()
{
    return elements[--size];
}

int StackOfIntegers::getSize() const
{
    return size;
}