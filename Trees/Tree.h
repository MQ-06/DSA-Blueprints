#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <stdexcept>
#include <limits>
using namespace std;

template <typename T>
class Tree
{
    T *nodes;
    int capacity;

    T get_min();
    void set_min(int index);

public:
    Tree(int initial_capacity = 10);
    ~Tree();
    Tree(const Tree &other);
    void resize(int new_capacity);
    void setLeftChild(int index, T value);
    void setRightChild(int index, T value);
    T getParent(int index);
    void deleteLeftChild(int index);
    void deleteRightChild(int index);
    void setRoot(T value);
    void displayTree();
};

#endif
