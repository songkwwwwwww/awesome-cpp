#include <cassert>
#include <iostream>
#include <string>
#include <type_traits>

template <typename T>
void process(const T& t)
{
    if constexpr(std::is_integral_v<T>)
    {
        std::cout << t << "is a integral type." << std::endl;
    }
    else
    {
        std::cout << t << "is a non-integral type." << std::endl;
    }
}

class IsDoable
{
public:
    void doit() const { std::cout << "IsDoable::doit()" << std::endl; }
};

class Derived : public IsDoable
{
};

template <typename T>
void call_doit([[maybe_unused]] const T& t)
{
    if constexpr(std::is_base_of_v<IsDoable, T>)
    {
        t.doit();
    }
    else
    {
        std::cout << "Cannot call doit()!" << std::endl;
    }
}

int main()
{
    // #1. 타입 범주에 속한 타입 트레이트

    // if(std::is_integral<int>::value)
    if(std::is_integral_v<int>)
    {
        std::cout << "int is integral" << std::endl;
    }
    // if(std::is_class<std::string>::value)
    if(std::is_class_v<std::string>)
    {
        std::cout << "string is class" << std::endl;
    }
    process(123);
    process(2.2);
    process("Test");

    // #2. 타입 관계 활용 방법
    // is_same, is_base_of, is_convertible

    // #4. constexpr if로 enable_if 간결하게 표현하기.
    Derived d;
    call_doit(d);
    call_doit(123);

    // #5. 논리 연산자 트레이트
    // conjunction, disjunction, negation
    std::cout << std::conjunction_v<std::is_integral<int>,
                                    std::is_integral<short>> << " ";
    std::cout << std::conjunction_v<std::is_integral<int>,
                                    std::is_integral<double>> << " ";
    std::cout
        << std::disjunction_v<std::is_integral<int>, std::is_integral<short>,
                              std::is_integral<double>> << " ";
    std::cout << std::negation_v<std::is_integral<int>> << std::endl;
}