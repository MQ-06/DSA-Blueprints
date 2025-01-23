#include <iostream>
#include "LinkedList.cpp"
using namespace std;

void menu()
{
    cout << "\n--- Linked List Operations Menu ---\n";

    cout << "1. Insert at Head\n";
    cout << "2. Insert at Tail\n";
    cout << "3. Insert After a Key\n";
    cout << "4. Insert Before a Key\n";
    cout << "5. Delete at Head\n";
    cout << "6. Delete at Tail\n";
    cout << "7. Delete After a Key\n";
    cout << "8. Delete Before a Key\n";
    cout << "9. Print List\n";
    cout << "10. Get Length of List\n";
    cout << "11. Search for a Value\n";
    cout << "12. Exit\n";
    cout << "Enter your choice (1-12): ";
}

int main()
{
    LinkedList<int> list;
    int choice = 0;
    int value, key;
    Node<int> *result = nullptr;

    do
    {
        menu();

        while (true)
        {
            cin >> choice;

            if (cin.fail() || choice < 1 || choice > 12)
            {
                cout << "Invalid choice! Please enter a number between 1 and 12: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
            cout << "Value inserted at head successfully!" << endl;

            break;
        case 2:
            cout << "Enter value to insert at tail: ";
            cin >> value;
            list.insert_at_tail(value);
            cout << "Value inserted at tail successfully!" << endl;

            break;
        case 3:
            cout << "Enter value to insert: ";
            cin >> value;
            cout << "Enter key after which to insert: ";
            cin >> key;
            if (!list.insert_after(value, key))
            {
                cout << "Key not found or list is empty.\n";
            }
            break;
        case 4:
            cout << "Enter value to insert: ";
            cin >> value;
            cout << "Enter key before which to insert: ";
            cin >> key;
            if (!list.insert_before(value, key))
            {
                cout << "Key not found or list is empty.\n";
            }
            break;
        case 5:
            list.delete_at_head();
            break;
        case 6:
            list.delete_at_tail();
            break;
        case 7:
            cout << "Enter key after which to delete: ";
            cin >> key;
            if (!list.delete_after(key))
            {
                cout << "Key not found or no node exists after the key.\n";
            }
            break;
        case 8:
            cout << "Enter key before which to delete: ";
            cin >> key;
            if (!list.delete_before(key))
            {
                cout << "Key not found or list is too short.\n";
            }
            break;
        case 9:
            cout << "List contents: ";
            list.print_List();
            cout << endl;
            break;
        case 10:
            cout << "Length of list: " << list.length() << endl;
            break;
        case 11:
            cout << "Enter value to search for: ";
            cin >> value;
            result = list.search(value);
            if (result)
            {
                cout << "Value " << value << " found in the list.\n";
            }
            else
            {
                cout << "Value " << value << " not found in the list.\n";
            }
            break;
        case 12:
            cout << "Exiting...\n";
            break;
        default:
            break;
        }
    } while (choice != 12);

    return 0;
}
