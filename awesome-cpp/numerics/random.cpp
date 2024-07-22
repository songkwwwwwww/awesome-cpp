#include <iostream>
#include <cassert>
#include <random>
#include <string>
#include <map>

int main()
{
    std::mt19937 gen32;
    std::mt19937_64 gen64;

    for (auto n{1}; n < 10'000; gen32(), gen64(), ++n)
	;

    assert(gen32() == 4'123'659'995 and
	    gen64() == 9'981'545'732'273'789'042ULL);

    std::random_device rd;
    std::mt19937 mersenne_engine{ rd() };
    std::map<int, int> hist;
    std::uniform_int_distribution<int> dist(0, 9);
    for (int n = 0; n < 10000; ++n) {
        ++hist[dist(rd)]; // note: demo only: the performance of many
                          // implementations of random_device degrades sharply
                          // once the entropy pool is exhausted. For practical use
                          // random_device is generally only used to seed
                          // a PRNG such as mt19937
    }
    for (auto p : hist) {
        std::cout << p.first << " : " << std::string(p.second/100, '*') << '\n';
    }
}
