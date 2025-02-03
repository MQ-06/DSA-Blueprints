#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>

class CircularQueue
{

    int front;
    int rear;
    int capacity;
    T *arr;
    void resize(int newSize);

public:
    CircularQueue(int size);                                    // O(1)
    CircularQueue();                                            // O(1)
    ~CircularQueue();                                           // O(1)
    CircularQueue(const CircularQueue<T> &other);               // O(n)
    CircularQueue<T> &operator=(const CircularQueue<T> &other); // O(n)
    void enqueue(const T &data);                                // O(1)
    T dequeue();                                                // O(1)
    bool isEmpty() const;                                       // O(1)
    bool isFull() const;                                        // O(1)
    int size() const;                                           // O(1)
    T peek() const;                                             // O(1)
    void display() const;                                       // O(n)
};

#endif