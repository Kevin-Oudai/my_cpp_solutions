// Listing 5.4 - SubtractionQuizLoop.cpp

#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
    int correctCount = 0;
    int count = 0;
    long startTime = time(0);
    const int NUMBER_OF_QUESTIONS = 5;

    srand(time(0));

    while (count < NUMBER_OF_QUESTIONS)
    {
        int number1 = rand() % 10;
        int number2 = rand() % 10;

        if (number1 < number2)
        {
            int temp = number1;
            number1 = number2;
            number2 = temp;
        }

        std::cout << "What is " << number1 << " - " << number2 << "? ";
        int answer;
        std::cin >> answer;

        if (number1 - number2 == answer)
        {
            std::cout << "You are correct!\n";
            correctCount++;
        }
        else
            std::cout << "Your answer is wrong.\n"
                      << number1 << " - " << number2
                      << " should be " << (number1 - number2) << std::endl;
        count++;
    }

    long endTime = time(0);
    long testTime = endTime - startTime;

    std::cout << "Correct count is " << correctCount << "\nTest time is "
              << testTime << " seconds\n";

    return 0;
}