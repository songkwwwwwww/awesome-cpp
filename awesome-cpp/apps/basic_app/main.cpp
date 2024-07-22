#include <iostream>

#include "sum.hpp"

int main(int argc, char** argv)
{
    std::cout << "Hello World!" << std::endl;
    std::cout << "4 + 6 = " << custom_sum(4, 6) << std::endl;
    std::cout << "argc: " << argc << std::endl;
    for(int i = 0; i < argc; i++)
    {
        std::cout << argv[i] << std::endl;
    }

    return 0;
}
