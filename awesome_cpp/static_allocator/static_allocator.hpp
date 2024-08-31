/**
 * @file static_allocator.hpp
 * @author Kiwon Song (songkwwwwwww@naver.com)
 * @brief
 * @version 0.1
 * @date 2024-08-31
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef AWESOME_CPP_STATIC_ALLOCATOR_STATIC_ALLOCATOR_HPP_
#define AWESOME_CPP_STATIC_ALLOCATOR_STATIC_ALLOCATOR_HPP_

#include <array>
#include <cassert>
#include <iostream>
#include <memory>
#include <vector>

namespace awesome_cpp {
namespace static_allocator {

constexpr uint64_t ALIGNAS_OFFSET = 64;

template <typename T, size_t PoolSize = 10> class StaticAllocator {
public:
  using value_type = T;

  StaticAllocator() {
    for (size_t i = 0; i < PoolSize; ++i) {
      free_list[i] = &data[i];
    }
    free_count = PoolSize;
  }

  T *allocate(std::size_t n) {
    assert(n == 1);
    if (free_count == 0) {
      throw std::bad_alloc();
    }

    T *ptr = reinterpret_cast<T *>(free_list[--free_count]);
    return ptr;
  }

  void deallocate(T *p, std::size_t n) {
    assert(n == 1);
    assert(free_count < PoolSize);

    free_list[free_count++] = p;
  }

private:
  alignas(ALIGNAS_OFFSET)
      std::array<std::aligned_storage_t<sizeof(T), alignof(T)>, PoolSize> data;
  std::array<void *, PoolSize> free_list;
  size_t free_count;
};

} // namespace static_allocator
} // namespace awesome_cpp

#endif // AWESOME_CPP_STATIC_ALLOCATOR_STATIC_ALLOCATOR_HPP_
