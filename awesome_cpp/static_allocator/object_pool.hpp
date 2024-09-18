/**
 * @file object_pool.hpp
 * @author Kiwon Song (songkwwwwwww@naver.com)
 * @brief
 * @version 0.1
 * @date 2024-08-31
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef AWESOME_CPP_STATIC_ALLOCATOR_OBJECT_POOL_HPP_
#define AWESOME_CPP_STATIC_ALLOCATOR_OBJECT_POOL_HPP_

#include "awesome_cpp/static_allocator/static_allocator.hpp"

#include <array>
#include <cassert>
#include <iostream>
#include <memory>
#include <vector>

namespace awesome_cpp {
namespace static_allocator {

template <typename T, size_t PoolSize = 10> class ObjectPool {
public:
  using ObjectPtr = std::shared_ptr<T>;

  ObjectPool(StaticAllocator<T, PoolSize> &allocator) : allocator(allocator) {}

  template <typename... Args> ObjectPtr acquire(Args &&...args) {
    if (!pool.empty()) {
      ObjectPtr obj = pool.back();
      pool.pop_back();
      return obj;
    } else {
      T *rawPtr = allocator.allocate(1);
      return ObjectPtr(new (rawPtr) T(std::forward<Args>(args)...),
                       [this](T *ptr) {
                         ptr->~T();
                         allocator.deallocate(ptr, 1);
                         pool.push_back(ObjectPtr(ptr, [](T *) {}));
                       });
    }
  }

private:
  StaticAllocator<T, PoolSize> &allocator;
  std::vector<ObjectPtr> pool;
};

} // namespace static_allocator
} // namespace awesome_cpp

#endif // AWESOME_CPP_STATIC_ALLOCATOR_OBJECT_POOL_HPP_