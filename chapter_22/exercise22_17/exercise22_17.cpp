#include <iostream>
#include <set>

int main()
{
    int questions[][2] = {
        {9, 3}, {12, 5}, {14, 9}, {7, 2}, {18, 11}
    };
    std::set<int> answers;

    for (int i = 0; i < 5; i++)
    {
        int answer;
        std::cout << "What is " << questions[i][0] << " - " << questions[i][1] << "? ";

        if (!(std::cin >> answer))
        {
            answer = questions[i][0] - questions[i][1];
            std::cout << answer << std::endl;
        }

        answers.insert(answer);
    }

    std::cout << "Distinct answers: ";
    for (std::set<int>::iterator iterator = answers.begin(); iterator != answers.end(); iterator++)
        std::cout << *iterator << " ";
    std::cout << std::endl;

    return 0;
}
