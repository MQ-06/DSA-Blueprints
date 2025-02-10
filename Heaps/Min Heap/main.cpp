#include <iostream>
#include <limits>
#include "MinHeap.cpp"

using namespace std;

void menu()
{
    cout << "\n----------Min-Heap Operations Menu---------- \n";
    cout << "1. Insert an element\n";
    cout << "2. Delete the minimum element\n";
    cout << "3. Print heap \n";
    cout << "4. Get min element(root) \n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main()
{
    MinHeap<int> heap;
    int choice, value, min;

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
                cout << "Invalid choice! Please enter a number between 1 and 5: ";
            }
            else
            {
                break;
            }
        }

        switch (choice)
        {
        case 1:
        {
            cout << "Enter the value to insert: ";
            while (true)
            {
                cin >> value;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input! Please enter a valid integer: ";
                }
                else
                {
                    break;
                }
            }
            heap.insert(value);
            cout << "Inserted " << value << " into the heap.\n";
            break;
        }
        case 2:
        {
            try
            {
                heap.deleteMin();
                cout << "Deleted the minimum element.\n";
            }
            catch (const runtime_error &e)
            {
                cout << e.what() << endl;
            }
            break;
        }
        case 3:
        {
            cout << "Heap level by level:\n";
            heap.print_heap();
            break;
        }
        case 4:
            try
            {

                min = heap.getMin();
                cout << "Minimum element (The Root) is: " << min << endl;
            }
            catch (const exception &e)
            {
                cout << "Error: " << e.what() << endl;
            }
            break;

        case 5:
        {
            cout << "Exiting....\n";
            return 0;
        }
        default:
            cout << "Unexpected error occurred.\n";
        }
    }

    return 0;
}
