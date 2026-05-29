#include <iostream>
#include <vector>

void factorize(int m, std::vector<int> &factors)
{
    int n = m;
    for (int p = 2; p * p <= n; p++)
    {
        while (n % p == 0)
        {
            factors.push_back(p);
            n /= p;
        }
    }
    if (n > 1)
    {
        factors.push_back(n);
    }
}

int main()
{
    int m = 0;
    std::cout << "Enter an integer m: ";
    std::cin >> m;

    if (m <= 0)
    {
        std::cout << "m must be positive." << std::endl;
        return 0;
    }

    std::vector<int> factors;
    factorize(m, factors);

    std::vector<int> oddFactors;
    for (int f : factors)
    {
        int count = 0;
        for (int g : factors)
        {
            if (g == f)
            {
                count++;
            }
        }
        if (count % 2 == 1)
        {
            bool already = false;
            for (int existing : oddFactors)
            {
                if (existing == f)
                {
                    already = true;
                    break;
                }
            }
            if (!already)
            {
                oddFactors.push_back(f);
            }
        }
    }

    int n = 1;
    for (int f : oddFactors)
    {
        n *= f;
    }

    std::cout << "The smallest number n for m * n to be a perfect square is " << n << std::endl;
    std::cout << "m * n is " << static_cast<long long>(m) * n << std::endl;

    return 0;
}
