// Exercise 8.3 - Sort and display students
// Revision: Listing 8.2 - GradeExam.cpp

#include <iostream>

int main()
{
    const int NUMBER_OF_STUDENTS = 8;
    const int NUMBER_OF_QUESTIONS = 10;

    // Students' answers to the questions
    char answers[NUMBER_OF_STUDENTS][NUMBER_OF_QUESTIONS] =
        {
            {'A', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
            {'D', 'B', 'A', 'B', 'C', 'A', 'E', 'E', 'A', 'D'},
            {'E', 'D', 'D', 'A', 'C', 'B', 'E', 'E', 'A', 'D'},
            {'C', 'B', 'A', 'E', 'D', 'C', 'E', 'E', 'A', 'D'},
            {'A', 'B', 'D', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
            {'B', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
            {'B', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
            {'E', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}};

    // Key to the questions
    char keys[] = {'D', 'B', 'D', 'C', 'C', 'D', 'A', 'E', 'A', 'D'};

    // Grade all answers
    int correctCount = 0;
    for (int i = NUMBER_OF_STUDENTS; i >= 0; i--)
    {
        // Grade one student
        int correctCount = 0;
        for (int j = 0; j < NUMBER_OF_QUESTIONS; j++)
        {
            if (answers[i][j] == keys[j])
            {
                correctCount++;
            }
        }
        if (correctCount >= 6)
        {
            std::cout << "Student " << i << "'s correct count is " << correctCount << std::endl;
        }
    }
    return 0;
}