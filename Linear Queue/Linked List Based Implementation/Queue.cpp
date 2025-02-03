#include "Queue.h"

// QueueNode
template <typename T>
QueueNode<T>::QueueNode(T data) : data(data), next(nullptr)
{
}

template <typename T>
QueueNode<T>::QueueNode() : next(nullptr)
{
}

template <typename T>
QueueNode<T>::QueueNode(T data, QueueNode<T> *next) : data(data), next(next)
{
}

template <typename T>
void QueueNode<T>::setData(T data)
{
    this->data = data;
}

template <typename T>
T QueueNode<T>::getData() const
{
    return this->data;
}

template <typename T>
void QueueNode<T>::setNext(QueueNode<T> *next)
{
    this->next = next;
}

template <typename T>
QueueNode<T> *QueueNode<T>::getNext() const
{
    return this->next;
}

template <typename T>
Queue<T>::Queue() : front(nullptr), rear(nullptr), size(0) {}

template <typename T>
Queue<T>::Queue(const Queue<T> &other) : front(nullptr), rear(nullptr), size(0)
{
    if (!other.isEmpty())
    {
        QueueNode<T> *current = other.front;
        while (current != nullptr)
        {
            enqueue(current->data);
            current = current->next;
        }
    }
}

template <typename T>
Queue<T>::~Queue()
{
    while (!isEmpty())
    {
        dequeue();
    }
}

template <typename T>
void Queue<T>::enqueue(T element)
{
    if (isFull())
    {
        throw overflow_error("Queue is Full!");
    }

    QueueNode<T> *new_node = new QueueNode<T>(element, nullptr);
    if (rear == nullptr)
    {
        front = rear = new_node;
    }
    else
    {
        rear->next = new_node;
        rear = new_node;
    }
    size++;
}

template <typename T>
T Queue<T>::dequeue()
{
    if (isEmpty())
    {
        throw underflow_error("Queue is Empty!");
    }

    QueueNode<T> *temp = front;
    T value = front->data;
    front = front->next;

        if (front == nullptr)
    {
        rear = nullptr;
    }

    delete temp;
    size--;
    return value;
}

template <typename T>
int Queue<T>::currentSize() const
{
    return size;
}

template <typename T>
T Queue<T>::frontElement() const
{
    if (isEmpty())
    {
        throw underflow_error("Queue is Empty!");
    }
    return front->data;
}

template <typename T>
bool Queue<T>::isEmpty() const
{
    return front == nullptr;
}

template <typename T>
bool Queue<T>::isFull() const
{
    try
    {
        QueueNode<T> *temp = new QueueNode<T>();
        delete temp;
        return false;
    }
    catch (const bad_alloc &)
    {
        return true;
    }
}

template <typename T>
void Queue<T>::display() const
{
    if (isEmpty())
    {
        cout << "No elements to display!" << endl;
        return;
    }

    QueueNode<T> *temp = front;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
