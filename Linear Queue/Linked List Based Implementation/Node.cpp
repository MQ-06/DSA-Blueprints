#include "Node.h"

template <typename T>

Node<T>::Node(T value) : data(value), next(nullptr)
{
}
template <typename T>

Node<T>::Node(T value, Node *next) : data(value), next(next)
{

}

template <typename T>

Node<T>::Node()
{
    data=T();
    next = nullptr;
}

template <typename T>

void Node<T>::set_value(T value)
{
    this->data = value;
}
template <typename T>

T Node<T>::get_value() const
{
    return this->data;
}
template <typename T>

Node<T> *Node<T>::get_node() const
{
    return next;
}
template <typename T>

void Node<T>::set_node(Node<T> *node)
{
    this->next = node;
}
