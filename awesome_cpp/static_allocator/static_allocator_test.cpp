/**
 * @file static_allocator_test.cpp
 * @author Kiwon Song (songkwwwwwww@naver.com)
 * @brief
 * @version 0.1
 * @date 2024-08-31
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "awesome_cpp/static_allocator/object_pool.hpp"
#include "awesome_cpp/static_allocator/static_allocator.hpp"

#include "gtest/gtest.h"

#include <iostream>
#include <vector>

namespace awesome_cpp {
namespace static_allocator {

class MyObject {
public:
  MyObject(int x) : x_(x) {
    std::cout << "MyObject created with value: " << x_ << std::endl;
  }

  ~MyObject() { std::cout << "MyObject destroyed." << std::endl; }

  void use() { std::cout << "Using MyObject with value: " << x_ << std::endl; }

private:
  int x_;
};

TEST(MyLibraryTest, TestFunction) {
  StaticAllocator<MyObject> allocator;

  constexpr int nObjects = 10;
  ObjectPool<MyObject, nObjects> pool(allocator);

  {
    std::vector<std::shared_ptr<MyObject>> ptrVec;
    for (int i = 0; i < nObjects; i++) {
      auto obj1 = pool.acquire(i);
      obj1->use();
    }
  }
}

TEST(MyLibraryTest, TestExceptionHandling) {
  StaticAllocator<MyObject> allocator;

  constexpr int nObjects = 10;
  ObjectPool<MyObject, nObjects> pool(allocator);

  try {
    std::vector<std::shared_ptr<MyObject>> ptrVec;
    for (int i = 0; i < nObjects + 1; i++) {
      auto obj1 = pool.acquire(i);
      obj1->use();
      ptrVec.push_back(obj1);
    }
    FAIL() << "Expected std::runtime_error";
  } catch (const std::bad_alloc &e) {
    EXPECT_STREQ("std::bad_alloc", e.what());
  } catch (...) {
    FAIL() << "Expected std::runtime_error, but caught a different type";
  }
}

TEST(MyLibraryTest, TestNoException) {
  StaticAllocator<MyObject> allocator;

  constexpr int nObjects = 10;
  ObjectPool<MyObject, nObjects> pool(allocator);

  try {
    std::vector<std::shared_ptr<MyObject>> ptrVec;
    for (int i = 0; i < nObjects; i++) {
      auto obj1 = pool.acquire(i);
      obj1->use();
      ptrVec.push_back(obj1);
    }
    ptrVec.pop_back();
    auto obj1 = pool.acquire(11);
    obj1->use();
  } catch (...) {
    FAIL() << "Expected std::runtime_error, but caught a different type";
  }
}

} // namespace static_allocator
} // namespace awesome_cpp
