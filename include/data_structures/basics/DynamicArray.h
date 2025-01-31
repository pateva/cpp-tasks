#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <iostream>
#include <stdexcept>

class DynamicArray {
private:
    int* arr;
    int size;
    int capacity;

    void resize(); 

public:
    DynamicArray(int initialCapacity = 2);
    ~DynamicArray();
    DynamicArray(const DynamicArray& other);
    DynamicArray& operator=(const DynamicArray& other);

    void push_back(int value);
    void pop_back();
    int get(int index) const;
    void set(int index, int value);
    int getSize() const;
    int getCapacity() const;
    void print() const;
};

#endif // DYNAMIC_ARRAY_H
