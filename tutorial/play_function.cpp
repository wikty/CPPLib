#include <iostream>
#include <vector>
#include <iterator>

// 函数声明：函数名、函数返回类型、函数形参类型
void print1(std::vector<int> v);
void print2(std::vector<int> const& v);
void square1(std::vector<int> v);
void square2(std::vector<int>& v);
void modify1(int& x);
void modify2(int const& x);
int add(int x, int y);
int add(int x);
std::vector<int> add(std::vector<int> const& x, std::vector<int> const& y);


int main(int argc, char const *argv[])
{
    std::vector<int> v({ 1, 2, 3 });
    print1(v);  // 函数调用，传递实参，实参会被赋值给形参

    square1(v);
    print1(v);

    square2(v);
    print2(v);

    std::cout << add(3, 4)
        << std::endl
        << add(3)
        << std::endl;

    print2(add(v, std::vector<int>({ -1, -1, -1 })));

    // main 函数返回值给操作系统
    return 0;
}

// 函数定义：函数主体内容，形参名可以跟声明不一致，其它要一致
void print1(std::vector<int> v)
{
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, "\n"));
}

// 按值传递：实参变量的值复制到形参变量中
// 按值传递需要完成复制过程，对较大的对象有性能损耗，并且对形参的修改不会影响到实参
void square1(std::vector<int> v)
{
    for (std::vector<int>::iterator i(v.begin());
        i != v.end();
        i++)
    {
        *i = (*i) * (*i);
    }
}

// 按引用传递：形参是对实参的引用
// 不涉及到复制，形参可以看成是实参的别名，只有左值变量才能作为实参传递
void square2(std::vector<int>& v)
{
    for (std::vector<int>::iterator i(v.begin());
        i != v.end();
        i++)
    {
        *i = (*i) * (*i);
    }
}

// 常量引用：当不希望函数内容修改实参，同时又不想要值传递时
// 关于 const 的书写位置：
// std::vector<int> const& v
// const std::vector<int>& v
// 都是可以的，不过推荐前者，即将 const 离被修饰名字更近一点
void print2(std::vector<int> const& v)
{
    // 注：常量引用时，函数内部要结合 const_iterator 使用，以避免对形参修改
    for (std::vector<int>::const_iterator i(v.begin());
        i != v.end();
        i++)
    {
        std::cout << *i << std::endl;
    }
}

// 引用可以作用于整型
// 但注意实参不能是右值，如：modify(2) 会报错
void modify1(int& x)
{
    x = -1;
}

// 常量引用可以作用于整型
// 但注意不能在函数中修改它，不过可以将右值作为实参传递
void modify2(int const& x)
{
    x * 1;
}

// 函数重载机制：同一个函数名，只要接口不一样，可以重用多次
int add(int x, int y)
{
    return x + y;
}

int add(int x)
{
    return x + x;
}

std::vector<int> add(std::vector<int> const& x, std::vector<int> const& y)
{
    std::vector<int> result;
    for (std::vector<int>::const_iterator i(x.begin()), j(y.begin());
        i != x.end();
        i++, j++)
    {
        result.push_back((*i) + (*j));
    }
    return result;
}