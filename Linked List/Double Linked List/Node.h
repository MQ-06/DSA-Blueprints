#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include <limits>
#include <algorithm>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node<T> *prev;
    Node();
    ~Node();
    Node(T data);
    Node(T data, Node *next);
    Node(T data, Node *next, Node *prev);
    void set_data(T data);
    void set_next(Node<T> *next);
    void set_prev(Node<T> *prev);
    T get_data(T data) const;
    Node<T> *get_next() const;
    Node<T> *get_prev() const;

public:
};