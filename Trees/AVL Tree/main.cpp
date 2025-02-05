#include <iostream>
#include <limits>
#include "AVL.h"
using namespace std;

void menu()
{
    cout << "\nAVL Tree Operations Menu:\n";
    cout << "1. Insert a value\n";
    cout << "2. Delete a value\n";
    cout << "3. Search a value\n";
    cout << "4. Level-Order Traversal\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main()
{
    AVL<int> tree;
    int choice, value;

    while (true)
    {
        menu();

        while (true)
        {
            cin >> choice;
            if (cin.fail() || choice < 1 || choice > 5)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid choice. Please enter a number between 1 and 5: ";
            }
            else
            {
                break;
            }
        }

        if (choice == 1)
        {
            cout << "Enter value to insert: ";
            cin >> value;
            tree.insert(value);
            cout << "Value inserted successfully!\n";
        }
        else if (choice == 2)
        {
            cout << "Enter value to delete: ";
            cin >> value;
            if (tree.search_value(tree.root, value))
            {
                tree.root = tree.delete_node(tree.root, value);
                cout << "Value deleted successfully!\n";
            }
            else
            {
                cout << "Value not found in the tree.\n";
            }
        }
        else if (choice == 3)
        {
            cout << "Enter value to search: ";
            cin >> value;
            if (tree.search_value(tree.root, value))
            {
                cout << "Value found in the tree.\n";
            }
            else
            {
                cout << "Value not found in the tree.\n";
            }
        }
        else if (choice == 4)
        {
            cout << "Level-Order Traversal of the AVL Tree: \n";
            tree.LevelOrder();
        }
        else if (choice == 5)
        {
            cout << "Exiting program......\n";
            return 0;
        }
    }

    return 0;
}
