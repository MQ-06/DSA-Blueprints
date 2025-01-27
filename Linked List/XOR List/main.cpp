#include "XORList.cpp"
#include <iostream>
#include <limits>
using namespace std;

void menu()
{
    cout << "\n ....Menu.....\n";
    cout << "1. Insert at Head\n";
    cout << "2. Insert at Tail\n";
    cout << "3. Delete from Head\n";
    cout << "4. Delete from Tail\n";
    cout << "5. Print List\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}
int main()
{
    XORList<int> list;
    int choice, value;

    while (true)
    {

        menu();
        cin >> choice;
        while (cin.fail() || choice < 1 || choice > 6)
        {
            cout << "Invalid input! Enter a number between 1 and 6: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> choice;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1)
        {
            cout << "Enter value to insert at head: ";
            cin >> value;
            while (cin.fail())
            {
                cout << "Invalid input. Please enter a valid integer: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> value;
            }
            list.insertAtHead(value);
            cout << "Value inserted at head.\n";
        }
        else if (choice == 2)
        {
            cout << "Enter value to insert at tail: ";
            cin >> value;
            while (cin.fail())
            {
                cout << "Invalid input. Please enter a valid integer: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> value;
            }
            list.insertAtTail(value);
            cout << "Value inserted at tail.\n";
        }
        else if (choice == 3)
        {
            if (list.head != nullptr)
            {
                list.deleteAtHead();
                cout << "Deleted from head.\n";
            }
            else
            {
                cout << "List is empty.\n";
            }
        }
        else if (choice == 4)
        {
            if (list.tail != nullptr)
            {
                list.deleteAtTail();
                cout << "Deleted from tail.\n";
            }
            else
            {
                cout << "List is empty.\n";
            }
        }
        else if (choice == 5)
        {
            list.printList();
        }
        else if (choice == 6)
        {
            cout << "Exiting....\n";
            break;
        }
    }

    return 0;
}
