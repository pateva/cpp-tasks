#include <iostream>
#include "data_structures/basics/list/CircularLinkedList.h"
#include "data_structures/Node.h"

template <typename T>
CircularLinkedList<T>::CircularLinkedList() : head(nullptr), tail(nullptr), count(0) {}

template <typename T>
CircularLinkedList<T>::~CircularLinkedList()
{
    if(head != nullptr) {
        tail->next = nullptr;

        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* temp = current;
            current = current->next;
            delete temp;
        }
    }

        head = tail = nullptr;
}

template <typename T>
void CircularLinkedList<T>::addFirst(const T &value)
{
    Node<T> *newNode = new Node<T>(value, head);

    if(!head) {
        head = tail = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }

    ++count;
}

template <typename T>
void CircularLinkedList<T>::addLast(const T &value)
{
    Node<T> *newNode = new Node<T>(value, head);

    if (tail)
    {
        tail->next = newNode;
        tail = newNode;
    }
    else
    {
        head = tail = newNode;
        tail->next = newNode;
    }

    ++count;
}

template <typename T>
void CircularLinkedList<T>::popFront()
{
    if (head)
    {
        Node<T> *temp = head;

        if (head == nullptr)
        {
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
            tail->next = head;
        }

        delete temp;
        count--;
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

    Node<T> *iterator = head;
    while (iterator->next != tail)
    {
        iterator = iterator->next;
    }

    Node<T> *temp = tail;
    tail = iterator;
    iterator->next = head;
    delete temp;
    count--;
}

template <typename T>
bool CircularLinkedList<T>::contains(const T &value) const
{
    Node<T> *iterator = head;

    do {
        if (iterator->data == value)
            return true;
        iterator = iterator->next;
    } while (iterator != head);

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

   Node<T>* iterator = head;
    do {
        std::cout << iterator->data << std::endl;
        iterator = iterator->next;
    } while (iterator != head);
}

template <typename T>
size_t CircularLinkedList<T>::size() const {
    return count;
}