#ifndef GENERICSTACK_H
#define GENERICSTACK_H

#include <vector>

template <typename T>
class GenericStack : public std::vector<T>
{
public:
    bool empty() const;
    T peek() const;
    void push(T value);
    T pop();
    int getSize() const;
};

template <typename T>
bool GenericStack<T>::empty() const
{
    return std::vector<T>::empty();
}

template <typename T>
T GenericStack<T>::peek() const
{
    return this->at(this->size() - 1);
}

template <typename T>
void GenericStack<T>::push(T value)
{
    this->push_back(value);
}

template <typename T>
T GenericStack<T>::pop()
{
    T value = this->at(this->size() - 1);
    this->pop_back();
    return value;
}

template <typename T>
int GenericStack<T>::getSize() const
{
    return static_cast<int>(this->size());
}

#endif
