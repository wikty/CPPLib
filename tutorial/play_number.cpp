#include <iostream>
#include <limits>
#include <string>

typedef signed char byte;


template<typename T>
void print_int_digits(std::string const& msg) {
    if (std::numeric_limits<T>::is_signed) {
        std::cout << msg << ": " << std::numeric_limits<T>::digits + 1 << '\n';
    }
    else {
        std::cout << msg << ": " << std::numeric_limits<T>::digits << '\n';
    }
}

template<typename T>
void print_real_info() {
    std::cout << "min=" << std::numeric_limits<T>::min() << '\n';
    std::cout << "max=" << std::numeric_limits<T>::max() << '\n';
    std::cout << "radix=" << std::numeric_limits<T>::radix << '\n';
    std::cout << "digits=" << std::numeric_limits<T>::digits << '\n';
    std::cout << "has infinity? " << std::numeric_limits<T>::has_infinity << '\n';
    std::cout << "has quiet NaN?" << std::numeric_limits<T>::has_quiet_NaN << '\n';
    std::cout << "has signaling NaN?" << std::numeric_limits<T>::has_signaling_NaN << '\n';

    if (std::numeric_limits<T>::has_infinity) {
        std::cout << std::numeric_limits<T>::infinity() << '\n';
    }
    if (std::numeric_limits<T>::has_quiet_NaN) {
        std::cout << 0.0/0.0 << '\n';
    }
}

void print_int(byte x) {
    // 必须强制转换为整数才能够在标准输出中以数字输出，否则以字符输出
    std::cout << "byte=" << static_cast<int>(x) << std::endl;
}

void print_int(short x) {
    std::cout << "short=" << x << std::endl;
}

void print_int(int x) {
    std::cout << "int=" << x << std::endl;
}

void print_int(long x) {
    std::cout << "long=" << x << std::endl;
}

void print_real(float x) {
    std::cout << "float=" << x << std:: endl;
}

void print_real(double x) {
    std::cout << "double=" << x << std::endl;
}

void print_real(long double x) {
    std::cout << "long double=" << x << std::endl;
}


int main(int argc, char const *argv[]) {
    // 2^8 = 256
    // 2^15 = 32768
    // 2^16 = 65536
    // 2^31 = 2147483648
    // 2^32 = 4294967296

    // C++ 标准要求编译器支持的整数最小取值范围
    // http://www.cplusplus.com/reference/climits/
    // signed char: C++ standard minimum range [-127, 127]
    // 最小整数类型，注它不是字符类型
    // 一般通过 typedef signed char byte; 来使用
    signed char sci;
    byte sci1;
    print_int_digits<byte>("byte");
    // short int: C++ standard minimum range [-32767, 32767]
    short int si;
    short si1;
    print_int_digits<short>("short");
    // int: C++ standard minimum range [-32767, 32767]
    int i;
    print_int_digits<int>("int");
    // long int: C++ standard minimum range [-2147483647, 2147483647]
    long int li;
    long li1;
    print_int_digits<long>("long");

    // 强制类型转换
    print_int(0); // 字面整数 int
    print_int(0L); // 字面整数 long
    print_int(static_cast<short>(0)); // 强制将字面整数 int 转换为 short
    print_int(static_cast<signed char>(0)); // 强制将字面整数 int 转换为 signed char
    print_int(static_cast<signed char>(128));  // 强制转换后丢失信息

    // 类型提升：运算时 signed char 和 short 会被提升为 int
    print_int(0 + static_cast<short>(20));
    // 类型转换：运算时 int 会被转换为 long
    print_int(0 + 2L);
    // 函数重载时，一定要留意类型提升和类型转化
    // 函数调用时，如果没有精确匹配的类型，编译器会自动利用
    // 类型提升和转换来查找合适的函数

    // 浮点数
    print_real_info<float>();
    print_real(3.14);
    print_real(3.14e-10f);
    print_real(3.14L);


    // 浮点数的运算是精确的，但浮点数无法精确表示实数
    float a(0.03f);
    float b(10.0f);
    float c(0.3f);
    if (a*b == c) {
        std::cout << "Never happen!" << std::endl;
    }

    
    return 0;
}