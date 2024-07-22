#include <array>
#include <iomanip>
#include <iostream>
#include <string>
#include <string_view>

int main()
{
    std::string cppstr = "Foo";
    std::string_view cppstr_v(cppstr);
    std::cout << "cppstr_v: " << quoted(cppstr_v) << '\n';

    char array[3] = {'B', 'a', 'r'};
    std::string_view array_v(array, std::size(array));
    std::cout << "array_v: " << quoted(array_v) << '\n';

    const char* one_0_two = "One\0Two";
    std::string_view one_v{one_0_two};
    std::cout << "one_v: " << quoted(one_v)
              << ", one_v.size(): " << one_v.size() << '\n';
}
