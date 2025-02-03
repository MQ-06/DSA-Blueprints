#include <iostream>
#include <stdexcept>
#include <limits>
#include <stdexcept>
#include "CircularQueue.cpp"
using namespace std;
void menu()
{
    cout << "\n--- Circular Queue Menu ---" << endl;
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Check if the queue is full" << endl;
    cout << "4. Check if the queue is empty" << endl;
    cout << "5. Get current size of the queue" << endl;
    cout << "6. Peek at front element" << endl;
    cout << "7. Display the queue" << endl;
    cout << "8. Exit" << endl;
}

int main()
{
    int size;

    while (true)
    {
        try
        {
            cout << "Enter the size of the circular queue: ";
            cin >> size;

            if (cin.fail() || size <= 0)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Invalid size. Please enter a positive integer.");
            }
            break;
        }
        catch (const invalid_argument &e)
        {
            cout << e.what() << endl;
        }
    }

    CircularQueue<int> queue(size);
    int choice;

    do
    {
        menu();
        try
        {
            cout << "Please choose an option (1-8): ";

            cin >> choice;

            if (cin.fail() || choice < 1 || choice > 8)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Invalid choice. Please choose a valid option (1-8).");
            }

            switch (choice)
            {
            case 1:
            {
                int value;
                cout << "Enter the value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                break;
            }
            case 2:
            {
                try
                {
                    cout << "Dequeued element: " << queue.dequeue() << endl;
                }
                catch (const underflow_error &e)
                {
                    cout << e.what() << endl;
                }
                break;
            }
            case 3:
            {
                cout << "Is the queue full? " << (queue.isFull() ? "Yes" : "No") << endl;
                break;
            }
            case 4:
            {
                cout << "Is the queue empty? " << (queue.isEmpty() ? "Yes" : "No") << endl;
                break;
            }
            case 5:
            {
                cout << "Current size of the queue: " << queue.size() << endl;
                break;
            }
            case 6:
            {
                try
                {
                    cout << "Front element: " << queue.peek() << endl;
                }
                catch (const underflow_error &e)
                {
                    cout << e.what() << endl;
                }
                break;
            }
            case 7:
            {
                queue.display();
                break;
            }
            case 8:
            {
                cout << "Exiting the program." << endl;
                break;
            }
            }
        }
        catch (const invalid_argument &e)
        {
            cout << e.what() << endl;
        }

    } while (choice != 8);

    return 0;
}
