#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <iostream>
#include <stdexcept>

template <typename T>
class DynamicArray {
private:
    T* arr;
    int size;
    int capacity;

    void resize(); 

public:
    explicit DynamicArray<T>(int initialCapacity = 2);
    ~DynamicArray();
    DynamicArray<T>(const DynamicArray<T>& other);
    DynamicArray<T>& operator=(const DynamicArray<T>& other);

    void push_back(const T& value);
    void pop_back();
    T& get(int index) const;
    void set(int index, const T& value);
    int getSize() const;
    int getCapacity() const;
    void print() const;
};

#include "../src/data_structures/basics/list/DynamicArray.tpp"

#endif // DYNAMIC_ARRAY_H
