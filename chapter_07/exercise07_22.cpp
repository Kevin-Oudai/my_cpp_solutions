// Create 2 dice arrays
// Return dice values if the match the integer value
#include <iostream>
int main()
{
    int dice[6] = {1, 2, 3, 4, 5, 6};
    int value;
    std::cout << "Enter the value you wish to get from two dies: ";
    std::cin >> value;
    if (value >= 2 && value <= 12)
    {
        std::cout << "To get the value of " << value << " on two dies the following combinations are possible." << std::endl;
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (value == dice[i] + dice[j])
                {
                    std::cout << "\t(1st Dice) " << dice[i] << " && (2nd Dice) " << dice[j] << std::endl;
                }
            }
        }
    }
    else
    {
        std::cout << "That value is not possible with 2 dies." << std::endl;
    }

    return 0;
}