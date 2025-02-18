#include <iostream>
#include "data_structures/basics/stack/LinkedListStack.h"
#include "data_structures/basics/list/SinglyLinkedList.h"

template <typename T>
LinkedListStack<T>::LinkedListStack()
{
    this->list = new SinglyLinkedList<T>();
    this->topIndex = -1;
}

template <typename T>
LinkedListStack<T>::LinkedListStack(const LinkedListStack<T> &other)
{

    this->list = new SinglyLinkedList<T>(*other.list);
    this->topIndex = other.topIndex;
}

template <typename T>
LinkedListStack<T>::~LinkedListStack()
{
    delete list;
    list = nullptr;
    topIndex = -1;
}

template <typename T>
LinkedListStack<T> &LinkedListStack<T>::operator=(const LinkedListStack<T> &other)
{
    if (this == &other)
    {
        return *this;
    }

    delete this->list;

    if(other.list != nullptr) {
    this->list = new SinglyLinkedList<T>(*other.list);
    } else {
        this->list = nullptr;
    }

    this->topIndex = other.topIndex;

    return *this;
}

template <typename T>
void LinkedListStack<T>::push(const T &value)
{
    this->list->addLast(value);
    this->topIndex++;
}

template <typename T>
void LinkedListStack<T>::pop()
{
    this->list->popBack();
    this->topIndex--;
}

template <typename T>
T& LinkedListStack<T>::top() const
{
    if(this->topIndex < 0) {
        throw std::invalid_argument("Stack is empty");
    }

    return this->list->getLast();
}

template <typename T>
bool LinkedListStack<T>::isEmpty() const
{
    return this->topIndex < 0;
}

template <typename T>
int LinkedListStack<T>::size() const
{
    return this->topIndex + 1;
}