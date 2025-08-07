// Listing 7.6 ConstArrayDemo.cpp

#include <iostream>

void p(const int list[], int arraySize)
{
    // list[0] = 100;
}

int main()
{
    int numbers[5] = {1, 4, 3, 6, 8};
    p(numbers, 5);

    return 0;
}