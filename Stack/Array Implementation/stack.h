#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include <limits>
#include <algorithm>
using namespace std;
template <typename T>
class Stack
{
    T *arr;
    int max_size;
    int curr_size;

    void resize()
    {
        max_size *= 2;
        T *new_arr = new T[max_size];
        for (int i = 0; i < curr_size; i++)
        {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
    }

public:
    Stack() : curr_size(0), max_size(10) {}
    Stack(int max_size) : curr_size(0)
    {
        this->max_size = max_size;
        if (max_size <= 0)
        {
            throw invalid_argument("Invalid size");
        }
        arr = new T[max_size];
    }

    ~Stack()
    {
        delete[] arr;
    }

    Stack(const Stack<T> &other) : max_size(other.max_size), curr_size(other.curr_size)
    {
        arr = new T[max_size];
        for (int i = 0; i < curr_size; i++)
        {
            arr[i] = other.arr[i];
        }
    }

    Stack &operator=(const Stack<T> &other)
    {
        if (this == &other)
        {
            return *this;
        }
        delete[] arr;
        max_size = other.max_size;
        curr_size = other.curr_size;
        arr = new T[max_size];
        for (int i = 0; i < curr_size; i++)
        {
            arr[i] = other.arr[i];
        }
        return *this;
    }

    void push(T value)
    {
        if (isFull())
        {
            resize();
        }
        arr[curr_size++] = value;
    }

    T pop()
    {
        if (isEmpty())
        {
            throw underflow_error("Stack is empty!");
        }
        return arr[--curr_size];
    }

    T top()
    {
        if (isEmpty())
        {
            throw invalid_argument("Stack is Empty!");
        }
        return arr[curr_size - 1];
    }

    int getSize() const
    {
        return curr_size;
    }

    int getCapacity() const
    {
        return max_size;
    }

    int getNumberofElements() const
    {
        return max_size - curr_size;
    }

    bool isEmpty() const
    {
        return curr_size == 0;
    }

    bool isFull() const
    {
        return curr_size == max_size;
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