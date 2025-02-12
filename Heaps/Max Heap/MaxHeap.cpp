
#include "MaxHeap.h"
#include <iostream>
using namespace std;
// Constructor
template <typename T>
MaxHeap<T>::MaxHeap(int initialCapacity)
{
    capacity = initialCapacity;
    size = 0;
    heap = new T[capacity];
}

// Destructor
template <typename T>
MaxHeap<T>::~MaxHeap()
{
    delete[] heap;
}

// Copy Constructor
template <typename T>
MaxHeap<T>::MaxHeap(const MaxHeap<T> &other)
{
    capacity = other.capacity;
    size = other.size;
    heap = new T[capacity];
    for (int i = 0; i < size; i++)
    {
        heap[i] = other.heap[i];
    }
}

// Insert a value into the heap
template <typename T>
void MaxHeap<T>::insert(T value)
{
    if (size == capacity)
    {
        resize();
    }
    heap[size] = value;
    heapifyUp(size);
    size++;
}

// Delete the maximum value (root) from the heap
template <typename T>
void MaxHeap<T>::deleteMax()
{
    if (isEmpty())
    {
        throw std::underflow_error("Heap is empty");
    }
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
}

// Heapify Up: Maintains the max-heap property by moving the element up
template <typename T>
void MaxHeap<T>::heapifyUp(int index)
{
    int parent = (index - 1) / 2;
    while (index > 0 && heap[index] > heap[parent])
    {
        std::swap(heap[index], heap[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

// Heapify Down: Maintains the max-heap property by moving the element down
template <typename T>
void MaxHeap<T>::heapifyDown(int index)
{
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int largest = index;

    if (leftChild < size && heap[leftChild] > heap[largest])
    {
        largest = leftChild;
    }
    if (rightChild < size && heap[rightChild] > heap[largest])
    {
        largest = rightChild;
    }
    if (largest != index)
    {
        std::swap(heap[index], heap[largest]);
        heapifyDown(largest);
    }
}

// Resize the heap when it reaches capacity
template <typename T>
void MaxHeap<T>::resize()
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

// Print the heap
template <typename T>
void MaxHeap<T>::print_heap() const
{
    for (int i = 0; i < size; i++)
    {
        std::cout << heap[i] << " ";
    }
    std::cout << std::endl;
}

// Get the maximum value (root) of the heap
template <typename T>
T MaxHeap<T>::getMax() const
{
    if (isEmpty())
    {
        throw std::underflow_error("Heap is empty");
    }
    return heap[0];
}

// Check if the heap is empty
template <typename T>
bool MaxHeap<T>::isEmpty() const
{
    return size == 0;
}

// Get the size of the heap
template <typename T>
int MaxHeap<T>::getSize() const
{
    return size;
}

