#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <vector>

template <typename T>
class Stack
{
public:
    Stack();
    bool empty() const;
    T peek() const;
    void push(T value);
    T pop();
    int getSize() const;
    void printStack();

private:
    std::vector<T> elements;
};

template <typename T>
Stack<T>::Stack()
{
}

template <typename T>
bool Stack<T>::empty() const
{
    return this->elements.empty();
}

template <typename T>
T Stack<T>::peek() const
{
    return elements.at(elements.size() - 1);
}

template <typename T>
void Stack<T>::push(T value)
{
    elements.push_back(value);
}

template <typename T>
T Stack<T>::pop()
{
    return elements.pop_back();
}

template <typename T>
int Stack<T>::getSize() const
{
    return elements.size();
}

template <typename T>
void Stack<T>::printStack()
{
    for (int i = 0; i < elements.size(); i++)
    {
        std::cout << elements.at(i) << " ";
    }
    std::cout << std::endl;
}

#endif