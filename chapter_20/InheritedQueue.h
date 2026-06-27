#ifndef INHERITEDQUEUE_H
#define INHERITEDQUEUE_H

#include "LinkedList.h"

template<typename T>
class Queue : public LinkedList<T>
{
public:
    void enqueue(T element);
    T dequeue();
};

template<typename T>
void Queue<T>::enqueue(T element)
{
    this->addLast(element);
}

template<typename T>
T Queue<T>::dequeue()
{
    return this->removeFirst();
}

#endif
