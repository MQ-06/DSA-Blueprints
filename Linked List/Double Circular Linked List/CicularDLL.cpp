#include "CircularDLL.h"

template <typename T>

void CircularDLL<T>::insert_before_head(T value)
{

    if (head == nullptr)
    {
        insert_at_head(value);
    }
    else
    {
        if (head->next == head && head->prev == head)
        {
            Node<T> *new_node = new Node<T>(value, head, head);
            head->prev = new_node;
            head->next = new_node;
            head = new_node;
        }
        else
        {
            Node<T> *new_node = new Node<T>(value);
            Node<T> *tail = head->prev;
            head->prev = new_node;
            new_node->next = head;
            new_node->prev = tail;
            tail->next = new_node;
            head = new_node;
        }
    }
}

template <typename T>

void CircularDLL<T>::insert_after_head(T value)
{
    if (head == nullptr)
    {
        insert_at_head(value);
    }
    else if (head->next == head)
    {
        Node<T> *new_node = new Node<T>(value);
        head->next = new_node;
        new_node->prev = head;
        new_node->next = head;
        head->prev = new_node;
    }
    else
    {
        Node<T> *new_node = new Node<T>(value);
        Node<T> *next = head->next;
        new_node->next = next;
        next->prev = new_node;
        head->next = new_node;
        new_node->prev = head;
    }
}
template <typename T>

void CircularDLL<T>::insert_after_tail(T value)
{
    if (head == nullptr)
    {
        Node<T> *new_node = new Node<T>(value);
        head = new_node;
        head->next = new_node;
        head->prev = new_node;
    }
    else if (head->next == head)
    {
        Node<T> *new_node = new Node<T>(value, head, head);
        head->prev = new_node;
        head->next = new_node;
    }
    else
    {
        Node<T> *new_node = new Node<T>(value);
        Node<T> *old_tail = head->prev;
        old_tail->next = new_node;
        new_node->prev = old_tail;
        new_node->next = head;
        head->prev = new_node;
    }
}
template <typename T>

void CircularDLL<T>::insert_before_tail(T value)
{

    if (head == nullptr)
    {
        insert_at_tail(value);
    }
    else if (head->next == head)
    {
        Node<T> *new_node = new Node<T>(value, head, head);
        head->prev = new_node;
        head->next = new_node;
    }
    else
    {
        Node<T> *new_node = new Node<T>(value);

        Node<T> *tail = head->prev;
        Node<T> *tail_prev = tail->prev;
        tail_prev->next = new_node;
        new_node->prev = tail_prev;
        new_node->next = tail;
        tail->prev = new_node;
    }
}
template <typename T>

CircularDLL<T>::CircularDLL() : head(nullptr)
{
}
template <typename T>

CircularDLL<T>::~CircularDLL()
{
    if (head == nullptr)
        return;
    Node<T> *temp = head;
    do
    {
        Node<T> *next = temp->next;
        delete temp;
        temp = next;
    } while (temp != head);
    head = nullptr;
}

template <typename T>
CircularDLL<T>::CircularDLL(CircularDLL &other)
{
    if(other.head==nullptr){
        head=nullptr;
        return;
    }
    head=new Node<T>(other.head->data);
    Node<T>*curr=head;
    Node<T>* temp=other.head->next;
    while(temp!=other.head){
        Node<T>* new_node=new Node<T>(temp->data);
        curr->next=new_node;
        new_node->prev=curr;
        curr=new_node;
        temp=temp->next;
    }
    curr->next=head;
    head->prev=curr;
}

template <typename T>

void CircularDLL<T>::insert_at_head(T value)
{
    if (head == nullptr)
    {
        Node<T> *new_node = new Node<T>(value, new_node, new_node);
        head = new_node;
    }
    else
    {
        Node<T> *tail = head->prev;
        Node<T> *new_node = new Node<T>(value, head);
        new_node->prev = tail;
        head->prev = new_node;
        tail->next = new_node;
        head = new_node;
    }
}
template <typename T>

void CircularDLL<T>::insert_at_tail(T value)
{
    if (head == nullptr)
    {
        Node<T> *new_node = new Node<T>(value, new_node, new_node);
        head = new_node;
    }
    else
    {
        Node<T> *new_node = new Node<T>(value);
        Node<T> *tail = head->prev;
        tail->next = new_node;
        new_node->prev = tail;
        new_node->next = head;
        head->prev = new_node;
    }
}
template <typename T>

void CircularDLL<T>::delete_at_head()
{
    if (head == nullptr)
    {
        return;
    }
    if (head->next == head && head->prev == head)
    {
        delete head;
        head = nullptr;
        return;
    }
    Node<T> *deleted_node = head;
    Node<T> *tail = head->prev;
    Node<T> *next = head->next;
    next->prev = tail;
    tail->next = next;
    head = next;
    delete deleted_node;
}
template <typename T>

void CircularDLL<T>::delete_at_tail()
{
    if (head == nullptr)
    {
        return;
    }
    if (head->next == head && head->prev == head)
    {
        delete head;
        head = nullptr;
        return;
    }
    Node<T> *tail = head->prev;
    Node<T> *before_tail = tail->prev;
    before_tail->next = head;
    head->prev = before_tail;
    delete tail;
}
template <typename T>

void CircularDLL<T>::print_List()
{

    if (head == nullptr)
    {
        cout << "The list is empty." << endl;
        return;
    }

    Node<T> *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    Node<T> *tail = head->prev;
    do
    {
        cout << tail->data << " ";
        tail = tail->prev;
    } while (tail != head->prev);
}
template <typename T>

Node<T> *CircularDLL<T>::get_node(int n)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    int count = 0;
    Node<T> *temp = head;
    while (temp != head && count < n)
    {
        temp = temp->next;
        count++;
    }
    return temp;
}
template <typename T>

bool CircularDLL<T>::insert_after(T value, T key)
{
    if (head == nullptr)
        return false;

    Node<T> *temp = head;
    if (head->data == key)
    {
        insert_after_head(value);
        return true;
    }
    do
    {
        if (temp->data == key)
        {
            Node<T> *new_node = new Node<T>(value);
            Node<T> *next = temp->next;
            next->prev = new_node;
            new_node->next = next;
            new_node->prev = temp;
            temp->next = new_node;
            return true;
        }
        temp = temp->next;
    } while (temp != head);
    return false;
}
template <typename T>

bool CircularDLL<T>::insert_before(T value, T key)
{
    if (head == nullptr)
        return false;
    Node<T> *temp = head;
    if (head->data == key)
    {
        insert_before_head(value);
        return true;
    }
    do
    {
        if (temp->data == key)
        {
            Node<T> *new_node = new Node<T>(value);
            Node<T> *prev = temp->prev;
            prev->next = new_node;
            new_node->prev = prev;
            new_node->next = temp;
            temp->prev = new_node;
            return true;
        }
        temp = temp->next;
    } while (temp != head);
    return false;
}
template <typename T>

bool CircularDLL<T>::delete_before(T key)
{
    if (head == nullptr)
        return false;
    if (head->data == key && head->next == nullptr)
        return false;

    Node<T> *temp = head;
    do
    {
        if (temp->data == key)
        {
            Node<T> *deleted_node = temp->prev;
            temp->prev = deleted_node->prev;
            deleted_node->prev->next = temp;
            delete deleted_node;
            return true;
        }
        temp = temp->next;

    } while (temp != head);
    return false;
}
template <typename T>

bool CircularDLL<T>::delete_after(T key)
{
    if (head == nullptr)
        return false;
    if (head->data == key && head->next == nullptr)
        return false;

    Node<T> *temp = head;
    do
    {
        if (temp->data == key)
        {
            Node<T> *deleted_node = temp->next;
            temp->next = deleted_node->next;
            deleted_node->next->prev = temp;
            delete deleted_node;
            return true;
        }
        temp = temp->next;

    } while (temp != head);
    return false;
}
template <typename T>

int CircularDLL<T>::length()
{
    if (head == nullptr)
    {
        return 0;
    }
    Node<T> *temp = head;
    int count = 0;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}
template <typename T>

Node<T> *CircularDLL<T>::search(T value)
{
    if (head == nullptr)
        return nullptr;
    Node<T> *temp = head;
    do
    {
        if (temp->data == value)
        {
            return temp;
        }
        temp = temp->next;
    } while (temp != head);
    return nullptr;
}
template <typename T>

bool CircularDLL<T>::remove_kth_node(int value)
{
}