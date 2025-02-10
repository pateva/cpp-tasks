#include "data_structures/basics/list/CircularLinkedList.h"
#include "data_structures/Node.h"
#include <gtest/gtest.h>

class CircularLinkedListTest : public ::testing::Test {
protected:
    CircularLinkedList<int> list;
};

TEST_F(CircularLinkedListTest, IsEmptyInitially) {
    EXPECT_TRUE(list.isEmpty());
    EXPECT_EQ(list.size(), 0);
}

TEST_F(CircularLinkedListTest, AddFirstIncreasesSizeAndContainsElement) {
    list.addFirst(10);
    EXPECT_FALSE(list.isEmpty());
    EXPECT_EQ(list.size(), 1);
    EXPECT_TRUE(list.contains(10));

    list.addFirst(20);
    EXPECT_EQ(list.size(), 2);
    EXPECT_TRUE(list.contains(20));
    EXPECT_TRUE(list.contains(10));
}

TEST_F(CircularLinkedListTest, AddLastIncreasesSizeAndContainsElement) {
    list.addLast(30);
    EXPECT_FALSE(list.isEmpty());
    EXPECT_EQ(list.size(), 1);
    EXPECT_TRUE(list.contains(30));

    list.addLast(40);
    EXPECT_EQ(list.size(), 2);
    EXPECT_TRUE(list.contains(40));
    EXPECT_TRUE(list.contains(30));
}

TEST_F(CircularLinkedListTest, ContainsReturnsCorrectValue) {
    list.addFirst(100);
    list.addLast(200);
    EXPECT_TRUE(list.contains(100));
    EXPECT_TRUE(list.contains(200));
    EXPECT_FALSE(list.contains(300));
}

