#include "data_structures/basics/stack/LinkedListStack.h"
#include <gtest/gtest.h>

class LinkedListStackTest : public ::testing::Test {
protected:
    LinkedListStack<int> stack;
};

TEST_F(LinkedListStackTest, Constructor)
{
    EXPECT_EQ(stack.size(), 0);
}

TEST_F(LinkedListStackTest, CopyConstructor) {
    LinkedListStack<int> original;
    EXPECT_TRUE(original.isEmpty());
    original.push(10);
    original.push(20);
    original.push(30);

    EXPECT_EQ(original.size(), 3);
    EXPECT_EQ(original.top(), 30);

    LinkedListStack<int> copy(original);

    EXPECT_EQ(copy.size(), original.size());
    EXPECT_EQ(copy.top(), original.top());
}

TEST_F(LinkedListStackTest, Operator) {
    LinkedListStack<int> original;
    EXPECT_TRUE(original.isEmpty());
    original.push(10);

    EXPECT_EQ(original.size(), 1);
    EXPECT_EQ(original.top(), 10);

    LinkedListStack<int> copy = original;

    EXPECT_EQ(copy.size(), original.size());
    EXPECT_EQ(copy.top(), original.top());
}

TEST_F(LinkedListStackTest, Push) {
    stack.push(10);
    EXPECT_EQ(stack.top(), 10);
    EXPECT_EQ(stack.size(), 1);
}

TEST_F(LinkedListStackTest, Top) {
    stack.push(10);
    stack.push(20);
    EXPECT_EQ(stack.top(), 20);
}
