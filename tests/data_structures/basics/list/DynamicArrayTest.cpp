#include "data_structures/basics/list/DynamicArray.h"
#include <gtest/gtest.h>

class DynamicArrayTest : public ::testing::Test {
    protected:
    DynamicArray<int> arr;
};
// Test Constructor
TEST_F(DynamicArrayTest, Constructor) {
    EXPECT_EQ(arr.getSize(), 0);
    EXPECT_GE(arr.getCapacity(), 2); // Default capacity should be at least 2
}

TEST_F(DynamicArrayTest, PushBack) {
    arr.push_back(10);
    arr.push_back(20);
    EXPECT_EQ(arr.getSize(), 2);
    EXPECT_EQ(arr.get(0), 10);
    EXPECT_EQ(arr.get(1), 20);
}

TEST_F(DynamicArrayTest, PushBackResize) {
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    EXPECT_EQ(arr.getCapacity(), 4);
    EXPECT_EQ(arr.get(0), 10);
    EXPECT_EQ(arr.get(1), 20);
    EXPECT_EQ(arr.get(2), 30);
}

TEST_F(DynamicArrayTest, PopBack) {
    arr.push_back(10);
    arr.pop_back();
    EXPECT_EQ(arr.getSize(), 0);
}

TEST_F(DynamicArrayTest, PopBackExc) {
    EXPECT_THROW(arr.pop_back(), std::out_of_range);
}

