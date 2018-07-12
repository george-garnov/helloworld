#include <gtest/gtest.h>

TEST(myTest1, Test1) { 
    ASSERT_EQ(100, 6*6+8*8) << "test_1";
}

TEST(myTest2, Test2) {
    ASSERT_FALSE(true==false) << "test_2";
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
