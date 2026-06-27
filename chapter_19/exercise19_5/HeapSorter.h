#ifndef HEAPSORTER_H
#define HEAPSORTER_H

#include "Heap.h"

template<typename T>
void heapSort(T list[], int arraySize)
{
    Heap<T> heap;

    for (int i = 0; i < arraySize; i++)
        heap.add(list[i]);

    for (int i = 0; i < arraySize; i++)
        list[arraySize - i - 1] = heap.remove();
}

class HeapSorter
{
public:
    void run() const;
};

#endif
