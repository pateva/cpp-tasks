#ifndef CIRCLULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

#include <iostream>
#include "../Node.h"

template <typename T>
class CircularLinkedList {
    Node<T>* head;
    Node<T>* tail;
    std::size_t count;

    public:
    CircularLinkedList();
    ~CircularLinkedList();

    void addFirst(const T& value);
    void addLast(const T& value);
    void popFront();
    void popBack();
    bool contains(const T& value) const;
    bool isEmpty() const;
    void print() const;
    size_t size() const;
};

#endif