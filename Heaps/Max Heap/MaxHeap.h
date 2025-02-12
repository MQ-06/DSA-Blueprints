#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <iostream>
#include <stdexcept>
#include <queue>

template <typename T>
class MaxHeap
{
private:
    T *heap;
    int capacity;
    int size;
    void heapifyUp(int index);
    void heapifyDown(int index);
    void resize();

public:
    MaxHeap(int initialCapacity = 10);
    ~MaxHeap();

    MaxHeap(const MaxHeap<T> &other);

    void insert(T value);

    void deleteMax();

    void print_heap() const;

    T getMax() const;

    bool isEmpty() const;

    int getSize() const;
};

#endif