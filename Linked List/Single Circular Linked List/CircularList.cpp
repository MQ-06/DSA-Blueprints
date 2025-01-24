#include "CircularList.h"
using namespace std;

template <typename T>
CircularLL<T>::CircularLL()
{
    head = nullptr;
}

template <typename T>
CircularLL<T>::~CircularLL()
{
    if (head == nullptr)
    {
        return;
    }
    Node<T> *current = head;
    Node<T> *nextNode;
    do
    {
        nextNode = current->next;
        delete current;
        current = nextNode;
    } while (current != head);
    head = nullptr;
}

template <typename T>
CircularLL<T>::CircularLL(CircularLL &node)
{
    head = nullptr;
    Node<T> *temp = node.head;
    if (temp == nullptr)
    {
        return;
    }
    do
    {
        insert_at_tail(temp->data);
        temp = temp->next;
    } while (temp != node.head);
}

template <typename T>
void CircularLL<T>::insert_at_head(T value)
{
    Node<T> *newNode = new Node<T>(value);
    if (head == nullptr)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        Node<T> *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
}

template <typename T>
void CircularLL<T>::insert_at_tail(T value)
{
    Node<T> *newNode = new Node<T>(value);
    if (head == nullptr)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        Node<T> *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

template <typename T>
void CircularLL<T>::insert_before_head(T value)
{
    insert_at_tail(value);
}

template <typename T>
void CircularLL<T>::insert_after_head(T value)
{
    if (head == nullptr)
    {
        insert_at_head(value);
        return;
    }
    Node<T> *newNode = new Node<T>(value);
    newNode->next = head->next;
    head->next = newNode;
}

template <typename T>
void CircularLL<T>::insert_after_tail(T value)
{
    insert_at_tail(value);
}

template <typename T>
void CircularLL<T>::insert_before_tail(T value)
{
    if (head == nullptr || head->next == head)
    {
        insert_at_head(value);
        return;
    }
    Node<T> *temp = head;
    while (temp->next->next != head)
    {
        temp = temp->next;
    }
    Node<T> *newNode = new Node<T>(value);
    newNode->next = temp->next;
    temp->next = newNode;
}

template <typename T>
void CircularLL<T>::delete_at_head()
{
    if (head == nullptr)
    {
        return;
    }

    Node<T> *temp = head;
    if (head->next == head)
    {
        head = nullptr;
    }
    else
    {
        Node<T> *last = head;
        while (last->next != head)
        {
            last = last->next;
        }
        last->next = head->next;
        head = head->next;
    }
    delete temp;
}

template <typename T>
void CircularLL<T>::delete_at_tail()
{
    if (head == nullptr)
    {
        return;
    }

    Node<T> *temp = head;
    if (head->next == head)
    {
        head = nullptr;
        delete temp;
        return;
    }

    while (temp->next->next != head)
    {
        temp = temp->next;
    }
    Node<T> *deletedNode = temp->next;
    temp->next = head;
    delete deletedNode;
}

template <typename T>
Node<T> *CircularLL<T>::get_node(int n)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    int count = 0;
    Node<T> *temp = head;

    do
    {
        if (count == n)
        {
            return temp;
        }
        temp = temp->next;
        count++;
    } while (temp != head);

    return nullptr;
}

template <typename T>
bool CircularLL<T>::insert_after(T value, T key)
{
    if (head == nullptr)
    {
        cout << "No node to insert after." << endl;
        return false;
    }

    Node<T> *temp = head;
    do
    {
        if (temp->data == key)
        {
            Node<T> *newNode = new Node<T>(value);
            newNode->next = temp->next;
            temp->next = newNode;
            return true;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Key not found in the list." << endl;
    return false;
}

template <typename T>
bool CircularLL<T>::insert_before(T value, T key)
{
    if (head == nullptr)
    {
        cout << "No node to insert before." << endl;
        return false;
    }

    Node<T> *temp = head;
    if (head->data == key)
    {
        insert_at_head(value);
        return true;
    }

    Node<T> *prev = nullptr;
    do
    {
        if (temp->data == key)
        {
            Node<T> *newNode = new Node<T>(value);
            newNode->next = temp;
            prev->next = newNode;
            return true;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != head);

    cout << "Key not found in the list." << endl;
    return false;
}

template <typename T>
bool CircularLL<T>::delete_before(T key)
{
    if (head == nullptr || head->next == head)
    {
        cout << "Cannot delete before; list is too small." << endl;
        return false;
    }

    Node<T> *current = head;
    Node<T> *prev = nullptr;
    Node<T> *beforePrev = nullptr;

    do
    {
        beforePrev = prev;
        prev = current;
        current = current->next;
        if (current->data == key)
        {
            if (beforePrev == nullptr)
            {
                beforePrev = head;
                while (beforePrev->next != head)
                {
                    beforePrev = beforePrev->next;
                }
            }

            beforePrev->next = prev->next;
            if (prev == head)
            {
                head = prev->next;
            }
            delete prev;
            return true;
        }
    } while (current != head);

    cout << "Key not found in the list." << endl;
    return false;
}

template <typename T>
bool CircularLL<T>::delete_after(T key)
{
    if (head == nullptr || head->next == head)
    {
        cout << "Cannot delete after; list is too small." << endl;
        return false;
    }

    Node<T> *current = head;
    do
    {
        if (current->data == key)
        {
            Node<T> *toDelete = current->next;
            current->next = toDelete->next;
            if (toDelete == head)
            {
                head = toDelete->next;
            }
            delete toDelete;
            return true;
        }
        current = current->next;
    } while (current != head);

    cout << "Key not found in the list." << endl;
    return false;
}

template <typename T>
Node<T> *CircularLL<T>::search(T value)
{
    if (head == nullptr)
    {
        return nullptr;
    }
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
void CircularLL<T>::print_List()
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node<T> *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << head->data << endl;

    cout << endl;
}

template <typename T>
int CircularLL<T>::length()
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
