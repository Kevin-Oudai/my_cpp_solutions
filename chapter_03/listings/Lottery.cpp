// Listing 3.7 - Lottery.cpp

#include <iostream>
#include <ctime>   // for time function
#include <cstdlib> // for rand and srand functions

using namespace std;

int main()
{
    // Generate a lottery
    srand(time(0));
    int lottery = rand() % 100;

    // Prompt the user to enter a guess
    cout << "Enter your lottery pick (two digits): ";
    int guess;
    cin >> guess;

    // Get digits from lottery
    int lotteryDigit1 = lottery / 10;
    int lotteryDigit2 = lottery % 10;

    // Get digits from guess
    int guessDigit1 = guess / 10;
    int guessDigit2 = guess % 10;

    cout << "The lottery number is " << lottery << endl;

    // Check the guess
    if (guess == lottery)
        cout << "Exact match: you win $10,000" << endl;
    else if (guessDigit2 == lotteryDigit1 &&
             guessDigit1 == lotteryDigit2)
        cout << "Match all digits: you win $3000" << endl;
    else if (guessDigit1 == lotteryDigit1 ||
             guessDigit1 == lotteryDigit2 ||
             guessDigit2 == lotteryDigit1 ||
             guessDigit2 == lotteryDigit2)
        cout << "Match one digit: you win $1000" << endl;
    else
        cout << "Sorry, no match" << endl;

    return 0;
}