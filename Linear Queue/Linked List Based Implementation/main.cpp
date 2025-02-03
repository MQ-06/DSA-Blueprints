#include <iostream>
#include "Queue.cpp"
#include <limits>

using namespace std;

void menu()
{
    cout << "\n--- Queue Operations Menu ---\n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Display Queue\n";
    cout << "4. Get Current Size\n";
    cout << "5. View Front Element\n";
    cout << "6. Check if Queue is Empty\n";
    cout << "7. Check if Queue is Full\n";
    cout << "8. Exit\n";
    cout << "Enter your choice: ";
}

int main()
{
    Queue<int> myQueue;
    int choice, element;

    while (true)
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
            cout << "Enter the element to enqueue: ";
            cin >> element;
            try
            {
                myQueue.enqueue(element);
                cout << "Element " << element << " has been enqueued." << endl;
            }
            catch (const overflow_error &e)
            {
                cout << e.what() << endl;
            }
            break;

        case 2:
            try
            {
                element = myQueue.dequeue();
                cout << "Element " << element << " has been dequeued." << endl;
            }
            catch (const underflow_error &e)
            {
                cout << e.what() << endl;
            }
            break;

        case 3:
            myQueue.display();
            break;

        case 4:
            cout << "Current Queue Size: " << myQueue.currentSize() << endl;
            break;

        case 5:
            try
            {
                element = myQueue.frontElement();
                cout << "Front Element: " << element << endl;
            }
            catch (const underflow_error &e)
            {
                cout << e.what() << endl;
            }
            break;

        case 6:
            if (myQueue.isEmpty())
            {
                cout << "The queue is empty." << endl;
            }
            else
            {
                cout << "The queue is not empty." << endl;
            }
            break;

        case 7:
            if (myQueue.isFull())
            {
                cout << "The queue is full." << endl;
            }
            else
            {
                cout << "The queue is not full." << endl;
            }
            break;

        case 8:
            cout << "Exiting the program." << endl;
            return 0;

        default:
            cout << "Invalid choice. Please enter a number between 1 and 8." << endl;
            break;
        }
    }

    return 0;
}
