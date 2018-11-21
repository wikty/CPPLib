#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>


int main(int argc, char const *argv[])
{
    // init
    std::vector<int> data({ 1, 2, 3, 4 });
    // reverse
    for (std::vector<int>::iterator start(data.begin()), end(data.end());
         start != end and start != --end;
         ++start)
    {
        int temp = *start;
        *start = *end;
        *end = temp;
    }
    // reverse again
    std::reverse(data.begin(), data.end());
    // output
    std::copy(data.begin(), data.end(), 
              std::ostream_iterator<int>(std::cout, "\n"));

    return 0;
}