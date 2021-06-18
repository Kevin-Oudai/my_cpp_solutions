// Exercise 5.55 - Math Tutor

#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
    srand(time(0));
    int choice = 0;
    double num1, num2, answer, temp;
    while (choice != 5)
    {
        std::cout << "Main Menu" << std::endl;
        std::cout << "1: Addition" << std::endl;
        std::cout << "2: Subtraction" << std::endl;
        std::cout << "3: Multiplication" << std::endl;
        std::cout << "4: Division" << std::endl;
        std::cout << "5: Exit" << std::endl;
        std::cout << "Enter a choice: ";
        std::cin >> choice;
        if (choice == 1)
        {
            num1 = rand() % 10;
            num2 = rand() % 10;
            std::cout << "What is " << num1 << " + " << num2 << "? ";
            std::cin >> answer;
            if (answer == num1 + num2)
            {
                std::cout << "Your answer is correct.\n";
            }
            else
            {
                std::cout << "Your answer is wrong. The correct answer is " << num1 + num2 << std::endl;
            }
        }
        else if (choice == 2)
        {
            num1 = rand() % 10;
            num2 = rand() % 10;
            if (num1 > num2)
            {
                std::cout << "What is " << num1 << " - " << num2 << "?\n";
                std::cin >> answer;
                if (num1 - num2 == answer)
                {
                    std::cout << "You are correct.\n";
                }
                else
                {
                    std::cout << "You are wrong. The correct answer is " << num1 - num2 << ".\n";
                }
            }
            else
            {
                std::cout << "What is " << num2 << " - " << num1 << "?\n";
                std::cin >> answer;
                if (num2 - num1 == answer)
                {
                    std::cout << "You are correct.\n";
                }
                else
                {
                    std::cout << "You are wrong. The correct answer is " << num2 - num1 << ".\n";
                }
            }
        }
        else if (choice == 3)
        {
            num1 = rand() % 10;
            num2 = rand() % 10;
            std::cout << "What is " << num1 << " * " << num2 << "?\n";
            std::cin >> answer;
            (num1 * num2 == answer) ? std::cout << "You are correct.\n" : std::cout << "You are wrong. The correct answer is " << num1 * num2 << std::endl;
        }
        else if (choice == 4)
        {
            num1 = rand() % 10;
            num2 = rand() % 10;
            while (num2 == 0)
            {
                num2 = rand() % 10;
            }
            std::cout << "What is " << num1 << " / " << num2 << "?\n";
            std::cin >> answer;
            (num1 / num2 == answer) ? std::cout << "You are correct.\n" : std::cout << "You are wrong. The correct answer is " << num1 / num2 << std::endl;
        }
        else if (choice == 5)
        {
            std::cout << "Bye Bye!\n";
            break;
        }
        else
        {
            continue;
        }
    }
}