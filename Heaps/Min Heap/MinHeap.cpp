#include "MinHeap.h"
#include <iostream>
using namespace std;

// Constructor
template <typename T>
MinHeap<T>::MinHeap(int initialCapacity)
{
    capacity = initialCapacity;
    size = 0;
    heap = new T[capacity];
}

// Destructor
template <typename T>
MinHeap<T>::~MinHeap()
{
    delete[] heap;
}

// Copy Constructor
template <typename T>
MinHeap<T>::MinHeap(const MinHeap<T> &other)
{
    capacity = other.capacity;
    size = other.size;
    heap = new T[capacity];
    for (int i = 0; i < size; i++)
    {
        heap[i] = other.heap[i];
    }
}

// Helper function
template <typename T>
void MinHeap<T>::heapifyUp(int index)
{
    while (index > 0 && heap[index] < heap[(index - 1) / 2])
    {
        swap(heap[index], heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

// Helper function
template <typename T>
void MinHeap<T>::heapifyDown(int index)
{
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int smallest = index;
 
    if (leftChild < size && heap[leftChild] < heap[smallest])
    {
        smallest = leftChild;
    }

    if (rightChild < size && heap[rightChild] < heap[smallest])
    {
        smallest = rightChild;
    }

    if (smallest != index)
    {
        swap(heap[index], heap[smallest]);
        heapifyDown(smallest);
    }
}

template <typename T>
void MinHeap<T>::resize()
{
    capacity *= 2;
    T *newHeap = new T[capacity];
    for (int i = 0; i < size; i++)
    {
        newHeap[i] = heap[i];
    }
    delete[] heap;
    heap = newHeap;
}

// Insert
template <typename T>
void MinHeap<T>::insert(T value)
{
    if (size == capacity)
    {
        resize();
    }
    heap[size] = value;
    size++;
    heapifyUp(size - 1);
}

// Delete the minimum element
template <typename T>
void MinHeap<T>::deleteMin()
{
    if (size == 0)
    {
        throw runtime_error("Heap is empty! Cannot delete min.");
    }

    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
}

template <typename T>
void MinHeap<T>::print_heap() const
{
    if (size == 0)
    {
        cout << "Heap is empty!" << endl;
        return;
    }

    for (int i = 0; i < size; i++)
    {
        cout << heap[i] << " ";
    }
}

template <typename T>
T MinHeap<T>::getMin() const
{
    if (size > 0)
    {
        return heap[0];
    }
    throw runtime_error("Heap is empty");
}

template <typename T>
bool MinHeap<T>::isEmpty() const
{
    return size == 0;
}

template <typename T>
int MinHeap<T>::getSize() const
{
    return size;
}
