#include <iostream>
void displayPoints(int m[][2], int numberOfRows)
{
    for (int i = 0; i < 6; i++)
    {
        std::cout << "(" << m[i][0] << ", " << m[i][1] << "), " << std::endl;
    }
}
void switchPoints(int m[][2], int position)
{
    int temp[2];
    temp[0] = m[position][0];
    temp[1] = m[position][1];
    m[position][0] = m[position + 1][0];
    m[position][1] = m[position + 1][1];
    m[position + 1][0] = temp[0];
    m[position + 1][1] = temp[1];
}
void reverseSort(int m[][2], int numberOfRows)
{
    for (int j = 0; j < numberOfRows; j++)
    {
        for (int i = 0; i < numberOfRows - 1; i++)
        {
            if (m[i][0] < m[i + 1][0])
            {
                switchPoints(m, i);
            }
            else if ((m[i][0] == m[i + 1][0]) && (m[i][1] < m[i + 1][1]))
            {
                switchPoints(m, i);
            }
        }
    }
    displayPoints(m, numberOfRows);
}
int main()
{
    int points[12][2] = {};
    std::cout << "Enter 12 points: ";
    for (int i = 0; i < 12; i++)
    {
        std::cin >> points[i][0] >> points[i][1];
    }
    reverseSort(points, 12);

    // Test script
    // int points[6][2] = {{9, 7}, {6, 12}, {9, 10}, {6, 7}, {6, 6}, {9, 6}};
    // reverseSort(points, 6);

    return 0;
}