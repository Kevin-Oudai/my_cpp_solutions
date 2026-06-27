#ifndef INHERITEDSTACK_H
#define INHERITEDSTACK_H

#include "LinkedList.h"

template<typename T>
class Stack : public LinkedList<T>
{
public:
    bool empty() const;
    T peek() const;
    void push(T value);
    T pop();
};

template<typename T>
bool Stack<T>::empty() const
{
    return this->isEmpty();
}

template<typename T>
T Stack<T>::peek() const
{
    return this->getLast();
}

template<typename T>
void Stack<T>::push(T value)
{
    this->addLast(value);
}

template<typename T>
T Stack<T>::pop()
{
    return this->removeLast();
}

#endif
