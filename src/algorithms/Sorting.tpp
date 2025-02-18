#include "algorithms/Sorting.h"
#include <iostream>

using namespace std;

template<typename T>
void bubbleSort(std::vector<T> &v) {
    size_t sz = v.size();

    cout << "Before sorting:\n";
    for (auto i : v)
        cout << i << " ";

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
    
    cout << "After sorting:\n";
    for (auto i : v)
        cout << i << " ";

}