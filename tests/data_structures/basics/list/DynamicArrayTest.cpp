#include "data_structures/basics/list/DynamicArray.h"
#include <gtest/gtest.h>

// Test Constructor
TEST(DynamicArrayTest, Constructor) {
    DynamicArray arr;
    EXPECT_EQ(arr.getSize(), 0);
    EXPECT_GE(arr.getCapacity(), 2); // Default capacity should be at least 2
}

TEST(DynamicArrayTest, PushBack) {
    DynamicArray arr;
    arr.push_back(10);
    arr.push_back(20);
    EXPECT_EQ(arr.getSize(), 2);
    EXPECT_EQ(arr.get(0), 10);
    EXPECT_EQ(arr.get(1), 20);
}

TEST(DynamicArrayTest, PushBackResize) {
    DynamicArray arr;
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    EXPECT_EQ(arr.getCapacity(), 4);
    EXPECT_EQ(arr.get(0), 10);
    EXPECT_EQ(arr.get(1), 20);
    EXPECT_EQ(arr.get(2), 30);
}

TEST(DynamicArrayTest, PopBack) {
    DynamicArray arr;
    arr.push_back(10);
    arr.pop_back();
    EXPECT_EQ(arr.getSize(), 0);
}

TEST(DynamicArrayTest, PopBackExc) {
    DynamicArray arr;
    EXPECT_THROW(arr.pop_back(), std::out_of_range);
}
