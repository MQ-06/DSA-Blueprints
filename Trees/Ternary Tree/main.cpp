#include <iostream>
using namespace std;

struct TTNode
{
    int data;
    TTNode *left;
    TTNode *middle;
    TTNode *right;

    TTNode(int val) : data(val), left(nullptr), middle(nullptr), right(nullptr) {}
};

class TernaryTree
{
public:
    TernaryTree() : root(nullptr) {}

    void insert(int value)
    {
        root = insertRecursive(root, value);
    }

    bool search(int value)
    {
        return searchRecursive(root, value);
    }

    void remove(int value)
    {
        root = removeRecursive(root, value);
    }

    void inOrderTraversal() const
    {
        inOrderTraversalRecursive(root);
        cout << endl;
    }

    void preOrderTraversal() const
    {
        preOrderTraversalRecursive(root);
        cout << endl;
    }

    void postOrderTraversal() const
    {
        postOrderTraversalRecursive(root);
        cout << endl;
    }

    ~TernaryTree()
    {
        deleteTree(root);
    }

private:
    TTNode *root;

    TTNode *insertRecursive(TTNode *node, int value)
    {
        if (!node)
        {
            return new TTNode(value);
        }

        if (value < node->data)
        {
            node->left = insertRecursive(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = insertRecursive(node->right, value);
        }
        else
        {
            node->middle = insertRecursive(node->middle, value);
        }

        return node;
    }

    bool searchRecursive(TTNode *node, int value)
    {
        if (!node)
            return false;

        if (value < node->data)
        {
            return searchRecursive(node->left, value);
        }
        else if (value > node->data)
        {
            return searchRecursive(node->right, value);
        }
        else
        {
            return true;
        }
    }

    TTNode *findMin(TTNode *node)
    {
        while (node && node->left)
        {
            node = node->left;
        }
        return node;
    }

    TTNode *removeRecursive(TTNode *node, int value)
    {
        if (!node)
            return nullptr;

        if (value < node->data)
        {
            node->left = removeRecursive(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = removeRecursive(node->right, value);
        }
        else
        {
            if (node->middle)
            {
                node->middle = removeRecursive(node->middle, value);
            }
            else if (node->right)
            {
                TTNode *temp = findMin(node->right);
                node->data = temp->data;
                node->right = removeRecursive(node->right, temp->data);
            }
            else
            {
                TTNode *temp = node->left;
                delete node;
                return temp;
            }
        }

        return node;
    }

    void inOrderTraversalRecursive(TTNode *node) const
    {
        if (!node)
            return;
        inOrderTraversalRecursive(node->left);
        cout << node->data << " ";
        inOrderTraversalRecursive(node->middle);
        inOrderTraversalRecursive(node->right);
    }

    void preOrderTraversalRecursive(TTNode *node) const
    {
        if (!node)
            return;
        cout << node->data << " ";
        preOrderTraversalRecursive(node->left);
        preOrderTraversalRecursive(node->middle);
        preOrderTraversalRecursive(node->right);
    }

    void postOrderTraversalRecursive(TTNode *node) const
    {
        if (!node)
            return;
        postOrderTraversalRecursive(node->left);
        postOrderTraversalRecursive(node->middle);
        postOrderTraversalRecursive(node->right);
        cout << node->data << " ";
    }

    void deleteTree(TTNode *node)
    {
        if (!node)
            return;
        deleteTree(node->left);
        deleteTree(node->middle);
        deleteTree(node->right);
        delete node;
    }
};

int main()
{
    TernaryTree tree;

    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(5);
    tree.insert(2);
    tree.insert(6);

    cout << "In-order traversal: ";
    tree.inOrderTraversal();

    cout << "Pre-order traversal: ";
    tree.preOrderTraversal();

    cout << "Post-order traversal: ";
    tree.postOrderTraversal();

    cout << "Search for 5: " << (tree.search(5) ? "Found" : "Not Found") << endl;
    cout << "Search for 4: " << (tree.search(4) ? "Found" : "Not Found") << endl;

    tree.remove(5);
    cout << "After removing 5, In-order traversal: ";
    tree.inOrderTraversal();

    return 0;
}