#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class HashMap
{
    string *table;
    int S;
    int n;

    int getHashValue(const string &str)
    {
        int value = 0;
        for (char ch : str)
        {
            value += ch;
        }
        return value % S;
    }

public:
    HashMap(int size = 10) : S(size), n(0)
    {
        table = new string[S];
        for (int i = 0; i < S; i++)
        {
            table[i] = "";
        }
    }

    ~HashMap()
    {
        delete[] table;
    }

    bool isFull()
    {
        return n == S;
    }

    bool isEmpty()
    {
        return n == 0;
    }

    double loadFactor()
    {
        return static_cast<double>(n) / S;
    }

    bool insert(string str)
    {
        if (isFull())
        {
            cout << "Cannot insert \"" << str << "\". The hash table is full.\n";
            return false;
        }

        int index = getHashValue(str);
        cout << "Inserting \"" << str << "\" \n";
        cout << "Indices traversed: ";

        while (!table[index].empty())
        {
            cout << index;
            if (table[index] != str)
            {
                cout << " -> ";
            }
            else
            {
                cout << "\n\"" << str << "\" is already in the hash table.\n";
                return false;
            }
            index = (index + 1) % S;
        }

        cout << index << "\n";
        table[index] = str;
        n++;
        cout << "\"" << str << "\" was inserted at index " << index << ".\n";
        return true;
    }

    bool search(string str)
    {
        if (isEmpty())
        {
            cout << "Cannot search for \"" << str << "\". The hash table is empty.\n";
            return false;
        }

        int index = getHashValue(str);
        int start = index;
        cout << "Searching for \"" << str << "\" \n";
        cout << "Indices traversed: ";

        while (!table[index].empty())
        {
            cout << index;
            if (table[index] != str)
            {
                cout << " -> ";
            }
            else
            {
                cout << "\n\"" << str << "\" is in the hash table at index " << index << ".\n";
                return true;
            }
            index = (index + 1) % S;
            if (index == start)
            {
                break;
            }
        }
        cout << "\n\"" << str << "\" is not in the hash table.\n";
        return false;
    }

    void display()
    {
        cout << "Hash table contents:\n";
        for (int i = 0; i < S; ++i)
        {
            cout << "Index " << i << ": ";
            if (table[i].empty())
            {
                cout << "EMPTY\n";
            }
            else
            {
                cout << table[i] << "\n";
            }
        }
    }

    bool remove(string str)
    {
        if (isEmpty())
        {
            cout << "Cannot remove \"" << str << "\". The hash table is empty.\n";
            return false;
        }

        int index = getHashValue(str);
        int start = index;
        cout << "Removing \"" << str << "\" \n";
        cout << "Indices traversed: ";

        while (!table[index].empty())
        {
            cout << index;
            if (table[index] != str)
            {
                cout << " -> ";
            }
            else
            {
                cout << "\n\"" << str << "\" was removed from the hash table at index " << index << ".\n";
                table[index] = "";
                n--;
                return true;
            }
            index = (index + 1) % S;
            if (index == start)
            {
                break;
            }
        }
        cout << "\n\"" << str << "\" is not in the hash table.\n";
        return false;
    }
};
