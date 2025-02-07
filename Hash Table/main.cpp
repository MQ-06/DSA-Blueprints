#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <limits>
#include "hash.h"
using namespace std;

void menu()
{
    cout << "\n Hash Table Operations:\n";
    cout << "1. Insert a string\n";
    cout << "2. Search for a string\n";
    cout << "3. Remove a string\n";
    cout << "4. Display hash table\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main()
{
    int size;

    while (true)
    {
        cout << "Enter the size of the hash table: ";
        cin >> size;

        if (cin.fail() || size <= 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid size. Please enter a positive integer.\n";
        }
        else
        {
            break;
        }
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    HashMap hashTable(size);

    while (true)
    {
        menu();
        int choice;
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 5)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice. Please enter a number between 1 and 5.\n";
            continue;
        }

        string str;
        switch (choice)
        {
        case 1:
            cout << "Enter a string to insert: ";
            cin.ignore();
            getline(cin, str);
            hashTable.insert(str);
            break;
        case 2:
            cout << "Enter a string to search: ";
            cin.ignore();
            getline(cin, str);
            hashTable.search(str);
            break;
        case 3:
            cout << "Enter a string to remove: ";
            cin.ignore();
            getline(cin, str);
            hashTable.remove(str);
            break;
        case 4:
            hashTable.display();
            break;
        case 5:
            cout << "Exiting program.......\n";
            return 0;
        }
    }
}
