#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void testString()
{
    std::string s = "aba";
    std::sort(s.begin(), s.end());
    do
    {
        std::cout << s << '\n';
    } while(std::next_permutation(s.begin(), s.end()));
}

void testVector()
{
    std::vector v = {0, 1, 2, 3};
    do
    {
        for(auto n : v)
        {
            std::cout << n << ' ';
        }
        std::cout << '\n';
    } while(std::next_permutation(begin(v), end(v)));
}

int main()
{
    testString();
    testVector();
}
