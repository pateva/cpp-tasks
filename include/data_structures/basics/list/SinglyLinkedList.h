#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <iostream>
#include "data_structures/Node.h"

template <typename T>
class SinglyLinkedList {
    private:
    Node<T>* head;
    Node<T>* tail;
    std::size_t count;

    public:
    SinglyLinkedList();
    SinglyLinkedList(const SinglyLinkedList<T>& other);
    ~SinglyLinkedList();

    void addFirst(const T& value);
    void addLast(const T& value);
    void popFront();
    void popBack();
    bool contains(const T& value) const;
    bool isEmpty() const;
    void print() const;
    size_t size() const;
    T& getLast() const;
};

#include "../src/data_structures/basics/list/SinglyLinkedList.tpp"

#endif // SINGLY_LINKED_LIST_H