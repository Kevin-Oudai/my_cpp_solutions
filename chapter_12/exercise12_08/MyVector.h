#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <iostream>

template <typename T>
class MyVector
{
public:
    MyVector();
    MyVector(int size);
    MyVector(int size, T defaultValue);
    void push_back(T element);
    void pop_back();
    unsigned int getSize() const;
    T at(int index) const;
    bool empty() const;
    void clear();
    void swap(MyVector v2);
    void printVector();

private:
    T elements[100];
    unsigned int size;
};

template <typename T>
MyVector<T>::MyVector()
{
    size = 0;
}

template <typename T>
MyVector<T>::MyVector(int size)
{
    this->size = size;
    for (int i = 0; i < size; i++)
    {
        elements[i] = 0;
    }
}

template <typename T>
MyVector<T>::MyVector(int size, T defaultValue)
{
    this->size = size;
    for (int i = 0; i < size; i++)
    {
        elements[i] = defaultValue;
    }
}

template <typename T>
void MyVector<T>::push_back(T element)
{
    elements[size++] = element;
}

template <typename T>
void MyVector<T>::pop_back()
{
    size--;
}

template <typename T>
unsigned int MyVector<T>::getSize() const
{
    return size;
}

template <typename T>
T MyVector<T>::at(int index) const
{
    return elements[index];
}

template <typename T>
bool MyVector<T>::empty() const
{
    return size == 0;
}

template <typename T>
void MyVector<T>::clear()
{
    this->size = 0;
}

template <typename T>
void MyVector<T>::swap(MyVector v2)
{
    this->size = v2.getSize();
    for (int i = 0; i < this->size; i++)
    {
        elements[i] = v2.at(i);
    }
}

template <typename T>
void MyVector<T>::printVector()
{
    for (int i = 0; i < this->size; i++)
    {
        std::cout << this->elements[i] << " ";
    }
    std::cout << std::endl;
}
#endif