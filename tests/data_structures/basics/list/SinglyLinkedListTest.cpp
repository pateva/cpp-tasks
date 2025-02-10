#include "data_structures/basics/list/SinglyLinkedList.h"
#include "data_structures/Node.h"
#include <gtest/gtest.h>

class SinglyLinkedListTest : public ::testing::Test {
protected:
    SinglyLinkedList<int> list;
};

TEST_F(SinglyLinkedListTest, IsEmptyInitially) {
    EXPECT_TRUE(list.isEmpty());
    EXPECT_EQ(list.size(), 0);
}

TEST_F(SinglyLinkedListTest, AddFirst) {
    list.addFirst(10);
    EXPECT_FALSE(list.isEmpty());
    EXPECT_EQ(list.size(), 1);
    EXPECT_TRUE(list.contains(10));
}

TEST_F(SinglyLinkedListTest, AddLast) {
    list.addLast(20);
    EXPECT_FALSE(list.isEmpty());
    EXPECT_EQ(list.size(), 1);
    EXPECT_TRUE(list.contains(20));
}

TEST_F(SinglyLinkedListTest, MultipleInsertions) {
    list.addFirst(10);
    list.addLast(20);
    list.addFirst(5);  

    EXPECT_EQ(list.size(), 3);
    EXPECT_TRUE(list.contains(5));
    EXPECT_TRUE(list.contains(10));
    EXPECT_TRUE(list.contains(20));
    EXPECT_FALSE(list.contains(99));
}

TEST_F(SinglyLinkedListTest, PopFront) {
    list.addLast(10);
    list.addLast(20);
    list.addLast(30);

    list.popFront();
    EXPECT_EQ(list.size(), 2);
    EXPECT_FALSE(list.contains(10));
    EXPECT_TRUE(list.contains(20));
    EXPECT_TRUE(list.contains(30));

    list.popFront();
    list.popFront();
    EXPECT_TRUE(list.isEmpty());
}

TEST_F(SinglyLinkedListTest, PopBack) {
    list.addLast(10);
    list.addLast(20);
    list.addLast(30);

    list.popBack();
    EXPECT_EQ(list.size(), 2);
    EXPECT_TRUE(list.contains(10));
    EXPECT_TRUE(list.contains(20));
    EXPECT_FALSE(list.contains(30));

    list.popBack();
    EXPECT_EQ(list.size(), 1);
    EXPECT_TRUE(list.contains(10));
    EXPECT_FALSE(list.contains(20));

    list.popBack();
    EXPECT_TRUE(list.isEmpty());
}