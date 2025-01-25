#include "Node.h"

template <typename T>
Node<T>::Node() : prev(nullptr), next(nullptr) {}
template <typename T>

Node<T>::~Node()
{
    delete next;
    delete prev;
}
template <typename T>

Node<T>::Node(T data) : data(data), prev(nullptr), next(nullptr)
{
}
template <typename T>

Node<T>::Node(T data, Node *next) : prev(nullptr), next(next), data(data)
{
}
template <typename T>

Node<T>::Node(T data, Node *next, Node *prev) : prev(prev), next(next), data(data)
{
}
template <typename T>

void Node<T>::set_data(T data)
{
    this->data = data;
}
template <typename T>

void Node<T>::set_next(Node<T> *next)
{
    this->next = next;
}
template <typename T>

void Node<T>::set_prev(Node<T> *prev)
{
    this->prev = prev;
}
template <typename T>

T Node<T>::get_data(T data) const
{
    return data;
}
template <typename T>

Node<T> *Node<T>::get_next() const
{
    return next;
}
template <typename T>

Node<T> *Node<T>::get_prev() const
{
    return prev;
}