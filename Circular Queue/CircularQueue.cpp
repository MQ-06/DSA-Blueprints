
#include "CircularQueue.h"
template <typename T>
CircularQueue<T>::CircularQueue(int size)
{
    front = -1;
    rear = -1;
    this->capacity = size;
    arr = new T[capacity];
}

template <typename T>
CircularQueue<T>::CircularQueue() : capacity(10)
{
    front = -1;
    rear = -1;
    arr = new T[capacity];
}

template <typename T>
CircularQueue<T>::~CircularQueue()
{
    delete[] arr;
}

template <typename T>
CircularQueue<T>::CircularQueue(const CircularQueue<T> &other)
{
    capacity = other.capacity;
    front = other.front;
    rear = other.rear;
    arr = new T[capacity];

    for (int i = 0; i < capacity; i++)
    {
        arr[i] = other.arr[i];
    }
}

template <typename T>
CircularQueue<T> &CircularQueue<T>::operator=(const CircularQueue<T> &other)
{
    if (this != &other)
    {
        delete[] arr;

        capacity = other.capacity;
        front = other.front;
        rear = other.rear;
        arr = new T[capacity];

        for (int i = 0; i < capacity; i++)
        {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

template <typename T>
void CircularQueue<T>::enqueue(const T &data)
{
    if (isFull())
    {
        // resize(capacity * 2);
        cout << "Queue is full!" << endl;
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    rear = (rear + 1) % capacity;
    arr[rear] = data;
}

template <typename T>
T CircularQueue<T>::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is Empty! Can't remove an element" << endl;
        throw underflow_error("Queue is empty");
    }
    T element = arr[front];
    arr[front] = T();

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % capacity;
    }
    return element;
}

template <typename T>
bool CircularQueue<T>::isEmpty() const
{
    return front == -1;
}

template <typename T>
bool CircularQueue<T>::isFull() const
{
    return (front == 0 && rear == capacity - 1) || (front == (rear + 1) % capacity);
}

template <typename T>
int CircularQueue<T>::size() const
{
    if (front == -1)
    {
        return 0;
    }
    else if (rear >= front)
    {
        return rear - front + 1;
    }
    else
    {
        return (capacity - front + rear + 1);
    }
}

template <typename T>
T CircularQueue<T>::peek() const
{
    if (isEmpty())
    {
        throw underflow_error("Queue is empty");
    }
    return arr[front];
}

template <typename T>
void CircularQueue<T>::display() const
{
    if (isEmpty())
    {
        cout << "Queue is empty!" << endl;
        return;
    }

    int index = front;
    cout << "Queue elements: ";
    while (true)
    {
        cout << arr[index] << " ";
        if (index == rear)
            break;
        index = (index + 1) % capacity;
    }
    cout << endl;
}

template <typename T>
void CircularQueue<T>::resize(int newSize)
{
    if (newSize <= 0)
    {
        throw invalid_argument("New size must be greater than zero.");
    }

    T *newArr = new T[newSize];
    int currentSize = size();

    for (int i = 0; i < currentSize; i++)
    {
        newArr[i] = arr[(front + i) % capacity];
    }

    delete[] arr;
    arr = newArr;
    front = 0;
    rear = currentSize - 1;
    capacity = newSize;
}