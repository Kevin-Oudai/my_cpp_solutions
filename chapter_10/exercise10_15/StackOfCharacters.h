#ifndef STACK_H
#define STACK_H

class StackOfCharacters
{
public:
    StackOfCharacters();
    void push(char value);
    bool elementInStack(char element);
    int getSize() const;

private:
    int elements[100];
    int size;
};

#endif