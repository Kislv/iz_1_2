#include <gtest/gtest.h>
//#include "include/input_output.h"

extern "C" {
#include "include/input_output.h"
}

TEST(FIB_TEST, Assert_1) {
EXPECT_EQ(max_int(4,6), 6);
}
TEST(FIB_TEST, Assert_2) {
EXPECT_EQ(string_to_int("1235\n"), 1235);
}
TEST(FIB_TEST, Assert_3) {
EXPECT_EQ(string_is_int("1235\n"), true);
}
/*
TEST(FIB_OPT_TEST, Assert_1) {
EXPECT_EQ(fib_opt(1), 1);
}

TEST(FIB_TEST, Compare_20) {
EXPECT_EQ(fib(20), fib_opt(20));
}
*/
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}