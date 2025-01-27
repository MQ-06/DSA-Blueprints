#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

template <typename T>

class Node
{
public:
    T data;
    Node<T> *npx;
    Node();
     ~Node();
    Node(T data,Node<T>*node);
    Node(T data);
    void set_data(T data);
    T get_data() const;
    void set_Node(Node<T> *npx);
    Node<T> *get_Node() const;
};