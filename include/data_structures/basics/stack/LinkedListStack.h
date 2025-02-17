#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include <iostream>
#include "data_structures/basics/list/SinglyLinkedList.h"

template <typename T>
class LinkedListStack {
    private:
    int topIndex;
    SinglyLinkedList<T>* list;

    public:
    LinkedListStack();
    LinkedListStack(const LinkedListStack<T>& other);
    ~LinkedListStack();

    LinkedListStack& operator=(const LinkedListStack<T>& other);
    void push(const T& value);
    void pop();
    T& top() const;
    bool isEmpty() const;
    int size() const;

};

#include "../src/data_structures/basics/stack/LinkedListStack.tpp"

#endif