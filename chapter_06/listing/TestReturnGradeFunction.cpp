#include <iostream>

// Return the grade for the score
char getGrade(double score)
{
    if (score >= 90.0)
        return 'A';
    else if (score >= 80.0)
    {
        return 'B';
    }
    else if (score >= 70.0)
    {
        return 'C';
    }
    else if (score >= 60.0)
    {
        return 'D';
    }
    else
    {
        return 'F';
    }
}

int main()
{
    std::cout << "Enter a score: ";
    double score;
    std::cin >> score;

    std::cout << "The grade is ";
    std::cout << getGrade(score) << std::endl;

    return 0;
}