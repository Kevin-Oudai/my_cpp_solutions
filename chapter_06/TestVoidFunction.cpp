#include <iostream>

void printGrade(double score)
{
    if (score >= 90.0)
        std::cout << 'A' << std::endl;
    else if (score >= 80.0)
        std::cout << 'B' << std::endl;
    else if (score >= 70.0)
    {
        std::cout << 'C' << std::endl;
    }
    else if (score >= 60.0)
    {
        std::cout << 'D' << std::endl;
    }
    else
        std::cout << 'F' << std::endl;
}

int main()
{
    std::cout << "Enter a score: ";
    double score;
    std::cin >> score;
    std::cout << "The grade is ";
    printGrade(score);

    return 0;
}