/**
 * @file execution_time.cpp
 * @author Kiwon Song (songkwwwwwww@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-07-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <chrono>
#include <cstdio>

/**
 * https://www.geeksforgeeks.org/measure-execution-time-with-high-precision-in-c-c/
 */

int main() {
  long long int sum = 0;

  auto begin = std::chrono::high_resolution_clock::now();

  int iterations = 1000 * 1000;
  for (int i = 0; i < iterations; i++) {
    sum += 1;
  }

  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed =
      std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

  printf("Result: %.20lld\n", sum);
  printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);

  return 0;
}
