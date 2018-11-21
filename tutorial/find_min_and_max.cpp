#include <iostream>
#include <limits>

int main(int argc, char* argv[])
{
    int x;
    bool any(false);  // init variable
    int min(std::numeric_limits<int>::max());
    int max(std::numeric_limits<int>::min());
    while (std::cin >> x)
    {
        any = true;
        if (x < min)
        {
            min = x;
        }
        if (x > max)
        {
            max = x;
        }
    }

    if (any)
    {
        // char with '' and string with "" 
        std::cout << "min = " << min << "\nmax = " << max << '\n';
    }
}