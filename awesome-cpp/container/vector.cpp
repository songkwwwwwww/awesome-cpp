#include <functional>
#include <iostream>
#include <memory>
#include <vector>

#define FUNC_START std::cout << __FUNCTION__ << " start." << std::endl;
#define FUNC_END std::cout << __FUNCTION__ << " end." << std::endl;

void test_1() {
  FUNC_START

  // Create a vector containing integers
  std::vector<int> v = {7, 5, 16, 8};

  // Add two more integers to vector
  v.push_back(25);
  v.push_back(13);

  // Print out the vector
  std::cout << "v = { ";
  for (int n : v) {
    std::cout << n << ", ";
  }
  std::cout << "}; \n";

  FUNC_END
}

void test_make_move_iterator() {
  FUNC_START

  std::vector<std::unique_ptr<int>> v1;

  v1.push_back(std::make_unique<int>(1));
  v1.push_back(std::make_unique<int>(2));
  v1.push_back(std::make_unique<int>(3));

  std::vector<std::unique_ptr<int>> v2(std::make_move_iterator(v1.begin()),
                                       std::make_move_iterator(v1.end()));

  for (auto &i : v2) {
    std::cout << *i << std::endl;
  }

  FUNC_END
}

int main() {
  test_1();
  test_make_move_iterator();
}
