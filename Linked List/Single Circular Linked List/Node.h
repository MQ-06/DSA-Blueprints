#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include <limits>
#include <algorithm>

template <typename T>

class Node
{

public:
    T data;
    Node<T> *next;
    Node();
    Node(T value);
    Node(T value, Node *next);
    void set_value(T value);
    T get_value()const;
    Node<T>* get_node()const;
    void set_node(Node<T> *node);
    
};

#endif