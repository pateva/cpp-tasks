#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    Node* next;

    Node(const T& val): data(val), next(nullptr) {}
    Node(const T& val, Node<T>* next = nullptr): data(val), next(next) {}

};

#endif