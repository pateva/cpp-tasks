#ifndef DOUBLY_NODE_H
#define DOUBLY_NODE_H

template <typename T>
struct DoublyNode {
    T data;
    DoublyNode* next;
    DoublyNode* prev;

    DoublyNode(const T& val): data(val), next(nullptr), prev(nullptr) {}
    DoublyNode(const T& val, DoublyNode<T>* next = nullptr, DoublyNode<T>* prev = nullptr): data(val), next(next), prev(prev) {}

};

#endif