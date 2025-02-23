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

TEST(SelectionSortTest, SortIntegers) {
    std::vector<int> input{5, 3, 1, 4, 2};
    std::vector<int> expected{1, 2, 3, 4, 5};

    selectionSort(input);
    EXPECT_EQ(input, expected);
}

TEST(SelectionSortTest, AlreadySorted) {
    std::vector<int> input{1, 2, 3, 4, 5};
    std::vector<int> expected{1, 2, 3, 4, 5};

    selectionSort(input);
    EXPECT_EQ(input, expected);
}

TEST(SelectionSortTest, SingleElement) {
    std::vector<int> input{42};
    std::vector<int> expected{42};

    selectionSort(input);
    EXPECT_EQ(input, expected);
}

TEST(SelectionSortTest, EmptyVector) {
    std::vector<int> input;
    selectionSort(input);
    EXPECT_TRUE(input.empty());
}

TEST(MergeSortTest, SortIntegers) {
    std::vector<int> input{5, 3, 1, 4, 2};
    std::vector<int> expected{1, 2, 3, 4, 5};

    mergeSort(input, 0, input.size()-1);
    EXPECT_EQ(input, expected);
}

TEST(MergeSortTest, AlreadySorted) {
    std::vector<int> input{1, 2, 3, 4, 5};
    std::vector<int> expected{1, 2, 3, 4, 5};

    mergeSort(input, 0, input.size()-1);
    EXPECT_EQ(input, expected);
}

TEST(MergeSortTest, SingleElement) {
    std::vector<int> input{42};
    std::vector<int> expected{42};

    mergeSort(input, 0, input.size()-1);
    EXPECT_EQ(input, expected);
}

TEST(MergeSortTest, EmptyVector) {
    std::vector<int> input;
    mergeSort(input, 0, input.size()-1);
    EXPECT_TRUE(input.empty());
}