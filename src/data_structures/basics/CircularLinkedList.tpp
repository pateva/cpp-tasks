#include <iostream>
#include "../include/data_structures/basics/CircularLinkedList.h"
#include "../include/data_structures/Node.h"

template <typename T>
CircularLinkedList<T>::CircularLinkedList() : head(nullptr), tail(nullptr), count(0) {}

template <typename T>
CircularLinkedList<T>::~CircularLinkedList()
{
    Node<T> *current = head;

    while (current != nullptr)
    {
        Node<T> *temp = current;
        current = current->next;
        delete temp;
    }

    head = tail = nullptr;
}

template <typename T>
void CircularLinkedList<T>::addFirst(const T &value)
{
    Node<T> *newNode = new Node(value, head);
    head = newNode;

    if (tail == nullptr)
    {
        tail = newNode;
    }

    ++count;
}

template <typename T>
void CircularLinkedList<T>::addLast(const T &value)
{
    Node<T> *newNode = new Node(value, head);

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
void CircularLinkedList<T>::popFront()
{
    if (head)
    {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        count--;

        if (head == nullptr)
        {
            tail = nullptr;
        }
        else
        {
            tail->next = head;
        }
    }
}

template <typename T>
void CircularLinkedList<T>::popBack()
{
    if (!head)
    {
        return;
    }

    if (head == tail)
    {
        delete head;
        head = tail = nullptr;
        count--;

        return;
    }

    Node<T> *temp = tail;

    Node<T> *iterator = head;
    while (iterator->next == tail)
    {
        iterator = iterator->next;
    }

    tail = iterator;
    iterator->next = head;
    delete temp;
    count--;
}

template <typename T>
bool CircularLinkedList<T>::contains(const T &value) const
{
    Node<T> *iterator = head;

    while (iterator)
    {
        if (iterator->data == value)
            return true;

        iterator = iterator->next;
    }

    return false;
}

template <typename T>
bool CircularLinkedList<T>::isEmpty() const
{
    return head == nullptr;
}

template <typename T>
void CircularLinkedList<T>::print() const
{

    Node<T> *iterator = head;

    while (iterator)
    {
        std::cout << iterator->data << std::endl;
        iterator = iterator->next;
    }
}

template <typename T>
size_t CircularLinkedList<T>::size() const {
    return count;
}