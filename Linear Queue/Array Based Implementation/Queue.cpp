#include "Queue.h"

template <typename T>
void Queue<T>::resize(int newSize)
{
    if (newSize <= 0)
    {
        throw invalid_argument("New size must be greater than zero.");
    }

    T *newArr = new T[newSize];
    int numElements = getSize();
    for (int i = 0; i < numElements; i++)
    {
        newArr[i] = arr[frontIndex + i];
    }
    delete[] arr;
    arr = newArr;
    frontIndex = 0;
    rearIndex = numElements - 1;
    max_capacity = newSize;
}

template <typename T>
Queue<T>::Queue()
{
    frontIndex = 0;
    rearIndex = -1;
    max_capacity = 10; // by default
    arr = new T[max_capacity];
}

template <typename T>
Queue<T>::Queue(int max_capacity)
{
    this->max_capacity = max_capacity;
    frontIndex = 0;
    rearIndex = -1;
    arr = new T[max_capacity];
}

template <typename T>
Queue<T>::Queue(const Queue<T> &other)
{
    this->max_capacity = other.max_capacity;
    this->frontIndex = other.frontIndex;
    this->rearIndex = other.rearIndex;
    arr = new T[max_capacity];
    for (int i = frontIndex; i <= rearIndex; i++)
    {
        this->arr[i] = other.arr[i];
    }
}

template <typename T>
Queue<T> &Queue<T>::operator=(const Queue<T> &other)
{
    if (this != &other)
    {
        delete[] arr;
        this->max_capacity = other.max_capacity;
        this->frontIndex = other.frontIndex;
        this->rearIndex = other.rearIndex;
        arr = new T[max_capacity];
        for (int i = frontIndex; i <= rearIndex; i++)
        {
            this->arr[i] = other.arr[i];
        }
    }
    return *this;
}

template <typename T>
Queue<T>::~Queue()
{
    delete[] arr;
}

template <typename T>
void Queue<T>::enqueue(const T element)
{
    if (isFull())
    {
        resize(max_capacity * 2);
    }
    arr[++rearIndex] = element;
}

template <typename T>
T Queue<T>::dequeue()
{
    if (isEmpty())
    {
        throw underflow_error("Queue is empty! Cannot dequeue.");
    }
    return arr[frontIndex++];
}

template <typename T>
T Queue<T>::getFront() const
{
    if (isEmpty())
    {
        throw underflow_error("Queue is empty! Cannot get front element.");
    }
    return arr[frontIndex];
}

template <typename T>
bool Queue<T>::isEmpty() const
{
    return frontIndex > rearIndex;
}

template <typename T>
bool Queue<T>::isFull() const
{
    return rearIndex == max_capacity - 1;
}

template <typename T>
int Queue<T>::getSize() const
{
    return rearIndex - frontIndex + 1;
}

template <typename T>
int Queue<T>::getCapacity() const
{
    return max_capacity;
}

template <typename T>
T Queue<T>::getBack() const
{
    if (isEmpty())
    {
        throw underflow_error("Queue is empty! Cannot get back element.");
    }
    return arr[rearIndex];
}

template <typename T>
void Queue<T>::display() const
{
    if (isEmpty())
    {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Queue elements: ";
    for (int i = frontIndex; i <= rearIndex; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}