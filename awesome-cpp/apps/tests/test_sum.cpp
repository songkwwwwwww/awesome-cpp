#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "sum.hpp"

TEST(SUM_TEST, SUM_TEST_1) { EXPECT_EQ(10, custom_sum(4, 6)); }