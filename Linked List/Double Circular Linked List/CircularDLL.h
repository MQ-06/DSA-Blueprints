#ifndef CircularDLL_H
#define CircularDLL_H
#include "Node.cpp"

template <typename T>
class CircularDLL
{

public:
    Node<T> *head;
    void insert_before_head(T value);
    void insert_after_head(T value);
    void insert_after_tail(T value);
    void insert_before_tail(T value);
    CircularDLL();
    ~CircularDLL();
    CircularDLL(CircularDLL &node);
    void insert_at_head(T value);
    void insert_at_tail(T value);
    void delete_at_head();
    void delete_at_tail();
    void print_List();
    Node<T> *get_node(int n);
    bool insert_after(T value, T key);
    bool insert_before(T value, T key);
    bool delete_before(T key);
    bool delete_after(T key);
    int length();
    Node<T> *search(T value);
    bool remove_kth_node(int value);
};

#endif