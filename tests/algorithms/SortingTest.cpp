#include <gtest/gtest.h>
#include <vector>
#include "algorithms/Sorting.h"

TEST(BubbleSortTest, SortIntegers) {
    std::vector<int> input{5, 3, 1, 4, 2};
    std::vector<int> expected{1, 2, 3, 4, 5};

    bubbleSort(input);
    EXPECT_EQ(input, expected);
}

TEST(BubbleSortTest, AlreadySorted) {
    std::vector<int> input{1, 2, 3, 4, 5};
    std::vector<int> expected{1, 2, 3, 4, 5};

    bubbleSort(input);
    EXPECT_EQ(input, expected);
}

TEST(BubbleSortTest, SingleElement) {
    std::vector<int> input{42};
    std::vector<int> expected{42};

    bubbleSort(input);
    EXPECT_EQ(input, expected);
}

TEST(BubbleSortTest, EmptyVector) {
    std::vector<int> input;
    insertionSort(input);
    EXPECT_TRUE(input.empty());
}

TEST(InsertionSortTest, SortIntegers) {
    std::vector<int> input{5, 3, 1, 4, 2};
    std::vector<int> expected{1, 2, 3, 4, 5};

    insertionSort(input);
    EXPECT_EQ(input, expected);
}

TEST(InsertionSortTest, AlreadySorted) {
    std::vector<int> input{1, 2, 3, 4, 5};
    std::vector<int> expected{1, 2, 3, 4, 5};

    insertionSort(input);
    EXPECT_EQ(input, expected);
}

TEST(InsertionSortTest, SingleElement) {
    std::vector<int> input{42};
    std::vector<int> expected{42};

    insertionSort(input);
    EXPECT_EQ(input, expected);
}

TEST(InsertionSortTest, EmptyVector) {
    std::vector<int> input;
    insertionSort(input);
    EXPECT_TRUE(input.empty());
}