#include <iostream>
#include <vector>
#include <ios>

int main(int argc, char const *argv[])
{
    // stdin and stdout
    std::cout << "true=" << true << std::endl;
    std::cout << "false=" << false << std::endl;
    std::cout << std::boolalpha;
    std::cout << "true=" << true << std::endl;
    std::cout << "false=" << false << std::endl;
    std::cout << std::noboolalpha;

    // built-in type auto-convert
    bool b;
    std::cout << std::boolalpha;
    b = 42;  // true
    std::cout << b << std::endl;
    b = '\0';  // false
    std::cout << b << std::endl;
    b = "";  // ture
    std::cout << b << std::endl;
    std::cout << std::noboolalpha;

    // cannot auto-convert string and vector
    std::string empty;
    // b = empty;
    std::vector<char> v;
    // b = v;

    // (and, or, not) is more readable than (&&, ||, !)
    int i(0);
    int j(1);
    std::cout << i << std::endl;
    if (j == 1 and ++i)
    {
        ++i;
    }
    std::cout << i << std::endl;
    if (j == 2 and i++)
    {
        ++i;
    }
    std::cout << i << std::endl;

    // compare string and vector
    std::cout << std::boolalpha;
    std::string s1("abc"), s2("abb");
    std::vector<int> v1({1, 2, 3}), v2({1, 2, 2});
    std::cout << (s1 > s2) << std::endl;
    std::cout << (v1 > v2) << std::endl;

    // Don't compare string const
    std::cout << ("abc" > "abb") << std::endl;

    return 0;
}