#include <iostream>
#include <stdexcept>
#include "data_structures/basics/list/DynamicArray.h"

DynamicArray::DynamicArray(int initialCapacity)
{
    this->capacity = initialCapacity;
    this->size = 0;
    this->arr = new int[this->capacity];
}

DynamicArray::DynamicArray(const DynamicArray &other)
{
    this->capacity = other.capacity;
    this->size = other.size;
    this->arr = new int[this->size];
}

DynamicArray& DynamicArray::operator=(const DynamicArray &other)
{
    if (this == &other)
    {
        return *this;
    }

    if (arr != nullptr)
    {
        delete[] arr;
    }

    arr = new int[other.size];

    for (int i = 0; i < other.size; i++)
    {
        arr[i] = other.arr[i];
    }

    return *this;
}

DynamicArray::~DynamicArray()
{
    delete[] arr;
}

void DynamicArray::resize()
{
    int newCapacity = this->capacity * 2;
    int *newArr = new int[newCapacity];

    for (int i = 0; i < this->size; i++)
    {
        newArr[i] = this->arr[i];
    }

    delete[] arr;
    this->arr = newArr;
    this->capacity = newCapacity;
}

// insert element at the end
void DynamicArray::push_back(int value)
{
    if (this->size == this->capacity)
    {
        this->resize();
    }

    this->arr[size++] = value;
}

// remove the last element
void DynamicArray::pop_back()
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

// get element at a given index
int DynamicArray::get(int index) const
{
    if (index < 0 || index >= size)
    {
        throw std::out_of_range("Index out of bounds");
    }

    return this->arr[index];
}

// set element at a given index
void DynamicArray::set(int index, int value)
{
    if (index < 0 || index >= size)
    {
        throw std::out_of_range("Index out of bounds");
    }

    this->arr[index] = value;
}

int DynamicArray::getSize() const
{
    return this->size;
}

int DynamicArray::getCapacity() const
{
    return this->capacity;
}

// print all elements
void DynamicArray::print() const
{
    for (size_t i = 0; i < this->size; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}
