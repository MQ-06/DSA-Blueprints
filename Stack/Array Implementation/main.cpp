#include <iostream>
#include <stdexcept>
using namespace std;

void menu()
{
    cout << "1. Push into Stack" << endl;
    cout << "2. Pop from Stack" << endl;
    cout << "3. Check if Stack is Empty" << endl;
    cout << "4. Check if Stack is Full" << endl;
    cout << "5. See size of Stack" << endl;
    cout << "6. Check capacity left in Stack" << endl;
    cout << "7. Assign one stack to another" << endl;
    cout << "8. Display Stack" << endl;
    cout << "0. Exit" << endl;
}
const int MAX_SIZE = 10;

template <typename T>
class Stack
{
private:
    T arr[MAX_SIZE];
    int curr_size;

public:
    Stack() : curr_size(0) {}
    Stack(const Stack<T> &other)
    {
    }
    void push(T value)
    {
        if (curr_size == MAX_SIZE)
        {
            throw overflow_error("Stack overflow");
        }
        arr[curr_size++] = value;
    }

    T pop()
    {
        if (isEmpty())
        {
            throw underflow_error("Stack underflow");
        }
        return arr[--curr_size];
    }

    T Top() const
    {
        if (isEmpty())
        {
            throw underflow_error("Stack is empty");
        }
        return arr[curr_size - 1];
    }

    bool isEmpty() const
    {
        return curr_size == 0;
    }

    bool isFull() const
    {
        return curr_size == MAX_SIZE;
    }

    int getSize() const
    {
        return curr_size;
    }
    int totalCapacity() const
    {
        return MAX_SIZE;
    }
    int getCapacityLeft() const
    {
        return MAX_SIZE - curr_size;
    }

    Stack &operator=(const Stack<T> &other)
    {
        if (this == &other)
        {
            return *this;
        }

        curr_size = other.curr_size;
        for (int i = 0; i < curr_size; ++i)
        {
            arr[i] = other.arr[i];
        }

        return *this;
    }

    void display() const
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return;
        }

        for (int i = 0; i < curr_size; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack<int> s1;
    Stack<int> s2;

    int choice, value;
    do
    {
        menu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter a value to push: ";
            cin >> value;
            try
            {
                s1.push(value);
                cout << "Value pushed into the stack." << endl;
            }
            catch (const exception &e)
            {
                cout << e.what() << endl;
            }
            break;

        case 2:
            try
            {
                value = s1.pop();
                cout << "Popped value: " << value << endl;
            }
            catch (const exception &e)
            {
                cout << e.what() << endl;
            }
            break;

        case 3:
            if (s1.isEmpty())
                cout << "Stack is empty." << endl;
            else
                cout << "Stack is not empty." << endl;
            break;

        case 4:
            if (s1.isFull())
                cout << "Stack is full." << endl;
            else
                cout << "Stack is not full." << endl;
            break;

        case 5:
            cout << "Size of the stack: " << s1.getSize() << endl;
            break;

        case 6:
            cout << "Capacity left: " << s1.getCapacityLeft() << endl;
            break;

        case 7:
            s2 = s1;
            cout << "Stack s1 has been assigned to stack s2." << endl;
            s2.display();
            break;
        case 8:
            cout << "Displaying Stack: " << endl;
            s1.display();
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }

    } while (choice != 0);

    return 0;
}
