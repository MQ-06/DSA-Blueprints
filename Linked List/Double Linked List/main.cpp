#include <iostream>
#include "DoubleLinkedList.cpp"

using namespace std;

void menu()
{
    cout << "\nMenu: \n";
    cout << "1.  Insert at Head\n";
    cout << "2.  Insert at Tail\n";
    cout << "3.  Insert After a Key\n";
    cout << "4.  Insert Before a Key\n";
    cout << "5.  Delete at Head\n";
    cout << "6.  Delete at Tail\n";
    cout << "7.  Delete After a Key\n";
    cout << "8.  Delete Before a Key\n";
    cout << "9.  Get Node by Position\n";
    cout << "10. Print List\n";
    cout << "11. Length of List\n";
    cout << "12. Search for a Key\n";
    cout << "0.  Exit\n";
}

int main()
{
    DoubleLinkedList<int> list;
    Node<int> *node;
    int choice, value, key, position;

    do
    {
        menu();
        while (true)
        {
            cout << "Enter your choice: ";
            cin >> choice;

            if (cin.fail() || choice < 0 || choice > 12)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter Again (0-12)." << endl;
            }
            else
            {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
        }

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert at head: ";
            cin >> value;
            list.insert_at_head(value);
            cout << "Value at head inserted successfully!" << endl;
            break;

        case 2:
            cout << "Enter value to insert at tail: ";
            cin >> value;
            list.insert_at_tail(value);
            cout << "Value at tail inserted successfully!" << endl;

            break;

        case 3:
            cout << "Enter value to insert and key after which to insert: ";
            cin >> value >> key;
            if (!list.insert_after(value, key))
            {
                cout << "Key not found!" << endl;
            }
            break;

        case 4:
            cout << "Enter value to insert and key before which to insert: ";
            cin >> value >> key;
            if (!list.insert_before(value, key))
            {
                cout << "Key not found!" << endl;
            }
            break;

        case 5:
            if (list.delete_at_head())
            {
                cout << "Deleted node at head." << endl;
            }
            else
            {
                cout << "List is empty!" << endl;
            }
            break;

        case 6:
            if (list.delete_at_tail())
            {
                cout << "Deleted node at tail." << endl;
            }
            else
            {
                cout << "List is empty!" << endl;
            }
            break;

        case 7:
            cout << "Enter key to delete after: ";
            cin >> key;
            if (!list.delete_after(key))
            {
                cout << "Key not found or no node after it!" << endl;
            }
            else
            {
                cout << "Node deleted successfully!" << endl;
            }
            break;

        case 8:
            cout << "Enter key to delete before: ";
            cin >> key;
            if (!list.delete_before(key))
            {
                cout << "Key not found or no node before it!" << endl;
            }
            else
            {
                cout << "Node deleted successfully!" << endl;
            }
            break;

        case 9:
            cout << "Enter position to get node: ";
            cin >> position;
            node = list.get_node(position);
            if (node)
            {
                if (node == list.tail)
                {
                    cout << "position exceeded list length so returning last node: " << endl;
                    cout << "Node at last position " << position << ": " << node->data << endl;
                }
                else
                {
                    cout << "Node at position " << position << ": " << node->data << endl;
                }
            }
            else
            {
                cout << "Invalid position!" << endl;
            }
            break;

        case 10:
            cout << "List: ";
            list.print_List();
            break;

        case 11:
            cout << "Length of list: " << list.length() << endl;
            break;

        case 12:
            cout << "Enter key to search: ";
            cin >> key;
            node = list.search(key);
            if (node)
            {
                cout << "Found node with value: " << node->data << endl;
            }
            else
            {
                cout << "Key not found!" << endl;
            }
            break;

        case 0:
            cout << "Exiting program :)" << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
