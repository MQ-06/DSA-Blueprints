#include "XORList.h"

template <typename T>
XORList<T>::XORList() : head(nullptr), tail(nullptr) {}
template <typename T>
XORList<T>::~XORList()
{
    while (head)
    {
        deleteAtHead();
    }
}
template <typename T>
void XORList<T>::insertAtHead(T val)
{
    Node<T> *new_node = new Node<T>(val);
    new_node->npx = head;

    if (head != nullptr)
    {
        head->npx = XOR(head->npx, new_node);
    }

    head = new_node;

    if (tail == nullptr)
    {
        tail = new_node;
    }
}
template <typename T>

void XORList<T>::insertAtTail(T val)
{
    Node<T> *new_node = new Node<T>(val);
    if (tail == nullptr)
    {
        head = tail = new_node;
        return;
    }

    tail->npx = XOR(tail->npx, new_node);
    new_node->npx = tail;
    tail = new_node;
}
template <typename T>

int XORList<T>::deleteAtHead()
{
    if (head == nullptr)
    {
        cout << "List is empty, cannot delete." << endl;
        return -1;
    }

    Node<T> *temp = head;
    int val = temp->data;

    Node<T> *next = XOR(temp->npx, nullptr);
    if (next != nullptr)
    {
        next->npx = XOR(next->npx, temp);
    }

    head = next;

    if (head == nullptr)
    {
        tail = nullptr;
    }

    delete temp;
    return val;
}
template <typename T>

int XORList<T>::deleteAtTail()
{
    if (tail == nullptr)
    {
        cout << "List is empty, cannot delete." << endl;
        return -1;
    }

    Node<T> *curr = tail;
    int val = curr->data;

    Node<T> *prev = XOR(curr->npx, nullptr);
    if (prev != nullptr)
    {
        prev->npx = XOR(prev->npx, curr);
    }

    tail = prev;

    if (tail == nullptr)
    {
        head = nullptr;
    }
    tail = prev;
    delete curr;
    return val;
}
template <typename T>

void XORList<T>::printList()
{

    if (head == nullptr)
    {
        cout << "no nodes to display" << endl;
        return;
    }
    Node<T> *curr = head;
    Node<T> *prev = nullptr;

    cout << "XOR Linked List: ";
    while (curr != nullptr)
    {
        cout << curr->data << " ";

        Node<T> *next = XOR(prev, curr->npx);
        prev = curr;
        curr = next;
    }
    cout << endl;
}

template <typename T>

Node<T> *XORList<T>::XOR(Node<T> *a, Node<T> *b)
{
    return reinterpret_cast<Node<T> *>(
        reinterpret_cast<uintptr_t>(a) ^ reinterpret_cast<uintptr_t>(b));
}
