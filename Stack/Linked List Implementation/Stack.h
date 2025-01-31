#ifndef STACK_H
#define STACK_H

template <typename T>
class StackNode
{

public:
    T data;
    StackNode<T> *next;
    StackNode(T data);
    StackNode();
    StackNode(T data, StackNode<T> *next);
    void setData(T data);
    T getData() const;
    void setNext(StackNode<T> *next);
    StackNode<T> getNext() const;
};

template <typename T>

class Stack
{
    StackNode<T> *top;
    int size;

public:
    Stack();
    ~Stack();
    Stack(const Stack<T> &other);
    T getTop();
    T pop();
    void push(T Element);
    int currSize();
    bool isEmpty()const;
    bool isFull()const;
    T Peek(int nodeNumber);
    void display()const;
};

#endif