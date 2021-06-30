// Exercise 7.1 - Assign Grades

#include <iostream>

int main()
{
    const int ARRAY_LIMIT = 100;
    std::cout << "Enter the number of students: ";
    int numberOfStudents, bestScore = 0;
    std::cin >> numberOfStudents;

    int scores[ARRAY_LIMIT];

    std::cout << "Enter " << numberOfStudents << " scores: ";
    for (int i = 0; i < numberOfStudents; i++)
    {
        std::cin >> scores[i];
        if (scores[i] > bestScore)
        {
            bestScore = scores[i];
        }
    }

    for (int i = 0; i < numberOfStudents; i++)
    {
        std::cout << "Student " << i << " score is " << scores[i] << " and grade is ";
        if (scores[i] >= bestScore - 10)
        {
            std::cout << "A\n";
        }
        else if (scores[i] >= bestScore - 20)
        {
            std::cout << "B\n";
        }
        else if (scores[i] >= bestScore - 30)
        {
            std::cout << "C\n";
        }
        else if (scores[i] >= bestScore - 40)
        {
            std::cout << "D\n";
        }
        else
        {
            std::cout << "F\n";
        }
    }
    return 0;
}