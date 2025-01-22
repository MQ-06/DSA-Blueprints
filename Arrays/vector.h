#ifndef vector_h
#define vector_h

#include <iostream>
using namespace std;
template <class T>
class Vector
{
    T *arr;
    int max_size;
    int current_size;
    void resize()
    {
        if (current_size == max_size)
        {
            T *temp = new T[max_size * 2];
            for (int i = 0; i < current_size; i++)
            {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
            max_size *= 2;
        }

        if (current_size < max_size / 4)
        {
            T *temp = new T[max_size / 2];
            for (int i = 0; i < current_size; i++)
            {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
            max_size /= 2;
        }
    }

public:
    template <class U>
    friend ostream &operator<<(ostream &out, const Vector<U> &obj);
    template <class U>
    friend istream &operator>>(istream &in, Vector<U> &obj);

    Vector() : arr(nullptr), max_size(0), current_size(0) {}
    Vector(int size)
    {
        if (size < 0)
        {
            throw invalid_argument("Invalid Size");
        }
        this->max_size = size;
        this->current_size = size;
        arr = new T[size]{};
    }
    Vector(const Vector<T> &obj)
    {
        this->max_size = obj.max_size;
        this->current_size = obj.current_size;
        this->arr = new T[current_size];
        for (int i = 0; i < obj.current_size; i++)
        {
            arr[i] = obj.arr[i];
        }
    }
    ~Vector()
    {
        if (arr != nullptr)
        {
            delete[] arr;
            arr = nullptr;
        }
    }

    T getSize() const { return current_size; }
    T *getVector() const { return arr; }

    void setSize(int size)
    {
        if (size < 0)
        {
            throw invalid_argument("Invalid Size!");
        }
        T *temp = new T[size];
        int minSize = size < max_size ? size : max_size;
        for (int i = 0; i < minSize; i++)
        {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        max_size = size;
        current_size = minSize;
    }

    // FUNCTIONALITIES OF THE VECTOR

    int returnCurrentSize() const
    {
        return this->current_size;
    }

    int getMaxSize() const
    {

        return this->max_size;
    }

    bool is_empty()
    {
        return current_size == 0;
    }
    bool is_full()
    {
        return current_size == max_size;
    }
    T at(int index)
    {
        if (index < 0 || index >= max_size)
        {
            throw invalid_argument("Invalid Index");
        }
        return arr[index];
    }
    T erase(int index)
    {
        T temp = arr[index];
        for (int i = index; i < current_size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        current_size--;
        return temp;
    }
    void swap(Vector<T> &obj)
    {

        int temp;
        int MIN = min(this->max_size, obj.max_size);

        for (int i = 0; i < MIN; i++)
        {
            temp = arr[i];
            arr[i] = obj.arr[i];
            obj.arr[i] = temp;
        }
    }
    void move(int num)
    {
        T temp;
        if (num > 0)
        {

            for (int i = 0; i < num; i++)
                temp = arr[max_size - 1];
            {
                for (int j = max_size - 1; j > 0; j--)
                {
                    arr[j] = arr[j - 1];
                }
                arr[0] = temp;
            }
        }
        if (num < 0)
        {

            for (int i = 0; i < num * -1; i++)
                temp = arr[0];
            {
                for (int j = 0; j < max_size; j++)
                {
                    arr[j] = arr[j + 1];
                }
                arr[max_size - 1] = temp;
            }
        }
    }
    void insert(int index, T element)
    {
        if (index < 0 || index >= current_size)
        {
            throw invalid_argument("Invalid Input!");
        }

        if (current_size == max_size)
        {
            resize();
        }

        for (int i = current_size; i >= index; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[index] = element;
        current_size++;
    }

    void sort()
    {
        int temp;
        for (int i = 0; i < current_size; i++)
        {
            for (int j = 0; j < current_size; j++)
            {
                if (arr[i] > arr[j])
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    Vector<T> vector_union(const Vector<T> &obj)
    {
        Vector<T> result(*this);
        for (int i = 0; i < obj.current_size; i++)
        {
            if (!result.search(obj.arr[i]))
            {
                result.push_back(obj.arr[i]);
            }
        }
        return result;
    }

    Vector<T> vector_intersection(Vector<T> &obj)
    {
        Vector<T> result;
        for (int i = 0; i < current_size; i++)
        {
            if (obj.search(arr[i]) && !result.search(arr[i]))
            {
                result.push_back(arr[i]);
            }
        }
        return result;
    }

    Vector<T> unique_vector()
    {
        Vector<T> result;
        for (int i = 0; i < current_size; i++)
        {
            if (!result.search(arr[i]))
            {
                result.push_back(arr[i]);
            }
        }
        return result;
    }

    int count(T element)
    {
        if (this->current_size == 0)
        {
            throw invalid_argument("Vector is Empty!");
        }
        int frequency = 0;
        for (int i = 0; i < current_size; i++)
        {
            if (arr[i] == element)
            {
                frequency++;
            }
        }

        return frequency;
    }
    bool search(T key)
    {
        for (int i = 0; i < current_size; i++)
        {
            if (arr[i] == key)
            {
                return true;
            }
        }
        return false;
    }

    void push_back(T element)
    {
        if (current_size == max_size)
        {
            resize();
        }
        arr[current_size++] = element;
    }
    T pop_back()
    {
        if (current_size == 0)
        {
            return T();
        }

        T poppedElement = arr[--current_size];
        arr[current_size] = T();

        if (current_size < max_size / 4)
        {
            resize();
        }
        current_size++;
        return poppedElement;
    }

    bool subset(Vector<T> &other)
    {
        bool flag;
        for (int i = 0; i < other.current_size; i++)
        {
            flag = false;
            for (int j = 0; j < current_size; j++)
            {
                if (other.arr[i] == arr[j])
                {
                    flag = true;
                    break;
                }
            }
        }
        if (!flag)
        {
            return false;
        }

        return true;
    }
    // OPERATOR OVERLOADING

    Vector<T> operator+(const Vector<T> &obj)
    {
        int size = max_size + obj.max_size;
        Vector<T> result(size);
        for (int i = 0; i < current_size; i++)
        {
            result[i] = arr[i];
        }
        for (int i = 0; i < obj.current_size; i++)
        {
            result[current_size + i] = obj.arr[i];
        }
        return result;
    }
    Vector<T> operator-(const Vector<T> &obj)
    {
        int size = current_size;
        for (int i = 0; i < current_size; i++)
        {
            for (int j = 0; j < obj.current_size; j++)
            {
                if (arr[i] == obj.arr[j])
                {
                    size--;
                    break;
                }
            }
        }

        Vector<T> result(size);
        int index = 0;
        for (int i = 0; i < current_size; i++)
        {
            bool found = false;
            for (int j = 0; j < obj.current_size; j++)
            {
                if (arr[i] == obj.arr[j])
                {
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                result[index++] = arr[i];
            }
        }
        return result;
    }
    T &operator[](int index)
    {
        if (index < 0 || index >= current_size)
        {
            throw invalid_argument("Invalid Index");
        }
        return arr[index];
    }
    bool operator==(Vector &obj)
    {
        bool flag = true;
        if (current_size != obj.current_size)
        {
            return false;
        }

        for (int i = 0; i < min(current_size, obj.current_size); i++)
        {
            if (arr[i] != obj.arr[i])
            {
                return false;
            }
        }
        return true;
    }
    bool operator>(Vector &obj)
    {
        bool flag;

        if (current_size > obj.current_size)
        {
            flag = true;
        }
        else
        {
            flag = false;
        }
        return flag;
    }
    bool operator<(Vector &obj)
    {
        bool flag;

        if (current_size < obj.current_size)
        {
            flag = true;
        }
        else
        {
            flag = false;
        }
        return flag;
    }
    Vector<T> &operator=(const Vector<T> &obj)
    {
        if (this != &obj)
        {
            delete[] arr;
            this->max_size = obj.max_size;
            this->current_size = obj.current_size;

            arr = new T[max_size];
            for (int i = 0; i < current_size; i++)
            {
                arr[i] = obj.arr[i];
            }
        }
        return *this;
    }
};

template <class U>
ostream &operator<<(ostream &out, const Vector<U> &obj)
{
    out << "[";
    for (size_t i = 0; i < obj.current_size; i++)
    {
        out << obj.arr[i];
        if (i < obj.current_size - 1)
        {
            out << ", ";
        }
    }
    out << "]";
    return out;
}

template <class U>
istream &operator>>(istream &in, Vector<U> &obj)
{
    cout << "Enter size of the vector: ";
    if (!(in >> obj.max_size) || obj.max_size <= 0)
    {
        throw invalid_argument("Invalid Size");
    }

    cout << "Enter Elements (separated by spaces):\n";
    obj.arr = new U[obj.max_size];
    for (size_t i = 0; i < obj.max_size; ++i)
    {
        if (!(in >> obj.arr[i]))
        {
            delete[] obj.arr;
            throw invalid_argument("Invalid input format");
        }
        obj.current_size++;
    }
    return in;
}

#endif