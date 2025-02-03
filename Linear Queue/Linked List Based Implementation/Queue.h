#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
class QueueNode
{
public:
    T data;
    QueueNode<T> *next;
    QueueNode(T data);
    QueueNode();
    QueueNode(T data, QueueNode<T> *next);
    void setData(T data);
    T getData() const;
    void setNext(QueueNode<T> *next);
    QueueNode<T> *getNext() const;
};
template <typename T>

class Queue
{
    QueueNode<T> *front;
    QueueNode<T> *rear;
    int size;

public:
    Queue();
    Queue(const Queue<T> &other);
    void enqueue(T element);
    T dequeue();
    int currentSize() const;
    T frontElement() const;
    bool isEmpty() const;
    bool isFull() const;
    void display() const;
    ~Queue();
};