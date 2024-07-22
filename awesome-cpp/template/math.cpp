#include <cstdio>
#include <iostream>
#include <type_traits>

template <typename T>
void tell_type()
{
    if(std::is_void<T>::value)
    {
        std::cout << "T 는 void ! \n";
    }
    else
    {
        std::cout << "T 는 void 가 아니다. \n";
    }
}

template <typename T,
          typename = typename std::enable_if<std::is_integral<T>::value>::type>
T my_sum(T a)
{
    return a;
    // return a + b;
}

// template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
// template <typename T,
//           typename = typename
//           std::enable_if<std::is_integral<T>::value>::type>
template <typename T, typename... Types,
          typename = typename std::enable_if<std::is_integral<T>::value>::type>
T my_sum(T a, Types... args)
{
    return a + my_sum(args...);
    // return a + b;
}

// 정수 타입만 받는 함수
template <typename T>
void only_integer(const T& t)
{
    static_assert(std::is_integral<T>::value);
    std::cout << "T is an integer \n";
}

class custom_class
{
};

int main()
{
    std::cout << my_sum<int>(5, 10) << std::endl;
    // std::cout << my_sum<double>(static_cast<double>(-5.5),
    //                             static_cast<double>(-10))
    //           << std::endl;
    tell_type<int>();
    tell_type<void>();
    only_integer(1);
    // only_integer(custom_class()); // error
}