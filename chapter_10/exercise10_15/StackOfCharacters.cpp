#include "StackOfCharacters.h"

StackOfCharacters::StackOfCharacters()
{
    size = 0;
}

void StackOfCharacters::push(char value)
{
    elements[size++] = value;
}

bool StackOfCharacters::elementInStack(char value)
{
    for (int i = 0; i < size; i++)
    {
        if (value == elements[i])
        {
            return true;
        }
    }
    return false;
}

int StackOfCharacters::getSize() const
{
    return size;
}