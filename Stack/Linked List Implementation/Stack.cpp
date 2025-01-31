#include "Stack.h"
#include<iostream>
#include <stdexcept>
using namespace std;
// stack node
template <typename T>

StackNode<T>::StackNode(T data)
{
    this->data = data;
    next = nullptr;
}

template <typename T>

StackNode<T>::StackNode()
{
    next = nullptr;
}
template <typename T>

StackNode<T>::StackNode(T data, StackNode<T> *next)
{

    this->data = data;
    this->next = next;
}
template <typename T>

void StackNode<T>::setData(T data)
{
    this->data = data;
}
template <typename T>

T StackNode<T>::getData() const
{
    return data;
}
template <typename T>

void StackNode<T>::setNext(StackNode<T> *next)
{
    this->next = next;
}
template <typename T>

StackNode<T> StackNode<T>::getNext() const
{
    return next;
}

// stack class
template <typename T>

Stack<T>::Stack()
{
    top = nullptr;
    size = 0;
}
template <typename T>

Stack<T>::~Stack()
{
    // StackNode<T> *temp = top;
    // while (temp != nullptr)
    // {
    //     StackNode<T> *new_node = temp->getNext();
    //     delete temp;
    //     temp = new_node;
    // }
    // top=nullptr;
    // size=0;

    while (!isEmpty())
    {
        pop();
    }
}
template <typename T>

Stack<T>::Stack(const Stack<T> &other)
{
    top = nullptr;
    size = 0;
    StackNode<T> *curr = other.top;
    while (curr != nullptr)
    {
        push(curr->data);
        curr = curr->next;
    }
}
template <typename T>

T Stack<T>::getTop()
{
    if (isEmpty())
    {
        throw underflow_error("Stack underflow!");
    }
    return top->data;
}
template <typename T>

T Stack<T>::pop()
{
    if (isEmpty())
    {
        throw underflow_error("Stack underflow!");
    }
    StackNode<T> *temp = top;
    T value = temp->data;
    top = top->next;
    delete temp;
    size--;
    return value;
}
template <typename T>

void Stack<T>::push(T Element)
{
    if (isFull())
    {
        throw overflow_error("Stack overflow!");
    }
    StackNode<T> *new_node = new StackNode<T>();
    new_node->data = Element;
    new_node->next = top;
    top = new_node;
    size++;
}
template <typename T>

int Stack<T>::currSize()
{
    return size;
}
template <typename T>

bool Stack<T>::isEmpty()const
{
    return top == nullptr;
}
template <typename T>

bool Stack<T>::isFull()const
{
    try
    {
        StackNode<T> *node = new StackNode<T>();
        delete node;
        return false;
    }
    catch (const bad_alloc &e)
    {
        return true;
    }
}
template <typename T>

T Stack<T>::Peek(int nodeNumber)
{

    if (isEmpty())
    {
        throw underflow_error("Stack underflow!");
    }

    if (nodeNumber < 1 || nodeNumber > size)
    {
        throw invalid_argument("Invalid nodeNumber");
    }
    StackNode<T> *current = top;
    for (int i = 1; i < nodeNumber; i++)
    {
        current = current->next;
    }

    return current->data;
}
template <typename T>
void Stack<T>::display() const
{
    if (isEmpty())
    {
        cout << "No elements to display!" << endl;
        return;
    }
    StackNode<T> *temp = top;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}