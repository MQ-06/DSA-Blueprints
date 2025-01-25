#include "DoubleLinkedList.h"

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList() : head(nullptr), tail(nullptr) {}

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(const DoubleLinkedList &node)
{

    if (node.head == nullptr)
    {
        head = nullptr;
        return;
    }
    head = new Node<T>(node.head->data);
    Node<T> *temp = node.head->next;
    Node<T> *curr = head;

    while (temp != nullptr)
    {
        Node<T> *new_node = new Node<T>(temp->data);
        curr->next = new_node;
        new_node->prev = curr;
        curr = new_node;
        temp = temp->next;
    }
    tail = curr;
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        Node<T> *after = temp->next;
        delete temp;
        temp = after;
    }
}

template <typename T>
bool DoubleLinkedList<T>::insert_after(T value, T key)
{
    if (head == nullptr)
        return false;

    if (head->data == key)
    {
        insert_after_head(value);
        return true;
    }
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == key)
        {
            Node<T> *new_node = new Node<T>(value);
            Node<T> *next = temp->next;
            temp->next = new_node;
            new_node->prev = temp;
            new_node->next = next;
            if (next != nullptr)
                next->prev = new_node;
            else
                tail = new_node;
            return true;
        }
        temp = temp->next;
    }

    return false;
}

template <typename T>
Node<T> *DoubleLinkedList<T>::get_node(int n)
{
    if (head == nullptr || n < 1)
    {
        return nullptr;
    }

    int count = 1;
    Node<T> *temp = head;
    while (temp != nullptr && count < n)
    {
        temp = temp->next;
        count++;
    }
    if (temp != nullptr)
        return temp;
    return tail;
}

template <typename T>
bool DoubleLinkedList<T>::insert_before(T value, T key)
{
    if (head == nullptr)
        return false;

    if (head->data == key)
    {
        insert_before_head(value);
        return true;
    }
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == key)
        {
            Node<T> *new_node = new Node<T>(value);
            Node<T> *prev = temp->prev;
            new_node->next = temp;
            new_node->prev = prev;
            if (prev != nullptr)
            {
                prev->next = new_node;
            }
            else
            {
                head = new_node;
            }
            temp->prev = new_node;
            return true;
        }
        temp = temp->next;
    }

    return false;
}

template <typename T>
bool DoubleLinkedList<T>::delete_before(T key)
{
    if (head == nullptr)
        return false;
    if (head->data == key && head->next == nullptr)
    {
        cout << "No node before head!";
        return false;
    }

    Node<T> *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == key)
        {
            if (temp->prev == nullptr)
            {
                cout << "No node before head!";
                return false;
            }
            Node<T> *deleted_node = temp->prev;
            if (deleted_node->prev != nullptr)
            {
                deleted_node->prev->next = temp;
            }
            else
            {
                head = temp;
            }
            temp->prev = deleted_node->prev;
            delete deleted_node;
            return true;
        }
        temp = temp->next;
    }

    return false;
}

template <typename T>
bool DoubleLinkedList<T>::delete_after(T key)
{
    if (head == nullptr)
        return false;
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == key)
        {
            Node<T> *next = temp->next;
            if (next == nullptr)
                return false;
            temp->next = next->next;
            if (next->next != nullptr)
            {
                next->next->prev = temp;
            }
            delete next;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

template <typename T>
Node<T> *DoubleLinkedList<T>::search(T value)
{
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == value)
        {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

template <typename T>
bool DoubleLinkedList<T>::remove_kth_node(int value)
{
    if (!head)
        return false;

    Node<T> *temp = head;
    do
    {
        if (temp->data == value)
        {
            if (temp->next == nullptr && temp->prev == nullptr)
            {
                head = nullptr;
            }
            else
            {
                temp->prev->next = temp->next;
                if (temp->next != nullptr)
                {
                    temp->next->prev = temp->prev;
                }
                if (temp == head)
                {
                    head = head->next;
                }
            }
            delete temp;
            return true;
        }
        temp = temp->next;
    } while (temp != nullptr);

    return false;
}

template <typename T>
void DoubleLinkedList<T>::insert_at_head(T value)
{
    Node<T> *new_node = new Node<T>(value);
    if (head == nullptr)
    {
        new_node->next = nullptr;
        new_node->prev = nullptr;
        head = new_node;
        tail = new_node;
    }
    else
    {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
}

template <typename T>
void DoubleLinkedList<T>::insert_at_tail(T value)
{
    Node<T> *new_node = new Node<T>(value);
    if (head == nullptr)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {

        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
}

template <typename T>
void DoubleLinkedList<T>::print_List()
{
    if (head == nullptr)
    {
        cout << "No nodes to display" << endl;
        return;
    }
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

template <typename T>
int DoubleLinkedList<T>::length()
{
    if (head == nullptr)
        return 0;

    Node<T> *temp = head;
    int count = 0;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

template <typename T>
bool DoubleLinkedList<T>::delete_at_head()
{
    if (head == nullptr)
        return false;

    Node<T> *deleted_node = head;
    head = head->next;
    if (head != nullptr)
    {
        head->prev = nullptr;
    }
    else
    {
        tail = nullptr;
    }

    delete deleted_node;
    return true;
}

template <typename T>
bool DoubleLinkedList<T>::delete_at_tail()
{
    if (head == nullptr)
        return false;

    if (tail == head)
    {
        delete tail;
        tail = nullptr;
        head = nullptr;
        return true;
    }
    Node<T> *prev = tail->prev;
    delete tail;
    tail = prev;
    if (tail != nullptr)
    {
        tail->next = nullptr;
    }
    return true;
}

template <typename T>
void DoubleLinkedList<T>::insert_before_head(T value)
{
    Node<T> *new_Node = new Node<T>(value);

    if (head == nullptr)
    {
        head = new_Node;
        tail = new_Node;
        new_Node->next = nullptr;
        new_Node->prev = nullptr;
        return;
    }

    new_Node->next = head;
    head->prev = new_Node;
    new_Node->prev = nullptr;
    head = new_Node;
}

template <typename T>
void DoubleLinkedList<T>::insert_after_head(T value)
{
    Node<T> *new_Node = new Node<T>(value);
    if (head == nullptr)
    {
        head = new_Node;
        tail = new_Node;
        new_Node->next = nullptr;
        new_Node->prev = nullptr;
        return;
    }
    if (head->next == nullptr)
    {
        head->next = new_Node;
        new_Node->prev = head;
        new_Node->next = nullptr;
        tail = new_Node;
    }
    else
    {
        Node<T> *next = head->next;
        next->prev = new_Node;
        new_Node->next = next;
        head->next = new_Node;
        new_Node->prev = head;
    }
}
template <typename T>
void DoubleLinkedList<T>::insert_after_tail(T value)
{

    Node<T> *new_Node = new Node<T>(value);

    if (head == nullptr)
    {
        head = new_Node;
        tail = new_Node;
        new_Node->next = nullptr;
        new_Node->prev = nullptr;
        return;
    }

    tail->next = new_Node;
    new_Node->prev = tail;
    new_Node->next = nullptr;
    tail = new_Node;
}
template <typename T>
void DoubleLinkedList<T>::insert_before_tail(T value)
{

    Node<T> *new_Node = new Node<T>(value);
    if (head == nullptr)
    {
        head = new_Node;
        tail = new_Node;
        new_Node->next = nullptr;
        new_Node->prev = nullptr;
        return;
    }
    if (head->next == nullptr)
    {
        insert_before_head(value);
        return;
    }
    Node<T> *prev = tail->prev;

    new_Node->prev = prev;
    new_Node->next = tail;
    if (prev != nullptr)
    {
        prev->next = new_Node;
    }
    else
    {
        head = new_Node;
    }

    tail->prev = new_Node;
}