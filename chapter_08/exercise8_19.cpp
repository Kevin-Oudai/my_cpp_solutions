#include <iostream>

bool isSafe(double loans[][100], int numberOfBanks, double limit, int bankNumber)
{
    double totalAssets = 0;
    for (int j = 0; j < numberOfBanks; j++)
    {
        totalAssets += loans[bankNumber][j];
    }
    if (totalAssets < limit && totalAssets != 0)
    {
        return false;
    }
    return true;
}

void removeBank(double loans[][100], int numberOfBanks, int bankNumber)
{
    for (int i = 0; i < numberOfBanks; i++)
    {
        loans[i][bankNumber] = 0;
        loans[bankNumber][i] = 0;
    }
}

void populateTable(double loans[][100], int numberOfBanks)
{
    int numberOfLoans, bankId;
    std::cout << std::endl;
    for (int i = 0; i < numberOfBanks; i++)
    {
        std::cin >> loans[i][i];
        std::cin >> numberOfLoans;
        for (int j = 0; j < numberOfLoans; j++)
        {
            std::cin >> bankId;
            std::cin >> loans[i][bankId];
        }
    }
}

int main()
{
    double loans[100][100] = {};
    std::cout << "Enter the number of banks: ";
    int n;
    std::cin >> n;
    std::cout << "Enter the limit: ";
    double limit;
    std::cin >> limit;
    populateTable(loans, n);
    std::cout << "Unsafe banks are ";
    for (int i = 0; i < n; i++)
    {
        if (!isSafe(loans, n, limit, i))
        {
            removeBank(loans, n, i);
            std::cout << i << " ";
            i = 0;
        }
    }

    return 0;
}
