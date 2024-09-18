/**
 * @file static_allocator_benchmark.cpp
 * @author Kiwon Song (songkwwwwwww@naver.com)
 * @brief
 * @version 0.1
 * @date 2024-09-18
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <benchmark/benchmark.h>

#include <memory>

#include "awesome_cpp/static_allocator/object_pool.hpp"
#include "awesome_cpp/static_allocator/static_allocator.hpp"

namespace awesome_cpp {
namespace static_allocator {

class MyObject {
public:
  MyObject() { data_.reserve(1000); }

  ~MyObject() = default;

private:
  std::vector<uint8_t> data_;
};

static int ITERATION = 10000;

static void BM_StaticAllocator(benchmark::State &state) {
  constexpr int NUM_OBJECTS = 10;
  StaticAllocator<MyObject, NUM_OBJECTS> allocator;
  ObjectPool<MyObject, NUM_OBJECTS> pool(allocator);

  for (auto _ : state) {
    for (int i = 0; i < ITERATION; i++) {
      auto ptr = pool.acquire();
      benchmark::DoNotOptimize(ptr);
      benchmark::ClobberMemory();
    }
  }
}

BENCHMARK(BM_StaticAllocator);

static void BM_NativeDynamicAllocator(benchmark::State &state) {
  for (auto _ : state) {
    for (int i = 0; i < ITERATION; i++) {
      auto ptr = std::make_shared<MyObject>();
      benchmark::DoNotOptimize(ptr);
      benchmark::ClobberMemory();
    }
  }
}
BENCHMARK(BM_NativeDynamicAllocator);

} // namespace static_allocator
} // namespace awesome_cpp

BENCHMARK_MAIN();