#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>
#include <stdexcept>
#include <queue>

template <typename T>
class MinHeap
{
private:
    T *heap;
    int capacity;
    int size;
    void heapifyUp(int index);
    void heapifyDown(int index);
    void resize();

public:
    MinHeap(int initialCapacity = 10);
    ~MinHeap();

    MinHeap(const MinHeap<T> &other);

    void insert(T value);

    void deleteMin();

    void print_heap() const;

    T getMin() const;

    bool isEmpty() const;

    int getSize() const;
};

#endif
