// tupleTie.cpp
#include <iostream>
#include <tuple>
using namespace std;

int main() {
  int first = 1;
  int second = 2;
  int third = 3;
  int fourth = 4;

  cout << first << " " << second << " " << third << " " << fourth
       << endl; // 1 2 3 4

  auto tup = tie(first, second, third, fourth); // bind the tuple
  //      = std::make_tuple(101, 102, 103, 104);   // create the tuple
  // and assign it
  cout << "Hello, " << get<0>(tup) << " " << get<1>(tup) << " " << get<2>(tup)
       << " " << get<3>(tup) << endl; // 101 102 103 104

  cout << first << " " << second << " " << third << " " << fourth
       << endl;                                    // 101 102 103 104
                                                   //
  auto tup2 = std::make_tuple(101, 102, 103, 104); // create the tuple
  cout << "Hello, " << get<0>(tup2) << " " << get<1>(tup2) << " "
       << get<2>(tup2) << " " << get<3>(tup2) << endl; // 101 102 103 104

  std::tie(first, second, third, fourth) = tup2;
  cout << "World, " << first << " " << second << " " << third << " " << fourth
       << endl; // 101 102 103 104

  first = 201;
  get<1>(tup) = 202;

  cout << get<0>(tup) << " " << get<1>(tup) << " " << get<2>(tup) << " "
       << get<3>(tup) << endl; // 201 202 103 104

  cout << first << " " << second << " " << third << " " << fourth
       << endl; // 201 202 103 104

  int a, b;
  tie(std::ignore, a, std::ignore, b) = tup;
  cout << a << " " << b << endl; // 202 104
                                 //
  int c, d;
  // auto [std::ignore, c, std::ignore, d] = tup;
  auto [e, f, g, h] = tup;
  // auto [std::ignore, f, g, h] = tup;

  return 0;
}
