// Exercise 6.37 - Financial: Credit Card Number Validation

#include <iostream>
#include <string>

// Return true if the card number is valid
bool isValid(const std::string &cardNumber);
// Get the result from step 2
int sumOfDoubleEvenPlace(const std::string &cardNumber);
// Return this number if it is a single digit, otherwise,
// return the sum of the digits
int getDigit(int number);
// Return sum of odd-place digits in the card number
int sumOfOddPlace(const std::string &cardNumber);
// Return true if substr is the prefix for cardNumber
bool startsWith(const std::string &cardNumber, const std::string &substr);

int main()
{
    std::cout << "Enter a credit card number: ";
    std::string cardNumber;
    std::getline(std::cin, cardNumber);

    bool valid = isValid(cardNumber);
    (valid)
        ? std::cout << cardNumber << " is a valid credit card number. " << std::endl
        : std::cout << cardNumber << " is NOT a valid credit card number." << std::endl;
    return 0;
}

bool isValid(const std::string &cardNumber)
{
    int stepTwo = sumOfDoubleEvenPlace(cardNumber);
    int stepThree = sumOfOddPlace(cardNumber);

    int stepFour = stepTwo + stepThree;
    if (stepFour % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int sumOfDoubleEvenPlace(const std::string &cardNumber)
{
    std::string reverseNumber = "";
    for (int i = 0; i < cardNumber.length(); i++)
    {
        reverseNumber = cardNumber.at(i) + reverseNumber;
    }
    int sum = 0, extract;
    for (int j = 0; j < cardNumber.length(); j++)
    {
        if (j % 2 == 1)
        {
            extract = static_cast<int>(reverseNumber.at(j) - '0');
            sum += getDigit(extract);
        }
    }
    return sum;
}

int getDigit(int number)
{
    number *= 2;
    if (number > 9)
    {
        return ((number / 10) + (number % 10));
    }
    return number;
}

int sumOfOddPlace(const std::string &cardNumber)
{
    std::string reverseNumber = "";
    for (int i = 0; i < cardNumber.length(); i++)
    {
        reverseNumber = cardNumber.at(i) + reverseNumber;
    }
    int sum = 0, extract;
    for (int j = 0; j < cardNumber.length(); j++)
    {
        if (j % 2 == 0)
        {
            extract = static_cast<int>(reverseNumber.at(j) - '0');
            sum += extract;
        }
    }
    return sum;
}