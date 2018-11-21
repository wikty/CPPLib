#include <iostream>

int main(int argc, char const *argv[])
{
    
    // cannot refer `i` out of the for loop
    for (int i(0); i<10; i++)
    {
        std::cout << i << '\n';
    }

    // init clause just run once time
    int x;
    for (int i(0), x=9; i<10; i++)
    {
        std::cout << x << '\n';
        // but you can refer `x` in the for loop
        x = i;
    }

    return 0;
}