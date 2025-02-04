#include <iostream>
#include <limits>
#include "Tree.cpp"

using namespace std;

void menu()
{
    cout << "\n----------Menu---------: \n";
    cout << "1. Set Left Child\n";
    cout << "2. Set Right Child\n";
    cout << "3. Get Parent\n";
    cout << "4. Delete Left Child\n";
    cout << "5. Delete Right Child\n";
    cout << "6. Set Root\n";
    cout << "7. Display Tree\n";
    cout << "8. Exit\n";
    cout << "Enter your choice: ";
}

int validateInput(const string &prompt)
{
    int input;
    while (true)
    {
        cout << prompt;
        cin >> input;

        if (cin.fail())
        {
            cout << "Invalid input. Please enter a valid integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            return input;
        }
    }
}

int menu_validation()
{
    int choice;
    while (true)
    {
        menu();
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 8)
        {
            cout << "Invalid choice. Please select a valid option (1-8).\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            return choice;
        }
    }
}

int main()
{
    int size;
    cout << "Enter the initial size of the tree: ";
    while (true)
    {
        cin >> size;
        if (cin.fail() || size <= 0)
        {
            cout << "Invalid choice. Enter a valid size\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            break;
        }
    }

    Tree<int> tree(size);

    int choice, index;
    int value;

    do
    {
        choice = menu_validation();

        switch (choice)
        {
        case 1:
            index = validateInput("Enter index for left child: ");
            value = validateInput("Enter value for left child: ");
            try
            {
                tree.setLeftChild(index, value);
                cout << "Left child set successfully.\n";
            }
            catch (const exception &e)
            {
                cout << "Error: " << e.what() << endl;
            }
            break;

        case 2:
            index = validateInput("Enter index for right child: ");
            value = validateInput("Enter value for right child: ");
            try
            {
                tree.setRightChild(index, value);
                cout << "Right child set successfully.\n";
            }
            catch (const exception &e)
            {
                cout << "Error: " << e.what() << endl;
            }
            break;

        case 3:
            index = validateInput("Enter index to get parent: ");
            try
            {
                int parent = tree.getParent(index);
                cout << "Parent node value: " << parent << endl;
            }
            catch (const exception &e)
            {
                cout << "Error: " << e.what() << endl;
            }
            break;

        case 4:
            index = validateInput("Enter index to delete left child: ");
            try
            {
                tree.deleteLeftChild(index);
                cout << "Left child deleted successfully.\n";
            }
            catch (const exception &e)
            {
                cout << "Error: " << e.what() << endl;
            }
            break;

        case 5:
            index = validateInput("Enter index to delete right child: ");
            try
            {
                tree.deleteRightChild(index);
                cout << "Right child deleted successfully.\n";
            }
            catch (const exception &e)
            {
                cout << "Error: " << e.what() << endl;
            }
            break;

        case 6:
            value = validateInput("Enter value to set root: ");
            tree.setRoot(value);
            cout << "Root set to " << value << ".\n";
            break;

        case 7:
            cout << "Displaying Tree...\n";
            tree.displayTree();
            break;

        case 8:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}
