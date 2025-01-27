#include "Node.h"

template <typename T>
Node<T>::Node() : data(T()), npx(nullptr) {}  

template <typename T>
Node<T>::~Node() {}  

template <typename T>
Node<T>::Node(T data, Node<T> *node) : data(data), npx(node) {}  

template <typename T>
Node<T>::Node(T data) : data(data), npx(nullptr) {}  

template <typename T>
void Node<T>::set_data(T data) { 
    this->data = data; 
}

template <typename T>
T Node<T>::get_data() const { 
    return this->data; 
}

template <typename T>
void Node<T>::set_Node(Node<T> *npx) { 
    this->npx = npx; 
}

template <typename T>
Node<T> *Node<T>::get_Node() const { 
    return this->npx; 
}
