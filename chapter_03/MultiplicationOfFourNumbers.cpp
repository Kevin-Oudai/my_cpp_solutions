// Listing 3.4 - SubtractionQuiz.cpp

#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
    // 1. Generate two random single-digit integers
    srand(time(0));
    int number1 = rand() % 5;
    int number2 = rand() % 5;
    int number3 = rand() % 5;
    int number4 = rand() % 5;

    // 3. Prompt the student to answer "what is number1 - number2?"
    std::cout << "What is " << number1 << " x " << number2
              << " x " << number3 << " x " << number4 << "? ";
    int answer;
    std::cin >> answer;

    // 4. Grade the answer and display the result
    if (number1 * number2 * number3 * number4 == answer)
        std::cout << "You are correct!";
    else
        std::cout << "Your answer is wrong. " << number1 << " x " << number2
                  << " x " << number3 << " x " << number4
                  << " should be " << (number1 * number2 * number3 * number4) << std::endl;

    return 0;
}