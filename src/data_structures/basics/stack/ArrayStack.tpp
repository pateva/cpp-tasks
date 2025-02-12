#include <iostream>
#include <stdexcept>
#include "data_structures/basics/stack/ArrayStack.h"
#include "data_structures/basics/list/DynamicArray.h"

template <typename T>
ArrayStack<T>::ArrayStack(int initialCapacity) {
    if(initialCapacity <= 0) {
        throw std::invalid_argument("Initial capacity must be greater than 0.");
    }

    this->arr = new DynamicArray<T>(initialCapacity);
    this->topIndex = -1;
}

template <typename T>
ArrayStack<T>::ArrayStack(const ArrayStack<T> &other) {
    this->arr = new DynamicArray(*other->arr);
    this->topIndex = arr.getSize()-1;
}

template <typename T>
ArrayStack<T>::~ArrayStack() {
    delete arr;
    arr = nullptr;
}

template <typename T>
ArrayStack<T>& ArrayStack<T>::operator= (const ArrayStack<T> &other) {
    if(this == &other) {
        return *this;
    }

    if(this->arr != nullptr) {
        delete arr;
    }

    this->arr = new DynamicArray<T>(*other->arr);
    this->topIndex = other->topIndex;

    return *this;
}

template <typename T>
void ArrayStack<T>::push(const T &value) {
    this->arr.push_back(value);
    this->topIndex++;
}

template <typename T>
void ArrayStack<T>::pop() {
    if(this->topIndex < 0) {
       throw std::invalid_argument("Stack is empty");
    }

    this->arr.pop_back();
    this->topIndex--;
}

template <typename T>
T& ArrayStack<T>::top() const {
    if(this->topIndex < 0) {
        throw std::invalid_argument("Array is empty");
    }

    return this->arr.get(this->topIndex);
}

template <typename T>
bool ArrayStack<T>::isEmpty() const {
    return this->topIndex < 0;
}

template <typename T>
int ArrayStack<T>::size() const {
    return this->topIndex + 1;
}