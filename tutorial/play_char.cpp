// * 字符在计算机中编码为数字
// * 不同编码方案涵盖的字符集是不同的
// * 不同编码方案对同一个字符的编码值也可能是不同的
// * C++ 标准没有强制要求使用特定编码方案
// * 显然我们需要在处理输入输出时，隐式或显式指定编码方案
#include <ios>
#include <iostream>
#include <vector>
#include <utility>

typedef std::pair<int, int> point;

char read_char1()
{
    // read a char even if it is a spacing
    char ch;
    std::cin.get(ch);
    return ch;
}

char read_char2()
{
    // read a char even if it is a spacing
    char ch;
    std::cin >> std::noskipws >> ch >> std::skipws;
    return ch; 
}

std::vector<point> read_points()
{
    std::vector<point> v;
    int x(0), y(0);
    char sep(' ');
    while (std::cin >> x >> sep and sep == ',' and std::cin >> y)
    {
        point p;
        p.first = x;
        p.second = y;
        v.push_back(p);
    }
    return v;
}

int main(int argc, char const *argv[])
{
    char ch;
    ch = read_char1();
    std::cout << '*' << ch << '*' << std::endl;

    std::vector<point> v;
    v = read_points();
    for (std::vector<point>::iterator i(v.begin()); i != v.end(); i++)
    {
        std::cout << '(' 
                  << i->first 
                  << ',' 
                  << i->second 
                  << ')'
                  << std::endl;
    }
    return 0;
}