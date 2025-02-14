#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include <limits>
#include <algorithm>
#include <queue>
using namespace std;

void menu()
{
    cout << endl;
    cout << "Menu:\n";
    cout << "1.Insert a node\n";
    cout << "2.Delete a node\n";
    cout << "3.Search a node\n";
    cout << "4.Find Min\n";
    cout << "5.Inorder Traversal\n";
    cout << "6.PreOrder Traversal\n";
    cout << "7.PostOrder Traversal\n";
    cout << "8.Level Order\n";
    cout << "9.Equal trees\n";
    cout << "10.Exit\n";
    cout << "Enter your choice: ";
}

template <typename T>
class Node
{
public:
    T data;
    Node<T> *left;
    Node<T> *right;
    Node(T data) : data(data), left(nullptr), right(nullptr) {}
    Node(T data, Node<T> *lchild, Node<T> *rchild) : data(data), left(lchild), right(rchild) {}
    Node(Node<T> *other)
    {
        *this = other;
    }
};

template <typename T>
class Tree
{
public:
    Node<T> *root;

    Tree() : root(nullptr) {}

    void insert(T value)

    {
        root = insert(root, value);
    }

    Node<T> *insert(Node<T> *node, T value)
    {

        if (node == nullptr)
        {
            return new Node<T>(value);
        }
        if (value < node->data)
        {

            node->left = insert(node->left, value);
        }
        else
        {

            node->right = insert(node->right, value);
        }
        return node;
    }

    Node<T> *delete_node(Node<T> *root, T value)
    {

        if (root == nullptr)
        {
            return nullptr;
        }

        if (root->data == value)
        {
            if (root->left == nullptr && root->right == nullptr)
            {
                delete root;
                return nullptr;
            }
            else if (root->left == nullptr && root->right != nullptr)
            {
                Node<T> *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->left != nullptr && root->right == nullptr)
            {

                Node<T> *temp = root->left;
                delete root;
                return temp;
            }
            else if (root->left != nullptr && root->right == nullptr)
            {
                Node<T> *temp = find_min();
                root->data = temp->data;
                root->right = delete_node(root->right, temp->data);
            }
        }
        else if (value < root->data)
        {
            root->left = delete_node(root->left, value);
        }
        else
        {
            root->right = delete_node(root->right, value);
        }

        return root;
    }
    bool search_node(Node<T> *root, T value)
    {

        if (root == nullptr)
        {
            return false;
        }

        if (root->data == value)
        {
            return true;
        }
        if (value < root->data)
        {
            search_node(root->left, value);
        }
        else
        {
            search_node(root->right, value);
        }
        return false;
    }
    bool search_node(T value)
    {

        Node<T> *temp = root;
        while (temp != nullptr)
        {
            if (temp->data == value)
            {
                return true;
            }
            if (root->data > value)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        return false;
    }
    
    Node<T> *find_min()
    {

        Node<T> *temp = root;
        while (temp->left != nullptr && temp)
        {
            temp = temp->left;
        }
        return temp;
    }
    void inorder(Node<T> *node)
    {
        if (node != nullptr)
        {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }
    void postorder(Node<T> *node)
    {
        if (node != nullptr)
        {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }
    void preorder(Node<T> *node)
    {
        if (node != nullptr)
        {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }
    void BFS()
    {

        if (root == nullptr)
            return;

        queue<Node<T> *> q;
        cout << root->data << " ";
        q.push(root);

        while (!q.empty())
        {
            Node<T> *temp = q.front();
            q.pop();
            if (temp->left)
            {
                cout << temp->left->data << " ";
                q.push(temp->left);
            }
            if (temp->right)
            {
                cout << temp->right->data << " ";
                q.push(temp->right);
            }
        }
    }
    bool isEqual(Node<T> *node1, Node<T> *node2)
    {
        if (node1 == nullptr && node2 == nullptr)
        {
            return true;
        }
        if (node1 == nullptr || node2 == nullptr)
        {
            return false;
        }
        return (node1->data == node2->data) && isEqual(node1->left, node2->right) && isEqual(node1->right, node2->left);
    }
};

int main()
{

    Tree<int> tree;
    int choice;

    do
    {
        menu();
        cin >> choice;
        if (cin.fail() || choice <= 0 || choice > 10)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice\n";
        }
        else
        {

            if (choice == 1)
            {
                int value;
                cout << "Enter value to insert:";
                cin >> value;
                tree.insert(value);
                cout << "Value inserted successfully!" << endl;
            }
            else if (choice == 2)
            {
                cout << "Enter node value u want to delete:\n";
                int val;
                cin >> val;

                if (tree.search_node(val))
                {

                    Node<int> *result = tree.delete_node(tree.root, val);
                    cout << "node deleted successfully!" << endl;
                }
                else
                {
                    cout << "Node not found!" << endl;
                }
            }
            else if (choice == 3)
            {
                int val;
                cout << "Enter value to search in BST" << endl;
                cin >> val;

                if (tree.search_node(val))
                {
                    cout << "key found " << endl;
                }
                else
                {
                    cout << "key not found" << endl;
                }
            }
            else if (choice == 4)
            {
                Node<int> *node = tree.find_min();
                cout << "Minimum node value is:" << node->data << endl;
            }
            else if (choice == 5)
            {
                cout << "Inorder Traversal:\n";
                tree.inorder(tree.root);
            }
            else if (choice == 6)
            {
                cout << "Pre Order Traversal:\n";
                tree.preorder(tree.root);
            }
            else if (choice == 7)
            {
                cout << "Post Order traversal:\n";
                tree.postorder(tree.root);
            }
            else if (choice == 8)
            {
                cout << "Level order" << endl;
                tree.BFS();
            }
            else if (choice == 9)
            {

                Tree<int> tree2;
                tree2.insert(1);
                tree2.insert(6);
                tree2.insert(0);
                tree2.insert(60);
                tree2.insert(11);
                tree2.insert(8);
                if (tree.isEqual(tree.root, tree2.root))
                {
                    cout << "both trees are equal\n";
                }
                else
                {
                    cout << "both trees are not equal\n";
                }
            }
            else if (choice == 10)
            {

                cout << "Exiting......";
                break;
            }
            else
            {
                cout << "Invalid option" << endl;
            }
        }
    } while (true);
}
