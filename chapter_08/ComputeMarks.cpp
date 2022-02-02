// Exercise 8.4 - Compute total marks for each student

#include <iostream>

const int NUMBER_OF_STUDENTS = 8;
const int NUMBER_OF_TESTS = 5;

void selectionSort(int list[][2])
{
    for (int i = 0; i < NUMBER_OF_STUDENTS - 1; i++)
    {
        double currentMin = list[i][1];
        int currentMinIndex = i;
        int currentMinStudent = list[i][0];

        for (int j = i + 1; j < NUMBER_OF_STUDENTS; j++)
        {
            if (currentMin < list[j][1]) // Changing this from less than to greater than changes the order of the list
            {
                currentMin = list[j][1];
                currentMinStudent = list[j][0];
                currentMinIndex = j;
            }
        }

        if (currentMinIndex != i)
        {
            list[currentMinIndex][0] = list[i][0];
            list[currentMinIndex][1] = list[i][1];
            list[i][0] = currentMinStudent;
            list[i][1] = currentMin;
        }
    }
}

int main()
{
    int data[NUMBER_OF_STUDENTS][NUMBER_OF_TESTS] = {
        {12, 14, 13, 14, 15},
        {17, 13, 14, 13, 13},
        {13, 13, 14, 13, 13},
        {19, 13, 14, 17, 13},
        {13, 15, 14, 13, 16},
        {13, 14, 14, 16, 13},
        {13, 17, 14, 18, 13},
        {16, 13, 15, 19, 12}};

    int result[NUMBER_OF_STUDENTS][2];

    for (int i = 0; i < NUMBER_OF_STUDENTS; i++)
    {
        int studentTotal = 0;
        for (int j = 0; j < NUMBER_OF_TESTS; j++)
        {
            studentTotal += data[i][j];
        }
        result[i][0] = i;
        result[i][1] = studentTotal;
    }
    selectionSort(result);
    for (int i = 0; i < NUMBER_OF_STUDENTS; i++)
    {
        std::cout << "Student: " << result[i][0] << " Score: " << result[i][1] << std::endl;
    }
    return 0;
}