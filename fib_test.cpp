#include <gtest/gtest.h>
#include "fib.h"


TEST(FIB_TEST, Assert_1) {
  EXPECT_EQ(fib(1), 1);
}

TEST(FIB_OPT_TEST, Assert_1) {
  EXPECT_EQ(fib_opt(1), 1);
}

TEST(FIB_TEST, Compare_20) {
  EXPECT_EQ(fib(20), fib_opt(20));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}