#include <iostream>
#include <limits>
#include "Stack.cpp"

using namespace std;

void menu()
{
    cout << "\n--- Stack Operations Menu ---\n";

    cout << "1. Push an element" << endl;
    cout << "2. Pop an element" << endl;
    cout << "3. Peek an element" << endl;
    cout << "4. Get the top element" << endl;
    cout << "5. Check if the stack is empty" << endl;
    cout << "6. Get current size of the stack" << endl;
    cout << "7. Display stack" << endl;
    cout << "8. Exit" << endl;
}

int main()
{
    Stack<int> stack;
    int choice, element, nodeNumber;

    while (true)
    {
        menu();
        cout << "Enter your choice: ";

        while (!(cin >> choice) || choice < 1 || choice > 8)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice. Please enter a number between 1 and 7: ";
        }

        switch (choice)
        {
        case 1:
            cout << "Enter element to push: ";
            while (!(cin >> element))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter an integer: ";
            }
            try
            {
                stack.push(element);
                cout << element << " pushed to stack." << endl;
            }
            catch (const overflow_error &e)
            {
                cout << e.what() << endl;
            }
            break;

        case 2: // Pop
            try
            {
                element = stack.pop();
                cout << element << " popped from stack." << endl;
            }
            catch (const underflow_error &e)
            {
                cout << e.what() << endl;
            }
            break;

        case 3:
            cout << "Enter node number to peek: ";
            while (!(cin >> nodeNumber))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a positive integer for node number: ";
            }
            try
            {
                element = stack.Peek(nodeNumber);
                cout << "Element at position " << nodeNumber << " is " << element << endl;
            }
            catch (const invalid_argument &e)
            {
                cout << e.what() << endl;
            }
            break;

        case 4:
            try
            {
                element = stack.getTop();
                cout << "Top element is " << element << endl;
            }
            catch (const underflow_error &e)
            {
                cout << e.what() << endl;
            }
            break;

        case 5:
            if (stack.isEmpty())
            {
                cout << "Stack is empty." << endl;
            }
            else
            {
                cout << "Stack is not empty." << endl;
            }
            break;

        case 6:
            cout << "Current size of the stack is " << stack.currSize() << endl;
            break;

        case 8:
            cout << "Exiting..." << endl;
            return 0;

        case 7:
            stack.display();
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
