#include "algorithms/Sorting.h"
#include <iostream>

using namespace std;

template<typename T>
void bubbleSort(vector<T> &v) {
    size_t sz = v.size();
    print(v, "Before sorting:");

    for (size_t i = 0; i < sz; i++)
    { 
        bool swapped = false;
        for (size_t j = 0; j < sz - i - 1; j++)
        {
            if(v[j] > v[j+1]) {
                swapped = true;
                swap(v[j], v[j+1]);
            }
        }

        if(swapped == false) break;
    }
    
    print(v, "After sorting:");
}

template<typename T>
void insertionSort(vector<T>& v) {
    size_t sz = v.size();
    print(v, "Before sorting:");

    for (size_t i = 1; i < sz; i++)
    {
        size_t j = i - 1;
        T key = v[i];

        while(j >= 0 && v[j] > key) {
            v[j+1] = v[j];
            j--;
        }

        v[j+1] = key;
    }

    print(v, "After sorting:");
}

template<typename T>
void print(const vector<T>& v, const string& str) {
    cout << str << endl;

    for (auto i : v)
        cout << i << " ";
}