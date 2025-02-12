#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include <iostream>
#include "data_structures/basics/list/DynamicArray.h"

template <typename T>
class ArrayStack {
    private:
    int topIndex;
    DynamicArray<T>* arr;

    public:
    ArrayStack(int initialCapacity = 16);
    ArrayStack(const ArrayStack<T>& other);
    ~ArrayStack();

    ArrayStack& operator=(const ArrayStack<T>& other);
    void push(const T& value);
    void pop();
    T& top() const;
    bool isEmpty() const;
    int size() const;

};

#include "../src/data_structures/basics/stack/ArrayStack.tpp"

#endif