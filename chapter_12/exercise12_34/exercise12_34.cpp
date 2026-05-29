#include <iostream>
#include <random>
#include <vector>

int main()
{
    std::mt19937 gen(static_cast<unsigned int>(std::random_device{}()));
    std::uniform_int_distribution<int> dist(0, 9);

    int n1 = dist(gen);
    int n2 = dist(gen);
    if (n1 < n2)
    {
        std::swap(n1, n2);
    }

    const int correct = n1 - n2;
    std::vector<int> attempts;

    std::cout << "What is " << n1 << " - " << n2 << "? ";
    int answer = 0;
    while (std::cin >> answer)
    {
        if (answer == correct)
        {
            std::cout << "You got it!" << std::endl;
            break;
        }

        bool seen = false;
        for (int v : attempts)
        {
            if (v == answer)
            {
                seen = true;
                break;
            }
        }

        if (seen)
        {
            std::cout << "You already entered " << answer << std::endl;
        }
        else
        {
            attempts.push_back(answer);
            std::cout << "Wrong answer. Try again." << std::endl;
        }

        std::cout << "What is " << n1 << " - " << n2 << "? ";
    }

    return 0;
}
