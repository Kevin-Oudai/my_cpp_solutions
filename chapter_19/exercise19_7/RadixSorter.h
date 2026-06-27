#ifndef RADIXSORTER_H
#define RADIXSORTER_H

class RadixSorter
{
public:
    void run() const;
    void radixSort(int list[], int size) const;

private:
    int getMax(int list[], int size) const;
};

#endif
