#ifndef SORTINGTIMER_H
#define SORTINGTIMER_H

class SortingTimer
{
public:
    void run() const;
    void displayTable(bool useExerciseSizes) const;

private:
    void selectionSort(int list[], int arraySize) const;
    void insertionSort(int list[], int arraySize) const;
    void bubbleSort(int list[], int arraySize) const;
    void mergeSort(int list[], int arraySize) const;
    void quickSort(int list[], int arraySize) const;
    void heapSort(int list[], int arraySize) const;
    long timeSort(int algorithm, int size) const;
    int* createRandomArray(int size) const;
    int* copyArray(int source[], int size) const;
    bool isSorted(int list[], int size) const;
};

#endif
