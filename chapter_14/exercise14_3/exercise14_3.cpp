#include <iostream>
#include "Circle.h"

void sortCircles(Circle circles[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int currentMinIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (circles[j] < circles[currentMinIndex])
            {
                currentMinIndex = j;
            }
        }

        if (currentMinIndex != i)
        {
            Circle temp = circles[i];
            circles[i] = circles[currentMinIndex];
            circles[currentMinIndex] = temp;
        }
    }
}

void printCircles(const Circle circles[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "Circle " << i + 1 << ": radius "
                  << circles[i].getRadius() << ", area "
                  << circles[i].getArea() << std::endl;
    }
}

int main()
{
    const int size = 5;
    Circle circles[size] = {Circle(5.0), Circle(2.5), Circle(8.0), Circle(1.0), Circle(3.5)};

    std::cout << "Before sorting:" << std::endl;
    printCircles(circles, size);

    sortCircles(circles, size);

    std::cout << std::endl << "After sorting by radius:" << std::endl;
    printCircles(circles, size);

    return 0;
}
