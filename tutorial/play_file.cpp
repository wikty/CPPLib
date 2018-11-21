#include <iostream>
#include <fstream>
#include <cstdio>

int main(int argc, char const *argv[])
{
    // read
    std::ifstream in("play_file.cpp");
    if (not in)
    {
        std::perror("Cannot open file");
    }
    else
    {
        char c;
        while (in >> c)
        {
            std::cout << c;
        }
        std::cout << std::endl;
        in.close();
    }

    // write
    std::ofstream out("test.txt");
    if (not out)
    {
        std::perror("Cannot open file");
    }
    else
    {
        for (int i(0); i <= 10; i++)
        {
            out << i << std::endl;
        }
        out.close();
    }

    return 0;
}