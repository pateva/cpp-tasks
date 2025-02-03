#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include "../Node.h"

template <typename T>
class SinglyLinkedList {
    private:
    Node<T>* head;
    Node<T>* tail;
    std::size_t count;

    public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    void addFirst(const T& value);
    void addLast(const T& value);
    void popFront();
    void popBack();
    bool contains(const T& value) const;
    bool isEmpty() const;
    void print() const;
    size_t size() const;
};

#include "../src/data_structures/basics/SinglyLinkedList.tpp"

#endif // DOUBLY_LINKED_LIST_H