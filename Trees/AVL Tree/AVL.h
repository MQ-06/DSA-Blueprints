#include <iostream>
#include <queue>
#include "Node.h"
using namespace std;

template <typename T>
class AVL
{
private:
    Node<T> *rotaterchild(Node<T> *oldRoot)
    {
        Node<T> *newRoot = oldRoot->lchild;
        Node<T> *subtree = newRoot->rchild;

        newRoot->rchild = oldRoot;
        oldRoot->lchild = subtree;

        oldRoot->height = max(getHeight(oldRoot->lchild), getHeight(oldRoot->rchild)) + 1;
        newRoot->height = max(getHeight(newRoot->lchild), getHeight(newRoot->rchild)) + 1;

        return newRoot;
    }

    Node<T> *rotatelchild(Node<T> *oldRoot)
    {
        Node<T> *newRoot = oldRoot->rchild;
        Node<T> *subtree = newRoot->lchild;

        newRoot->lchild = oldRoot;
        oldRoot->rchild = subtree;

        oldRoot->height = max(getHeight(oldRoot->lchild), getHeight(oldRoot->rchild)) + 1;
        newRoot->height = max(getHeight(newRoot->lchild), getHeight(newRoot->rchild)) + 1;

        return newRoot;
    }

public:
    Node<T> *root;

    AVL() : root(nullptr) {}

    int getHeight(Node<T> *node)
    {
        return node ? node->height : 0;
    }

    int getBF(Node<T> *node)
    {
        return node ? getHeight(node->lchild) - getHeight(node->rchild) : 0;
    }

    Node<T> *getMinimum(Node<T> *node)
    {
        Node<T> *current = node;
        while (current && current->lchild != nullptr)
        {
            current = current->lchild;
        }
        return current;
    }

    void insert(T value)
    {
        root = insert(root, value);
    }

    Node<T> *insert(Node<T> *node, T value)
    {
        if (!node)
        {
            return new Node<T>(value);
        }

        if (value < node->data)
        {
            node->lchild = insert(node->lchild, value);
        }
        else if (value > node->data)
        {
            node->rchild = insert(node->rchild, value);
        }
        else
        {
            return node;
        }

        node->height = 1 + max(getHeight(node->lchild), getHeight(node->rchild));

        int balance = getBF(node);

        // left-left imbalance
        if (balance > 1 && value < node->lchild->data)
        {
            return rotaterchild(node);
        }

        // right right imbalance
        if (balance < -1 && value > node->rchild->data)
        {
            return rotatelchild(node);
        }

        if (balance > 1 && value > node->lchild->data)
        {
            node->lchild = rotatelchild(node->lchild);
            return rotaterchild(node);
        }

        if (balance < -1 && value < node->rchild->data)
        {
            node->rchild = rotaterchild(node->rchild);
            return rotatelchild(node);
        }

        return node;
    }

    Node<T> *delete_node(Node<T> *node, T value)
    {
        if (!node)
        {
            return nullptr;
        }

        if (value < node->data)
        {
            node->lchild = delete_node(node->lchild, value);
        }
        else if (value > node->data)
        {
            node->rchild = delete_node(node->rchild, value);
        }
        else
        {
            if (!node->lchild && !node->rchild)
            {
                delete node;
                return nullptr;
            }
            else if (!node->lchild)
            {
                Node<T> *temp = node->rchild;
                delete node;
                return temp;
            }
            else if (!node->rchild)
            {
                Node<T> *temp = node->lchild;
                delete node;
                return temp;
            }
            else
            {
                Node<T> *temp = getMinimum(node->rchild);
                node->data = temp->data;
                node->rchild = delete_node(node->rchild, temp->data);
            }
        }

        node->height = 1 + max(getHeight(node->lchild), getHeight(node->rchild));

        int balance = getBF(node);

        if (balance > 1 && getBF(node->lchild) >= 0)
        {
            return rotaterchild(node);
        }

        if (balance > 1 && getBF(node->lchild) < 0)
        {
            node->lchild = rotatelchild(node->lchild);
            return rotaterchild(node);
        }

        if (balance < -1 && getBF(node->rchild) <= 0)
        {
            return rotatelchild(node);
        }

        if (balance < -1 && getBF(node->rchild) > 0)
        {
            node->rchild = rotaterchild(node->rchild);
            return rotatelchild(node);
        }

        return node;
    }

    bool search_value(Node<T> *node, T value)
    {
        if (!node)
            return false;
        if (node->data == value)
            return true;
        if (value < node->data)
        {
            return search_value(node->lchild, value);
        }
        else
        {
            return search_value(node->rchild, value);
        }
    }

    void LevelOrder()
    {
        if (!root)
            return;
        queue<Node<T> *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                Node<T> *current = q.front();
                q.pop();
                cout << current->data << " ";
                if (current->lchild)
                    q.push(current->lchild);
                if (current->rchild)
                    q.push(current->rchild);
            }
            cout << endl;
        }
    }

    void insert_root(T value)
    {
        root = insert(root, value);
    }

    void delete_root(T value)
    {
        root = delete_node(root, value);
    }

    ~AVL()
    {
        deleteTree(root);
        root = nullptr;
    }

    AVL(const AVL &other) : root(nullptr)
    {
        if (other.root)
        {
            root = copyTree(other.root);
        }
    }

    void deleteTree(Node<T> *node)
    {
        if (!node)
            return;
        deleteTree(node->lchild);
        deleteTree(node->rchild);
        delete node;
    }

    Node<T> *copyTree(Node<T> *node)
    {
        if (!node)
            return nullptr;
        Node<T> *newNode = new Node<T>(node->value);
        newNode->lchild = copyTree(node->lchild);
        newNode->rchild = copyTree(node->rchild);
        newNode->height = node->height;
        return newNode;
    }
};
