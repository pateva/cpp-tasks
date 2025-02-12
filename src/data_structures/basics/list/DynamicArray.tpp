#include <iostream>
#include <stdexcept>
#include "data_structures/basics/list/DynamicArray.h"

template <typename T>
DynamicArray<T>::DynamicArray(int initialCapacity)
{
    if (this->initialCapacity <= 0) {
        throw std::invalid_argument("Initial capacity must be greater than 0.");
    }

    this->capacity = initialCapacity;
    this->size = 0;
    this->arr = new T[this->capacity];
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray &other)
{
    this->capacity = other.capacity;
    this->size = other.size;
    this->arr = new T[this->size];

    for (int i = 0; i < this->size; i++) {
        this->arr[i] = other.arr[i];
    }
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray &other)
{
    if (this == &other)
    {
        return *this;
    }

    if (arr != nullptr)
    {
        delete[] arr;
    }

    arr = new T[other.size];

    for (int i = 0; i < other.size; i++)
    {
        arr[i] = other.arr[i];
    }

    return *this;
}

template <typename T>
DynamicArray<T>::~DynamicArray()
{
    delete[] arr;
}

template <typename T>
void DynamicArray<T>::resize()
{
    int newCapacity = this->capacity * 2;
    int *newArr = new T[newCapacity];

    for (int i = 0; i < this->size; i++)
    {
        newArr[i] = this->arr[i];
    }

    delete[] arr;
    this->arr = newArr;
    this->capacity = newCapacity;
}

template <typename T>
void DynamicArray<T>::push_back(const T& value)
{
    if (this->size == this->capacity)
    {
        this->resize();
    }

    this->arr[this->size++] = value;
}

template <typename T>
void DynamicArray<T>::pop_back()
{
    if (size > 0)
    {
        size--;
    }
    else
    {
        throw std::out_of_range("Array is empty");
    }
}

template <typename T>
T& DynamicArray<T>::get(int index) const
{
    if (index < 0 || index >= size)
    {
        throw std::out_of_range("Index out of bounds");
    }

    return this->arr[index];
}

template <typename T>
void DynamicArray<T>::set(int index, const T& value)
{
    if (index < 0 || index >= size)
    {
        throw std::out_of_range("Index out of bounds");
    }

    this->arr[index] = value;
}

template <typename T>
int DynamicArray<T>::getSize() const
{
    return this->size;
}

template <typename T>
int DynamicArray<T>::getCapacity() const
{
    return this->capacity;
}

template <typename T>
void DynamicArray<T>::print() const
{
    for (size_t i = 0; i < this->size; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}
