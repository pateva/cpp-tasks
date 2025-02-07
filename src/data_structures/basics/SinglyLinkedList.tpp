#include <iostream>
#include "../include/data_structures/basics/SinglyLinkedList.h"
#include "../include/data_structures/Node.h"


template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() : head(nullptr), tail(nullptr), count(0) {}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
    // TODO implement
}

template <typename T>
void SinglyLinkedList<T>::addFirst(const T &value)
{
    Node<T> *newNode = new Node<T>(value, head);
    head = newNode;

    if (tail == nullptr)
    {
        tail = newNode;
    }

    ++count;
}

template <typename T>
void SinglyLinkedList<T>::addLast(const T &value)
{
    Node<T> *newNode = new Node<T>(value, nullptr);

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
void SinglyLinkedList<T>::popFront()
{
    if (head)
    {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        --count;

        // if the list becomes empty
        if (head == nullptr)
        {
            tail = nullptr;
        }
    }
}

template <typename T>
void SinglyLinkedList<T>::popBack()
{
    if (!head)
        return;

    if (head == tail)
    {
        delete head;
        head = tail = nullptr;
        --count;

        return;
    }

    Node<T> *iterator = head;

    while (iterator->next != tail)
    {
        iterator = iterator->next;
    }

    delete tail;
    tail = iterator;
    tail->next = nullptr;
    --count;
}

template <typename T>
bool SinglyLinkedList<T>::contains(const T& value) const {
    Node<T>* iterator = head;

    while(iterator != nullptr) {
        if(iterator->data == value) {
            return true;
        }

        iterator = iterator->next;
    }

    return false;
}

template <typename T>
bool SinglyLinkedList<T>::isEmpty() const {
    return head == nullptr;
}

template <typename T>
void SinglyLinkedList<T>::print() const {
    Node<T>* iterator = head;

    while(iterator != nullptr) {
        std::cout << iterator->data << std::endl;
        iterator = iterator->next;
    }
}

template <typename T>
size_t SinglyLinkedList<T>::size() const {
   return count;
}