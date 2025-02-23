#include "algorithms/Sorting.h"
#include <iostream>

using namespace std;

namespace helper
{
    template <typename T>
    void merge(vector<T> &v, size_t start, size_t mid, size_t end)
    {
        size_t n1 = mid - start + 1;
        size_t n2 = end - mid;
        vector<T> L(n1), R(n2);

        for (size_t i = 0; i < n1; i++)
        {
            L[i] = v[start + i];
        }

        for (size_t i = 0; i < n2; i++)
        {
            R[i] = v[mid + i + 1];
        }

        size_t i = 0, j = 0;
        size_t k = start;

        while (i < n1 && j < n2)
        {
            if (L[i] < R[j])
            {
                v[k++] = L[i++];
            }
            else
            {
                v[k++] = R[j++];
            }
        }

        while (i < n1)
        {
            v[k++] = L[i++];
        }

        while (j < n2)
        {
            v[k++] = R[j++];
        }
    }

    template <typename T>
    void print(const vector<T> &v, const string &str)
    {
        cout << str << endl;

        if (v.size() > 1)
        {
            for (auto i : v)
                cout << i << " ";
        }
    }
}

template <typename T>
void bubbleSort(vector<T> &v)
{
    size_t sz = v.size();
    helper::print(v, "Before sorting:");

    for (size_t i = 0; i < sz; i++)
    {
        bool swapped = false;
        for (size_t j = 0; j < sz - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                swapped = true;
                swap(v[j], v[j + 1]);
            }
        }

        if (swapped == false)
            break;
    }

    helper::print(v, "After sorting:");
}

template <typename T>
void insertionSort(vector<T> &v)
{
    size_t sz = v.size();
    helper::print(v, "Before sorting:");

    for (size_t i = 1; i < sz; i++)
    {
        size_t j = i - 1;
        T key = v[i];

        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = key;
    }

    helper::print(v, "After sorting:");
}

template <typename T>
void selectionSort(std::vector<T> &v)
{
    size_t sz = v.size();

    if (sz < 2)
    {
        return;
    }

    helper::print(v, "Before sorting:");

    for (size_t i = 0; i < sz - 1; i++)
    {
        size_t sm = i;

        for (size_t j = i + 1; j < sz; j++)
        {
            if (v.at(sm) > v.at(j))
            {
                sm = j;
            }
        }

        swap(v.at(i), v.at(sm));
    }

    helper::print(v, "Before sorting:");
}

template <typename T>
void mergeSort(vector<T> &v, size_t start, size_t end)
{
    if (v.empty() || start >= end) {
        return;
    }

    size_t mid = start + (end - start) / 2;
    mergeSort(v, start, mid);
    mergeSort(v, mid + 1, end);
    helper::merge(v, start, mid, end);
}
