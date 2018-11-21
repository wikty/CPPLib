#include <iostream>
#include <ios>
#include <iomanip>

int main(int argc, char const *argv[])
{
    // I/O manipulator
    // set width
    std::cout << " N   N^2   N^3\n";
    for (int i = 1; i < 11; i++)
    {
        std::cout << std::setw(2) << i
                  << std::setw(6) << i * i
                  << std:: setw(6) << i * i * i
                  << '\n';
    }
    // fill
    int year(2018), month(8), day(1);
    std::cout << std::setfill('0')
              << "Year Month Day\n"
              << std::setw(4) << year << '/'
              << std::setw(2) << month << '/'
              << std::setw(2) << day << '\n';
    // align
    std::cout << std::setfill('-')
              << std::setw(6) << 123 << '\n'
              << std::left << std::setw(6) << 123 << '\n'
              << std::right << std::setw(6) << 123 << '\n';

    // member function
    std::cout.fill('*');
    std::cout.width(6);
    std::cout.setf(std::ios_base::left, std::ios_base::adjustfield);
    std::cout << 123 << '\n';

    // Print 9*9 table
    int const low(1);
    int const high(9);
    int const colwidth(4);
    // reset settings
    std::cout.fill(' ');
    std::cout << std::right;
    // header
    std::cout << std::setw(colwidth) << '*'
              << '|';
    for (int i(low); i <= high; i++)
    {
        std::cout << std::setw(colwidth) << i;
    }
    std::cout << '\n';
    std::cout.fill('-');
    std::cout << std::setw(colwidth) << ""
              << '+'
              << std::setw(high*colwidth) << ""
              << '\n';
    // body
    std::cout.fill(' ');
    for (int row(low); row <= high; row++)
    {
        std::cout << std::setw(colwidth) << row
                  << '|';
        for (int column(low); column <= high; column++)
        {
            std::cout << std::setw(colwidth) << row*column;
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}