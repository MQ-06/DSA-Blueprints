template <typename T>
class Node
{

public:
    T data;
    Node<T> *lchild;
    Node<T> *rchild;
    int height;

    Node(T value) : data(value), lchild(nullptr), rchild(nullptr), height(1) {}

    void setHeight(int height)
    {
        this->height = height;
    }

    int getHeight() const
    {
        return height;
    }

    T getData() const
    {
        return data;
    }

    Node<T>* getLeftChild() const
    {
        return lchild;
    }

    Node<T>* getRightChild() const
    {
        return rchild;
    }

    Node(const Node<T>& other)
        : data(other.data), height(other.height),
          lchild(other.lchild ? new Node<T>(*other.lchild) : nullptr),
          rchild(other.rchild ? new Node<T>(*other.rchild) : nullptr)
    {
    }

    ~Node()
    {
        delete lchild;
        delete rchild;
    }
};
