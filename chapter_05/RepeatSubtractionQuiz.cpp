// Listing 5.1 - RepeatSubtractionQuiz.cpp
#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
    srand(time(0));
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

    while (number1 - number2 != answer)
    {
        std::cout << "Wrong answer. Try again. What is " << number1 << " - " << number2 << "? ";
        std::cin >> answer;
    }
    std::cout << "You got it!" << std::endl;
    return 0;
}