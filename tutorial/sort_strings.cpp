// read and sort strings
#include <algorithm>
#include <iostream>
#include <fstream>
#include <ostream>
#include <iterator>
#include <string>
#include <vector>

void read(std::istream& in, std::vector<std::string>& lines)
{
    std::string line;
    while (std::getline(in, line))
    {
        lines.push_back(line);
    }
}

int main(int argc, char* argv[])
{
    std::vector<std::string> text;

    // read
    if (argc < 2)
    {
        // read strings from stdin
        // Note: Ctrl+D or Ctrl+Z to end of input
        read(std::cin, text);
    }
    else
    {
        // read strings from file
        std::ifstream in(argv[1]);
        if (not in)
        {
            std::perror(argv[1]);
            return EXIT_FAILURE;
        }
        read(in, text);
    }

    // sort
    std::sort(text.begin(), text.end());

    // output
    std::copy(text.begin(), text.end(),
              std::ostream_iterator<std::string>(std::cout, "\n"));

    return 0;
}