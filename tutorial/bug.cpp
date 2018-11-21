#include <iostream>

int main(int argc, char* argv[])
{
    // divide zero
    int x = 9;
    int y(0);
    std::cout << x / y;

    // equal test with assign operator
    if (y = 0)
    {
        std::cout << "zero";
    }
}