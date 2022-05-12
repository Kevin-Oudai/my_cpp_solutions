// Exercise 5.2 - Repeat Multiplications
// Revision of Listing 5.4 - SubtractionQuizLoop.cpp

#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
    int correctCount = 0;
    int count = 0;
    long startTime = time(0);
    const int NUMBER_OF_QUESTIONS = 9;

    srand(time(0));

    while (count < NUMBER_OF_QUESTIONS)
    {
        int number1 = (rand() % 5) + 1;
        int number2 = (rand() % 5) + 1;
        int number3 = (rand() % 5) + 1;

        std::cout << "What is " << number1 << " x " << number2 << " x " << number3 << "? ";
        int answer;
        std::cin >> answer;

        if (number1 * number2 * number3 == answer)
        {
            std::cout << "You are correct!\n";
            correctCount++;
        }
        else
            std::cout << "Your answer is wrong.\n"
                      << number1 << " x " << number2
                      << " x " << number3
                      << " should be " << (number1 * number2 * number3) << std::endl;
        count++;
    }

    long endTime = time(0);
    long testTime = endTime - startTime;

    std::cout << "Correct count is " << correctCount << "\nTest time is "
              << testTime << " seconds\n";

    return 0;
}