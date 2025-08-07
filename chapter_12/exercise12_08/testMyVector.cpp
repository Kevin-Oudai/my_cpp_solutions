// vector<elementType>() --> Constructs an empty vector with the specified element type
// vector<elementType>(size: int) --> Constructs a vector with the initial size, filled with default values
// vector<elementType>(size: int, defaultValue: elementType)
// --> Constructs a vector with the initial size, filled with specified values
// push_back(element: elementType): void --> Appends the element in this vector
// pop_back(): void --> Removes the last element from this vector
// size(): unsigned const --> Returns the number of the elements in this vector
// at(index: int): elementType const --> Returns the element at the specified index in this vector
// empty(): bool const --> Returns true if this vector is empty
// clear(): void --> Removes all elements from this vector
// swap(v2: vector): void --> Swaps the contents of this vector with the specified vector

#include <iostream>
#include "MyVector.h"

int main()
{
    MyVector<int> a(5, 3);
    MyVector<int> b(5);
    MyVector<int> c;
    a.printVector();

    c.push_back(2);
    c.push_back(3);
    b.printVector();
    b.pop_back();
    b.printVector();
    c.printVector();

    return 0;
}