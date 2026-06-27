#include "StackOfIntegers.h"
#include "EmptyStackException.h"

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
    if (isEmpty())
    {
        throw EmptyStackException();
    }

    return elements[size - 1];
}

void StackOfIntegers::push(int value)
{
    elements[size++] = value;
}

int StackOfIntegers::pop()
{
    if (isEmpty())
    {
        throw EmptyStackException();
    }

    return elements[--size];
}

int StackOfIntegers::getSize() const
{
    return size;
}
