#ifndef SORTING_H
#define SORTING_H

#include <vector>

template <typename T>
void bubbleSort(std::vector<T> &v);

template <typename T>
void insertionSort(std::vector<T> &v);

template <typename T>
void selectionSort(std::vector<T> &v);

template <typename T>
void mergeSort(std::vector<T> &v, size_t start, size_t end);

namespace detail
{
    template <typename T>
    void merge(std::vector<T> &v, size_t start, size_t mid, size_t end);

    template <typename T>
    void print(const std::vector<T> &v, const std::string &str);
}

#include "../src/algorithms/Sorting.tpp"

#endif
