// Listing 9.12 - HideDataField.cpp
#include <iostream>

class Foo
{
public:
    int x; // Data field
    int y; // Data field

    Foo()
    {
        x = 10;
        y = 10;
    }

    void p()
    {
        int x = 20; // Local variable
        std::cout << "x is " << x << std::endl;
        std::cout << "y is " << y << std::endl;
    }
};

int main()
{
    Foo foo;
    foo.p();

    return 0;
}