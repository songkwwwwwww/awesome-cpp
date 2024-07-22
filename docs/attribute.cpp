/**
 * @file attribute.cpp
 * @author Kiwon Song (songkwwwwwww@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-11-13
 *
 * @copyright Copyright (c) 2022
 *
 * https://en.cppreference.com/w/cpp/language/attributes
 * https://learn.microsoft.com/ko-kr/cpp/cpp/attributes?view=msvc-170
 * https://jacking75.github.io/cpp_modern_cpp_attribute/
 * http://egloos.zum.com/sweeper/v/3201377
 */
#include <iostream>

[[noreturn]] void foo()
{
    std::cout << "foo" << std::endl;
    throw; // OK
}

[[nodiscard]] int foo(int i) { return i * i; }

int main()
{
    foo();
    foo();
}
