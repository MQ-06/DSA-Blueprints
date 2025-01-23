#include "LinkedList.h"
using namespace std;

template <typename T>

LinkedList<T>::
    LinkedList()
{
    head = nullptr;
}
template <typename T>

LinkedList<T>::~LinkedList()
{
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        Node<T> *next_node = temp->get_node();
        delete temp;
        temp = next_node;
    }
}
template <typename T>

LinkedList<T>::LinkedList(LinkedList &other)
{
    if (other.head == nullptr)
    {
        head = nullptr;
        return;
    }
    head = new Node<T>(other.head->data);
    Node<T> *current = head;
    Node<T> *other_current = other.head->next;

    while (other_current != nullptr)
    {
        current->next = new Node<T>(other_current->get_value());
        current = current->next;
        other_current = other_current->next;
    }
}
template <typename T>

void LinkedList<T>::insert_at_head(T value)
{
    Node<T> *new_node = new Node<T>(value, head);
    head = new_node;
}
template <typename T>

void LinkedList<T>::insert_at_tail(T value)
{
    Node<T> *new_node = new Node<T>(value, nullptr);
    if (head == nullptr)
    {
        head = new_node;
        return;
    }
    Node<T> *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}
template <typename T>

void LinkedList<T>::delete_at_head()

{
    if (head == nullptr)
    {
        cout << "List is empty. Cant delete!";
        return;
    }

    Node<T> *temp = head;
    head = head->next;
    delete temp;
}

template <typename T>

void LinkedList<T>::delete_at_tail()
{
    if (head == nullptr)
    {
        cout << "List is empty. Cant delete!";
        return;
    }

    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }
    Node<T> *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    Node<T> *delete_node = temp->next;
    temp->next = nullptr;
    delete delete_node;
}
template <typename T>

void LinkedList<T>::print_List()
{
    if (head == nullptr)
    {
        cout << "List is empty! ";
        return;
    }
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
template <typename T>

Node<T> *LinkedList<T>::get_node(int n)
{

    if (head == nullptr)
    {
        cout << "No nodes!";
        return nullptr;
    }
    int count = 0;
    Node<T> *temp = head;

    while (temp->next != nullptr && count < n)
    {
        temp = temp->next;
        count++;
    }

    return temp;
}
template <typename T>
bool LinkedList<T>::insert_after(T value, T key)
{
    if (head == nullptr)
    {
        cout << "List is empty. Cannot insert." << endl;
        return false;
    }

    Node<T> *temp = head;

    while (temp != nullptr)
    {
        if (temp->data == key)
        {
            Node<T> *new_node = new Node<T>(value, temp->next);
            temp->next = new_node;
            return true;
        }
        temp = temp->next;
    }

    return false;
}

template <typename T>
bool LinkedList<T>::insert_before(T value, T key)
{
    if (head == nullptr)
    {
        cout << "List is empty. Cannot insert." << endl;
        return false;
    }

    if (head->data == key)
    {
        insert_before_head(value);
        return true;
    }

    Node<T> *temp = head;
    Node<T> *prev = nullptr;

    while (temp != nullptr)
    {
        if (temp->data == key)
        {
            Node<T> *new_node = new Node<T>(value, temp);
            if (prev != nullptr)
            {
                prev->next = new_node;
            }
            return true;
        }
        prev = temp;
        temp = temp->next;
    }

    return false;
}

template <typename T>

bool LinkedList<T>::delete_before(T key)
{
    if (head == nullptr || head->next == nullptr)
    {
        cout << "List is too short to delete a node before the key." << endl;
        return false;
    }

    if (head->next->data == key)
    {
        delete_at_head();
        return true;
    }

    Node<T> *before_prev = nullptr;
    Node<T> *prev = head;
    Node<T> *current = head->next;

    while (current != nullptr)
    {
        if (current->data == key)
        {
            if (before_prev != nullptr)
            {
                before_prev->next = current;
            }
            delete prev;
            return true;
        }
        before_prev = prev;
        prev = current;
        current = current->next;
    }

    return false;
}

template <typename T>
bool LinkedList<T>::delete_after(T key)
{
    if (head == nullptr)
    {
        cout << "Can't delete; linked list is empty!" << endl;
        return false;
    }

    Node<T> *temp = head;

    while (temp != nullptr)
    {
        if (temp->data == key)
        {
            if (temp->next != nullptr)
            {
                Node<T> *deleted_node = temp->next;
                temp->next = deleted_node->next;
                delete deleted_node;
                return true;
            }
            else
            {
                cout << "No node exists after the key!" << endl;
                return false;
            }
        }
        temp = temp->next;
    }

    return false;
}

template <typename T>

int LinkedList<T>::length()
{
    int count = 0;
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        count++;
        temp = temp->get_node();
    }
    return count;
}
template <typename T>

Node<T> *LinkedList<T>::search(T value)
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
void LinkedList<T>::insert_before_head(T value)
{
    Node<T> *newNode = new Node<T>(value, head);
    head = newNode;
}

template <typename T>
void LinkedList<T>::insert_after_head(T value)
{
    if (head == nullptr)
    {
        head = new Node<T>(value, nullptr);
        return;
    }
    Node<T> *new_node = new Node<T>(value, head->next);
    head->next = new_node;
}

template <typename T>
void LinkedList<T>::insert_after_tail(T value)
{
    if (head == nullptr)
    {
        head = new Node<T>(value, nullptr);
        return;
    }
    Node<T> *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    Node<T> *new_node = new Node<T>(value, nullptr);
    temp->next = new_node;
}

template <typename T>
void LinkedList<T>::insert_before_tail(T value)
{
    if (head == nullptr)
    {
        cout << "List is empty. Can't insert before tail." << endl;
        return;
    }

    if (head->next == nullptr)
    {
        Node<T> *new_node = new Node<T>(value, head);
        head = new_node;
        return;
    }

    Node<T> *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    Node<T> *new_node = new Node<T>(value, temp->next);
    temp->next = new_node;
}
