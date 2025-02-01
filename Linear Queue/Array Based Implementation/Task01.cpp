#include <iostream>
#include <limits>
#include "Queue.cpp"
using namespace std;

void menu()
{
    cout << "\n--- Linear Queue Menu ---" << endl;

    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Display Queue" << endl;
    cout << "4. Check if Empty" << endl;
    cout << "5. Check if Full" << endl;
    cout << "6. Get Front Element" << endl;
    cout << "7. Get Back Element" << endl;
    cout << "8. Exit" << endl;
}

int main()
{
    Queue<int> queue;
    int choice;
    int element;

    while (true)
    {
        menu();
        cout << "Enter your choice: ";
        cin >> choice;

        while (cin.fail() || choice < 1 || choice > 8)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice. Please enter a number between 1 and 8: ";
            cin >> choice;
        }

        switch (choice)
        {
        case 1:
            cout << "Enter an integer to enqueue: ";
            cin >> element;

            while (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a valid integer: ";
                cin >> element;
            }
            queue.enqueue(element);
            cout << element << " enqueued successfully." << endl;
            break;

        case 2:
            try
            {
                element = queue.dequeue();
                cout << element << " dequeued successfully." << endl;
            }
            catch (const underflow_error &e)
            {
                cout << e.what() << endl;
            }
            break;

        case 3:
            queue.display();
            break;

        case 4:
            if (queue.isEmpty())
            {
                cout << "Queue is empty." << endl;
            }
            else
            {
                cout << "Queue is not empty." << endl;
            }
            break;

        case 5:
            if (queue.isFull())
            {
                cout << "Queue is full." << endl;
            }
            else
            {
                cout << "Queue is not full." << endl;
            }
            break;

        case 6:
            try
            {
                element = queue.getFront();
                cout << "Front element: " << element << endl;
            }
            catch (const underflow_error &e)
            {
                cout << e.what() << endl;
            }
            break;

        case 7:
            try
            {
                element = queue.getBack();
                cout << "Back element: " << element << endl;
            }
            catch (const underflow_error &e)
            {
                cout << e.what() << endl;
            }
            break;

        case 8:
            cout << "Exiting program........" << endl;
            return 0;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}
