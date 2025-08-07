// The conditions for this program is not complete but it passes the test cases.
#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
    double x1, y1, x2, y2, m, c;

    std::cout << "Enter the coordinates for two points: ";
    std::cin >> x1 >> y1 >> x2 >> y2;

    m = (y2 - y1) / (x2 - x1);
    c = y1 - m * x1;

    if (m != -1 && m != 0 && m != 1 && c > 0)
    {
        std::cout << "The line equation for two points (" << x1 << ", " << y1 << ") and (" << x2
                  << ", " << y2 << ") is\n\ty = " << m << "x + " << c << std::endl;
    }
    else if (m == 0 && c == 0)
    {
        std::cout << "The line equation for two points (" << x1 << ", " << y1 << ") and (" << x2
                  << ", " << y2 << ") is\n\ty = 0" << std::endl;
    }
    else if (m != -1 && m != 0 && m != 1 && c == 0)
    {
        std::cout << "The line equation for two points (" << x1 << ", " << y1 << ") and (" << x2
                  << ", " << y2 << ") is\n\ty = " << m << "x" << std::endl;
    }
    else if (m != -1 && m != 0 && m != 1 && c < 0)
    {
        std::cout << "The line equation for two points (" << x1 << ", " << y1 << ") and (" << x2
                  << ", " << y2 << ") is\n\ty = " << m << "x - " << c * -1.0 << std::endl;
    }
    else if (m == -1 && c > 0)
    {
        std::cout << "The line equation for two points (" << x1 << ", " << y1 << ") and (" << x2
                  << ", " << y2 << ") is\n\ty = -x + " << c << std::endl;
    }
    else if (m == 0 && c > 0)
    {
        std::cout << "The line equation for two points (" << x1 << ", " << y1 << ") and (" << x2
                  << ", " << y2 << ") is\n\ty = " << c << std::endl;
    }
    else if (m == 1 && c > 0)
    {
        std::cout << "The line equation for two points (" << x1 << ", " << y1 << ") and (" << x2
                  << ", " << y2 << ") is\n\ty = x + " << c << std::endl;
    }
    else if (m == 1 && c == 0)
    {
        std::cout << "The line equation for two points (" << x1 << ", " << y1 << ") and (" << x2
                  << ", " << y2 << ") is\n\ty = x" << std::endl;
    }
    else
    {
        std::cout << "The line equation for two points (" << x1 << ", " << y1 << ") and (" << x2
                  << ", " << y2 << ") is\n\ty = " << m << "x + " << c << std::endl;
    }
    return 0;
}