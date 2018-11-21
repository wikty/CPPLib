// * 世界上不同地区使用的数字、货币、日期、字母、标点等是不同的。
// * 程序应该根据用户所使用的地区设置，来灵活的处理这些数据，这个就是程序的本地化问题。
// * C++ 中的所有 I/O 流对象都可以设置地区属性，以指定对输入输出数据的处理方式
#include <iostream>
#include <locale>

int main(int argc, char const *argv[])
{
    // 经典的区域设置
    std::locale classic(std::locale::classic());
    // 用户本地的区域设置
    std::locale local(std::locale(""));

    // config I/O
    std::cin.imbue(local);
    std::cout.imbue(classic);

    char ch;
    std::cin.get(ch);
    if (std::isalnum(ch, local))
    {
        std::cout << ch << std::endl;
    }
    else
    {
        std::cout << ch << "is invalid alnum char." << std::endl;
    }

    char a('a'), A('A');
    std::cout << a << std::islower(a, local) << std::endl;
    std::cout << A << std::tolower(A, local) << std::endl;

    return 0;
}