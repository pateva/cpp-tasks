#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include "data_structures/DoublyNode.h"

template <typename T>
class DoublyLinkedList {
    private:
    DoublyNode<T>* head;
    DoublyNode<T>* tail;
    std::size_t count;

    public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void addFirst(const T& value);
    void addLast(const T& value);
    void popFront();
    void popBack();
    bool contains(const T& value) const;
    bool isEmpty() const;
    void print() const;
    size_t size() const;
};

#include "../src/data_structures/basics/list/DoublyLinkedList.tpp"

#endif // DOUBLY_LINKED_LIST_H