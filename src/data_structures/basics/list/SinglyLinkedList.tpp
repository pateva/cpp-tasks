#include <iostream>
#include "data_structures/basics/list/SinglyLinkedList.h"
#include "data_structures/Node.h"


template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() : head(nullptr), tail(nullptr), count(0) {}

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList<T>& other) {
    if(other.head == nullptr) {
        this->head = this->tail = nullptr;
        count = 0;
        return;
    }

    this->head = new Node<T>(other.head->data, nullptr);
    count = 1;

    Node<T>* currentOther = other.head->next;
    Node<T>* current = head;

    while(currentOther != nullptr) {
        Node<T>* newNode = new Node<T>(currentOther->data);
        current->next = newNode;
        count++;
        currentOther = currentOther->next;
    }

    this->tail = current;
}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
    while(head!= nullptr) {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
    }

    tail = nullptr;
    count = 0;
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

template <typename T>
T& SinglyLinkedList<T>::getLast() const {
    return head->data;
}