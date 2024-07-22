/**
 * @file type_alias.cpp
 * @author Kiwon Song (songkwwwwwww@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-11-13
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <memory>
#include <string>
#include <vector>

int add(int x, int y) { return x + y; }

/**
 * 1. type alias (C++11)
 *
 * using IntPtr = int*;
 * using FunctionType = int (*)(char, double);
 */
void test1() {
  std::cout << "test1 " << std::endl;
  using IntPtr = int *;
  int *p1 = new int(5);
  IntPtr p2 = nullptr;

  p2 = p1;
  p1 = p2;

  std::cout << *p1 << std::endl;

  using StringVector = std::vector<std::string>;

  StringVector stringVector;
  stringVector.push_back("abc");
  stringVector.push_back("def");

  for (auto &str : stringVector) {
    std::cout << str << std::endl;
  }

  using FunctionType = int (*)(int, int);
  FunctionType func = add;
  std::cout << func(10, 20) << std::endl;
}
/**
 * 2. typedef
 *
 * typedef int* IntPtr;
 * typedef int (*FunctionType)(char, double);
 */
void test2() {
  std::cout << "test2" << std::endl;
  typedef int (*FunctionType)(int, int);
  FunctionType func = add;
  std::cout << func(10, 20) << std::endl;
}

int main() {
  test1();
  test2();
}