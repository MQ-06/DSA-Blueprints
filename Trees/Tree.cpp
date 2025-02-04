#include "Tree.h"

template <typename T>
Tree<T>::Tree(int initial_capacity) : capacity(initial_capacity)
{
    nodes = new T[capacity];
    for (int i = 0; i < capacity; i++)
    {
        nodes[i] = get_min();
    }
}

template <typename T>
Tree<T>::~Tree()
{
    delete[] nodes;
}

template <typename T>
Tree<T>::Tree(const Tree &other) : capacity(other.capacity)
{
    nodes = new T[capacity];
    for (int i = 0; i < capacity; i++)
    {
        nodes[i] = other.nodes[i];
    }
}

template <typename T>
void Tree<T>::resize(int new_capacity)
{
    if (new_capacity <= capacity)
    {
        throw invalid_argument("New capacity must be greater than current capacity.");
    }

    T *new_nodes = new T[new_capacity];
    for (int i = 0; i < new_capacity; i++)
    {
        new_nodes[i] = (i < capacity) ? nodes[i] : get_min();
    }

    delete[] nodes;
    nodes = new_nodes;
    capacity = new_capacity;
}

template <typename T>
T Tree<T>::get_min()
{
    return numeric_limits<T>::min();
}

template <typename T>
void Tree<T>::set_min(int index)
{
    nodes[index] = get_min();
}

template <typename T>
void Tree<T>::setLeftChild(int index, T value)
{
    if (index < 0 || index >= capacity || nodes[index] == get_min())
    {
        throw invalid_argument("Invalid index or parent node doesn't exist");
    }
    int lchild_index = 2 * index + 1;
    if (lchild_index >= capacity)
    {
        resize(2 * capacity);
    }
    nodes[lchild_index] = value;
}

template <typename T>
void Tree<T>::setRightChild(int index, T value)
{
    if (index < 0 || index >= capacity || nodes[index] == get_min())
    {
        throw invalid_argument("Invalid index or parent node doesn't exist");
    }
    int rchild_index = 2 * index + 2;
    if (rchild_index >= capacity)
    {
        resize(2 * capacity);
    }
    nodes[rchild_index] = value;
}

template <typename T>
T Tree<T>::getParent(int index)
{
    if (index <= 0 || index >= capacity)
    {
        throw invalid_argument("Root has no parent or index is out of bounds");
    }
    return nodes[(index - 1) / 2];
}

template <typename T>
void Tree<T>::deleteLeftChild(int index)
{
    int lchild_index = 2 * index + 1;
    if (index < 0 || lchild_index >= capacity || nodes[lchild_index] == get_min())
    {
        throw invalid_argument("Invalid index or left child doesn't exist");
    }
    set_min(lchild_index);
}

template <typename T>
void Tree<T>::deleteRightChild(int index)
{
    int rchild_index = 2 * index + 2;
    if (index < 0 || rchild_index >= capacity || nodes[rchild_index] == get_min())
    {
        throw invalid_argument("Invalid index or right child doesn't exist");
    }
    set_min(rchild_index);
}

template <typename T>
void Tree<T>::setRoot(T value)
{
    nodes[0] = value;
}

template <typename T>
void Tree<T>::displayTree()
{
    int level = 0;
    int elements = 1;
    int curr_index = 0;
    while (curr_index < capacity)
    {
        for (int i = 0; i < elements && curr_index < capacity; i++, curr_index++)
        {
            if (nodes[curr_index] != get_min())
            {
                cout << nodes[curr_index] << " ";
            }
            else
            {
                cout << "_ ";
            }
        }
        cout << endl;

        level++;
        elements *= 2;
    }
}
