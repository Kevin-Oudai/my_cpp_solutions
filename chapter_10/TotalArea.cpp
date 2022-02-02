// Listing 10.5 - TotalArea.cpp

#include <iostream>
#include <iomanip>
#include "CircleWithPrivateDataFields.h"

// Add circle areas
double sum(Circle circleArray[], int size)
{
    // Initialize sum
    double sum = 0;

    // Add areas to sum
    for (int i = 0; i < size; i++)
        sum += circleArray[i].getArea();

    return sum;
}

// Print an array of circles and their total area
void printCircleArray(Circle circleArray[], int size)
{
    std::cout << std::setw(35) << std::left << "Radius" << std::setw(8) << "Area" << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << std::setw(8) << std::left << circleArray[i].getRadius() << std::setw(8) << circleArray[i].getArea() << std::endl;
    }
    std::cout << "-------------------------------------------------------------" << std::endl;

    // Compute and display the result
    std::cout << std::setw(35) << std::left << "The total area of circles is " << std::setw(8) << sum(circleArray, size) << std::endl;
}

int main()
{
    const int SIZE = 10;

    // Create a Circle object with radius 1
    Circle circleArray[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        circleArray[i].setRadius(i + 1);
    }

    printCircleArray(circleArray, SIZE);

    return 0;
}