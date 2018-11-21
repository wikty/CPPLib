#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

int main(int argc, char const *argv[])
{
    // vector is like a dynamic array
    std::vector<int> data;
    std::cout << "begin == end"
              << (data.begin() != data.end())
              << '\n';
    
    // push input into vector
    int x;
    std::cout << "Please input integers:\n";
    while (std::cin >> x)
    {
        data.push_back(x);
    }
    std::cin.clear();
    std::cout << "Please input integers again:\n";
    // push input into vector
    data.insert(data.end(), 
                std::istream_iterator<int>(std::cin),
                std::istream_iterator<int>());
    // push input into vector
    std::cin.clear();
    std::cout << "Please input integers again:\n";
    std::copy(std::istream_iterator<int>(std::cin),
              std::istream_iterator<int>(),
              std::back_inserter(data));

    // output
    std::copy(data.begin(), data.end(),
              std::ostream_iterator<int>(std::cout, "\n"));
    
    // front and back
    std::cout << "Front " << data.front()
              << "Back " << data.back()
              << "Empty" << data.empty()
              << '\n';
    
    // sort and reverse
    std::sort(data.begin(), data.end());
    std::reverse(data.begin(), data.end());
    
    // for-in via size_type type
    for (std::vector<int>::size_type i(0); i < data.size(); i++)
    {
        std::cout << data[i] << std::endl;
        // the more recommended way to access vector
        std::cout << data.at(i) << std::endl;
    }
    // for-in via iterator
    for (std::vector<int>::iterator i(data.begin()); i != data.end(); i++)
    {
        // un-refer iterator
        std::cout << *i << std::endl;
    }

    // specify size and init value
    std::vector<int> full_of_zero_with_size_10(10);
    std::vector<int> full_of_one_with_size_10(10, 1);

    // nested vector
    // std::vector<std::vector<int>> v;  // Wrong!
    std::vector<std::vector<int> > v;

    // copy
    std::vector<int> input(3);
    std::vector<int> output(3);
    input.at(0) = 1;
    input.at(1) = 2;
    input.at(2) = 3;
    std::copy(input.begin(), input.end(), output.begin());
    std::vector<int> a({4, 5, 6});  // new syntax to init vector
    std::copy(a.begin(), a.end(), output.begin());

    return 0;
}