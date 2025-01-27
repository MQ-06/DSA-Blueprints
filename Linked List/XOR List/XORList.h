#include <iostream>
#include <vector>
#include "Node.cpp"

template <typename T>
class XORList
{
    Node<T> *XOR(Node<T> *one, Node<T> *two);

public:
    Node<T> *head;
    Node<T> *tail;
    XORList();
    ~XORList();
    void insertAtHead(T val);
    void insertAtTail(T val);
    int deleteAtHead();
    int deleteAtTail();
    void printList();
};