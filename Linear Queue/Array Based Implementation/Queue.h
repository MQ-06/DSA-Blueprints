#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Queue
{
private:
    T *arr;
    int frontIndex;
    int rearIndex;
    int max_capacity;

public:
    Queue();
    Queue(int max_capacity);
    Queue(const Queue<T> &other);
    Queue<T> &operator=(const Queue<T> &other);
    ~Queue();

    void enqueue(const T element); // O(1) average, O(n) worst (when resizing)
    T dequeue();                   // O(1), O(n) when shifting of elements
    T getFront() const;            // O(1)
    bool isEmpty() const;          // O(1)
    bool isFull() const;           // O(1)
    int getSize() const;           // O(1)
    int getCapacity() const;       // O(1)
    T getBack() const;             // O(1)
    void display() const;          // O(n)

private:
    void resize(int newSize); // O(n)
};

#endif