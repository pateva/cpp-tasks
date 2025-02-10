#include "data_structures/basics/list/DoublyLinkedList.h"
#include "data_structures/DoublyNode.h"
#include <gtest/gtest.h>

class DoublyLinkedListTest : public ::testing::Test {
protected:
    DoublyLinkedList<int> list;
};

TEST_F(DoublyLinkedListTest, IsEmptyInitially) {
    EXPECT_TRUE(list.isEmpty());
    EXPECT_EQ(list.size(), 0);
}

TEST_F(DoublyLinkedListTest, AddFirst) {
    list.addFirst(10);
    EXPECT_FALSE(list.isEmpty());
    EXPECT_EQ(list.size(), 1);
    EXPECT_TRUE(list.contains(10));
}

TEST_F(DoublyLinkedListTest, AddLast) {
    list.addLast(20);
    EXPECT_FALSE(list.isEmpty());
    EXPECT_EQ(list.size(), 1);
    EXPECT_TRUE(list.contains(20));
}

TEST_F(DoublyLinkedListTest, MultipleInsertions) {
    list.addFirst(10);
    list.addLast(20);
    list.addFirst(5); 

    EXPECT_EQ(list.size(), 3);
    EXPECT_TRUE(list.contains(5));
    EXPECT_TRUE(list.contains(10));
    EXPECT_TRUE(list.contains(20));
    EXPECT_FALSE(list.contains(99));
}

TEST_F(DoublyLinkedListTest, PopFront) {
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

TEST_F(DoublyLinkedListTest, PopBack) {
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