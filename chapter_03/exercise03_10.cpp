// Listing 3.4 - SubtractionQuiz.cpp

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    // 1. Generate two random single-digit integers
    srand(time(0));
    int number1 = rand() % 10;
    int number2 = rand() % 10;

    // 3. Prompt the student to answer "what is number1 - number2?"
    cout << "What is " << number1 << " x " << number2 << "? ";
    int answer;
    cin >> answer;

    // 4. Grade the answer and display the result
    if (number1 * number2 == answer)
        cout << "You are correct!";
    else
        cout << "Your answer is wrong. " << number1 << " x " << number2
             << " should be " << (number1 * number2) << endl;

    return 0;
}