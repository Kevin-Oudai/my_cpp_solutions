// Listing 3.8 - ChineseZodiac.cpp

#include <iostream>

using namespace std;

int main()
{
    cout << "Enter a year: ";
    int year;
    cin >> year;

    switch (year % 12)
    {
    case 0:
        cout << "monkey" << endl;
        break;
    case 1:
        cout << "rooster" << endl;
        break;
    case 2:
        cout << "dog" << endl;
        break;
    case 3:
        cout << "pig" << endl;
        break;
    case 4:
        cout << "rat" << endl;
        break;
    case 5:
        cout << "ox" << endl;
        break;
    case 6:
        cout << "tiger" << endl;
        break;
    case 7:
        cout << "rabbit" << endl;
        break;
    case 8:
        cout << "dragon" << endl;
        break;
    case 9:
        cout << "snake" << endl;
        break;
    case 10:
        cout << "horse" << endl;
        break;
    case 11:
        cout << "sheep" << endl;
        break;
    }

    return 0;
}