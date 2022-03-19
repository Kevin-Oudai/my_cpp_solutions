// This program assumes that the second rectangle has a smaller area than the first rectangle.
#include <iostream>

int main()
{
    double x1, y1, h1, w1, x2, y2, h2, w2, lowerX1, lowerX2, upperX1;
    double upperX2, lowerY1, lowerY2, upperY1, upperY2;
    bool Xinside, Yinside, Youtside, Xoutside;

    std::cout << "Enter r1's center x-, y-coordinates, width, and height: ";
    std::cin >> x1 >> y1 >> w1 >> h1;
    // Defines the boundaries for the larger rectangle
    lowerX1 = x1 - w1 / 2.0;
    upperX1 = x1 + w1 / 2.0;
    lowerY1 = y1 - h1 / 2.0;
    upperY1 = y1 + h1 / 2.0;

    std::cout << "Enter r2's center x-, y-coordinates, width, and height: ";
    std::cin >> x2 >> y2 >> w2 >> h2;
    // Defines the boundaries for the smaller rectangle
    lowerX2 = x2 - w2 / 2.0;
    upperX2 = x2 + w2 / 2.0;
    lowerY2 = y2 - h2 / 2.0;
    upperY2 = y2 + h2 / 2.0;

    // Checks if the boundaries of the smaller rectangle are inside the larger rectangle
    Xinside = lowerX1 <= lowerX2 && lowerX1 <= upperX2 && upperX1 >= lowerX2 && upperX1 >= upperX2;
    Yinside = lowerY1 <= lowerY2 && lowerY1 <= upperY2 && upperY1 >= lowerY2 && upperY1 >= upperY2;

    // Checks if the boundaries of the smaller rectangle are outside of the larger rectangle
    Xoutside = (lowerX1 > lowerX2 && lowerX1 > upperX2) || (upperX1 < lowerX2 && upperX1 < upperX2);
    Youtside = (lowerY1 > lowerY2 && lowerY1 > upperY2) || (upperY1 < lowerY2 && upperY1 < upperY2);

    if (Xinside && Yinside)
        std::cout << "r2 is inside r1" << std::endl;
    else if (Xoutside & Youtside)
    {
        std::cout << "r2 does not overlap r1" << std::endl;
    }
    // Condition for when the two rectangles overlap i.e. if it is not inside or outside then it overlaps.
    else
        std::cout << "r2 overlaps r1" << std::endl;

    return 0;
}