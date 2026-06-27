#ifndef HEAP_H
#define HEAP_H

#include <stdexcept>
#include <vector>

template<typename T>
class Heap
{
public:
    Heap();
    Heap(T elements[], int arraySize);
    T remove();
    void add(T element);
    int getSize() const;

private:
    std::vector<T> v;
};

template<typename T>
Heap<T>::Heap()
{
}

template<typename T>
Heap<T>::Heap(T elements[], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        add(elements[i]);
    }
}

template<typename T>
T Heap<T>::remove()
{
    if (v.size() == 0)
        throw std::runtime_error("Heap is empty");

    T removedElement = v[0];
    v[0] = v[v.size() - 1];
    v.pop_back();

    int currentIndex = 0;
    while (currentIndex < static_cast<int>(v.size()))
    {
        int leftChildIndex = 2 * currentIndex + 1;
        int rightChildIndex = 2 * currentIndex + 2;

        if (leftChildIndex >= static_cast<int>(v.size()))
            break;

        int maxIndex = leftChildIndex;
        if (rightChildIndex < static_cast<int>(v.size()) && v[maxIndex] < v[rightChildIndex])
            maxIndex = rightChildIndex;

        if (v[currentIndex] < v[maxIndex])
        {
            T temp = v[maxIndex];
            v[maxIndex] = v[currentIndex];
            v[currentIndex] = temp;
            currentIndex = maxIndex;
        }
        else
        {
            break;
        }
    }

    return removedElement;
}

template<typename T>
void Heap<T>::add(T element)
{
    v.push_back(element);
    int currentIndex = static_cast<int>(v.size()) - 1;

    while (currentIndex > 0)
    {
        int parentIndex = (currentIndex - 1) / 2;
        if (v[currentIndex] > v[parentIndex])
        {
            T temp = v[currentIndex];
            v[currentIndex] = v[parentIndex];
            v[parentIndex] = temp;
        }
        else
        {
            break;
        }

        currentIndex = parentIndex;
    }
}

template<typename T>
int Heap<T>::getSize() const
{
    return static_cast<int>(v.size());
}

#endif
