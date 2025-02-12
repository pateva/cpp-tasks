#include "data_structures/basics/stack/ArrayStack.h"
#include <gtest/gtest.h>

class ArrayStackTest : public ::testing::Test {
protected:
    ArrayStack<int> stack;
};

TEST_F(ArrayStackTest, Constructor) {
    EXPECT_EQ(stack.size(), 0);
}

TEST_F(ArrayStackTest, CopyConstructor) {
    ArrayStack<int> original(16);
    EXPECT_TRUE(original.isEmpty());
    original.push(10);
    original.push(20);
    original.push(30);

    EXPECT_EQ(original.size(), 3);
    EXPECT_EQ(original.top(), 30);

    ArrayStack<int> copy(original);

    EXPECT_EQ(copy.size(), original.size());
    EXPECT_EQ(copy.top(), original.top());
}

TEST_F(ArrayStackTest, Operator) {
    ArrayStack<int> original(16);
    EXPECT_TRUE(original.isEmpty());
    original.push(10);

    EXPECT_EQ(original.size(), 1);
    EXPECT_EQ(original.top(), 10);

    ArrayStack<int> copy = original;

    EXPECT_EQ(copy.size(), original.size());
    EXPECT_EQ(copy.top(), original.top());
}

TEST_F(ArrayStackTest, Push) {
    stack.push(10);
    EXPECT_EQ(stack.top(), 10);
    EXPECT_EQ(stack.size(), 1);
}

TEST_F(ArrayStackTest, Top) {
    stack.push(10);
    stack.push(20);
    EXPECT_EQ(stack.top(), 20);
}
