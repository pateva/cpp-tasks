#include <iostream>
#include "../include/data_structures/basics/DoublyLinkedList.h"
#include "../include/data_structures/DoublyNode.h"

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), count(0) {}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {}

template <typename T>
void DoublyLinkedList<T>::addFirst(const T &value)
{
    DoublyNode<T> *newNode = new DoublyNode<T>(value, head, nullptr);
    head = newNode;

    if (tail == nullptr)
    {
        tail = newNode;
    }

    ++count;
}

template <typename T>
void DoublyLinkedList<T>::addLast(const T &value)
{
    DoublyNode<T> *newNode = new DoublyNode<T>(value, nullptr, tail);

    if (tail)
    {
        tail->next = newNode;
        tail = newNode;
    }
    else
    {
        head = tail = newNode;
    }

    ++count;
}

template <typename T>
void DoublyLinkedList<T>::popFront()
{
    if (head)
    {
        DoublyNode<T> *temp = head;
        head = head->next;
        delete temp;
        count--;

        if (head == nullptr)
        {
            tail = nullptr;
        }
    }
}

template <typename T>
void DoublyLinkedList<T>::popBack()
{
    if (!head)
    {
        return;
    }

    if (head == tail)
    {
        delete head;
        head = tail = nullptr;
        --count;

        return;
    }

    DoublyNode<T> *temp = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete temp;
    count--;
}

template <typename T>
bool DoublyLinkedList<T>::contains(const T &value) const
{
    DoublyNode<T> *iterator = head;

    while (iterator)
    {
        if (iterator->data == value)
        {
            return true;
        }

        iterator = iterator->next;
    }

    return false;
}

template <typename T>
bool DoublyLinkedList<T>::isEmpty() const
{
    return (head == nullptr);
}

template <typename T>
void DoublyLinkedList<T>::print() const
{
    DoublyNode<T> *iterator = head;

    while (iterator)
    {
        std::cout << iterator->data << std::endl;
        iterator = iterator->next;
    }
}

template <typename T>
size_t DoublyLinkedList<T>::size() const {
    return count;
}