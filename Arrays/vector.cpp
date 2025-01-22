#include <iostream>
#include <chrono>
#include <thread>
#include "vector.h"

using namespace std;

void menu()
{
    cout << endl;
    cout << "---------VECTOR FUNCTIONALITIES---------" << endl;
    cout << "1. Show Current Size of the Vector" << endl;
    cout << "2. Show Max Size of the Vector" << endl;
    cout << "3. Push_Back Elements" << endl;
    cout << "4. Pop_Back Elements" << endl;
    cout << "5. Vector is Empty or Not? " << endl;
    cout << "6. Vector is Full or Not? " << endl;
    cout << "7. See Element at a index " << endl;
    cout << "8. Remove Element at a index " << endl;
    cout << "9. Swap Vector" << endl;
    cout << "10. Insert Element in a Vector" << endl;
    cout << "11. Move Elements in a Vector" << endl;
    cout << "12. Union of Vector" << endl;
    cout << "13. Intersection of Vector" << endl;
    cout << "14. Unique Vector" << endl;
    cout << "15. Occurrence of a specific element " << endl;
    cout << "16. Check Subset" << endl;
    cout << "17. Search Desired Key" << endl;
    cout << "-------OPERATOR OVERLOADING------" << endl;
    cout << "18. Addition(+) Operator Overloading" << endl;
    cout << "19. - Operator Overloading" << endl;
    cout << "20. Equality(==) Operator Overloading" << endl;
    cout << "21. Relational(<) Operator Overloading" << endl;
    cout << "22. Relational(>) Operator Overloading" << endl;
    cout << "23. Assignment(=) Operator Overloading" << endl;
    cout << "24. Index([]) Operator Overloading" << endl;
    cout << "PRESS 0 TO EXIT" << endl;
}

int main()
{

    int e;
    int v;
    Vector<int> obj1;
    Vector<int> obj2;

    cout << "For Vector 1: " << endl;

    do
    {
        try
        {
            cin >> obj1;
            break;
        }
        catch (exception &e)
        {
            cout << "ERROR! Enter Again! " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (true);

    cout << endl;
    cout << "For Vector 2: " << endl;

    do
    {
        try
        {
            cin >> obj2;
            break;
        }
        catch (exception &e)
        {
            cout << "ERROR! Enter Again! " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (true);
    cout << "VECTOR 1: ";
    cout << obj1;
    cout << endl;
    cout << "VECTOR 2: ";
    cout << obj2;
    cout << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));

    int choice;
    int num = 0;
    bool b;
    bool z;
    bool x;
    bool y;
    Vector<int> r1;
    Vector<int> r2;
    Vector<int> r3;
    Vector<int> obj3;
    Vector<int> obj4;

    do
    {
        menu();
        cout << "Enter Your Choice: ";
        cin >> choice;
        if (choice == 0)
        {
            exit(0);
        }
        else if (choice < 0)
        {
            cout << "Enter Again: ";
            continue;
        }
        else
        {
            if ((choice >= 1 && choice <= 8) || (choice == 11 || choice == 10 || choice == 15 || choice == 17 || choice == 24 || choice == 14))
            {
                do
                {
                    cout << "Which Object Functions Do You Want to See?\n PRESS 1 FOR OBJECT 1 \n PRESS 2 FOR OBJECT 2" << endl;
                    cin >> num;
                    if (num != 1 && num != 2)
                    {
                        cout << "You can only enter digits 1 or 2" << endl;
                    }
                    else
                    {
                        break;
                    }
                } while (true);
            }
        }

        switch (choice)
        {
        case 1:
            if (num == 1)
            {
                const int size = obj1.returnCurrentSize();
                cout << "The Current Size of Vector 1 is: " << size << endl;
            }
            else if (num == 2)
            {
                const int size = obj2.returnCurrentSize();
                cout << "The Current Size of Vector 2 is: " << size << endl;
            }
            break;
        case 2:
            if (num == 1)
            {
                const int size = obj1.getMaxSize();
                cout << "The Max Size of Vector 1 is: " << size << endl;
            }
            else if (num == 2)
            {
                const int size = obj2.getMaxSize();
                cout << "The Max Size of Vector 2 is: " << size << endl;
            }
            break;
        case 3:

            cout << "Enter the element you want to add: ";
            cin >> e;
            if (num == 1)
            {
                obj1.push_back(e);
                cout << obj1;
            }
            else if (num == 2)
            {
                obj2.push_back(e);
                cout << obj2;
            }
            break;
        case 4:
            if (num == 1)
            {

                v = obj1.pop_back();
                cout << "After popping " << v << " Vector is: ";
                cout << obj1 << endl;
                cin.clear();
            }
            else if (num == 2)
            {
                v = obj2.pop_back();
                cout << "After popping " << v << " Vector is: ";
                cout << obj2 << endl;
                cin.clear();
            }
            break;
        case 5:
            if (num == 1)
            {
                if (obj1.is_empty())
                {
                    cout << "Vector 1 is Empty" << endl;
                }
                else
                {
                    cout << "Vector 1 is not Empty" << endl;
                }
            }
            else if (num == 2)
            {
                if (obj2.is_empty())
                {
                    cout << "Vector 2 is Empty" << endl;
                }
                else
                {
                    cout << "Vector 2 is not Empty" << endl;
                }
            }
            break;
        case 6:
            if (num == 1)
            {
                if (obj1.is_full())
                {
                    cout << "Vector 1 is Full" << endl;
                }
                else
                {
                    cout << "Vector 1 is not Full" << endl;
                }
            }
            else if (num == 2)
            {
                if (obj2.is_full())
                {
                    cout << "Vector 2 is Full" << endl;
                }
                else
                {
                    cout << "Vector 2 is not Ful" << endl;
                }
            }
            break;
        case 7:
            if (num == 1)
            {
                int index;
                cout << "At Which Index Do You want to see value? ";
                try
                {
                    cin >> index;
                    int value = obj1.at(index);
                    cout << "The value at index " << index << " is " << value << endl;
                }
                catch (exception &e)
                {
                    cout << "ERROR! " << e.what() << endl;
                    cin.ignore();
                }
            }
            else if (num == 2)
            {
                int index;
                cout << "At Which Index Do You want to see value? ";
                try
                {
                    cin >> index;
                    int value = obj2.at(index);
                    cout << "The value at index " << index << " is " << value << endl;
                }
                catch (exception &e)
                {
                    cout << "ERROR! " << e.what() << endl;
                }
            }
            break;
        case 8:
            if (num == 1)
            {
                int index;
                cout << "At Which Index Do You want to erase the value? ";
                try
                {
                    cin >> index;
                    int value = obj1.erase(index);
                    cout << "The value being erased is: " << value << endl;
                }
                catch (exception &e)
                {
                    cout << "ERROR! " << e.what() << endl;
                }
            }
            else if (num == 2)
            {
                int index;
                cout << "At Which Index Do You want to erase the value? ";
                try
                {
                    cin >> index;
                    int value = obj2.erase(index);
                    cout << "The value being erased is: " << value << endl;
                }
                catch (exception &e)
                {
                    cout << "ERROR! " << e.what() << endl;
                }
            }
            break;
        case 9:
            cout << "Before Swapping: " << endl;
            cout << "VECTOR 1: ";
            cout << obj1 << endl;
            cout << "VECTOR 2: ";
            cout << obj2 << endl;
            cout << endl;
            cout << "After Swapping: " << endl;

            obj1.swap(obj2);
            cout << "VECTOR 1: ";

            cout << obj1 << endl;
            cout << "VECTOR 2: ";
            cout << obj2 << endl;
            break;
        case 10:
            if (num == 1)
            {
                int index;
                int element;
                cout << "At Which Index Do You want to insert the element? ";
                try
                {
                    cin >> index;
                    cout << "And Which Element? ";
                    cin >> element;
                    obj1.insert(index, element);
                    cout << "After Insetion Vector Becomes" << endl;
                    cout << obj1;
                }
                catch (exception &e)
                {
                    cout << "ERROR! " << e.what() << endl;
                }
            }
            else if (num == 2)
            {
                int index;
                int element;
                cout << "At Which Index Do You want to insert the element? ";
                try
                {
                    cin >> index;
                    cout << "And Which Element? ";
                    cin >> element;
                    obj2.insert(index, element);
                    cout << "After Insetion Vector Becomes" << endl;
                    cout << obj2;
                }
                catch (exception &e)
                {
                    cout << "ERROR! " << e.what() << endl;
                }
            }
            break;
        case 11:
            int key;
            cout << "Enter Key for Forward(>0) or Backward(<0) rotation: ";
            cin >> key;
            if (num == 1)
            {
                cout << "Before " << key << " times rotation ";
                cout << obj1 << endl;
                cout << "After " << key << " times rotation ";
                obj1.move(key);
                cout << obj1 << endl;
            }
            else if (num == 2)
            {
                cout << "Before " << key << " times rotation ";
                cout << obj2 << endl;
                cout << "After " << key << " times rotation ";
                obj2.move(key);
                cout << obj2 << endl;
            }
            break;
        case 12:
            std::cout << "Union of Vectors: " << std::endl;
            r1 = obj1.vector_union(obj2);
            std::cout << r1 << std::endl;
            break;
        case 13:
            std::cout << "Intersection of Vectors: " << std::endl;
            r2 = obj1.vector_intersection(obj2);
            std::cout << r2 << std::endl;
            break;
        case 14:
            if (num == 1)
            {
                try
                {
                    std::cout << "Unique Vector: " << std::endl;
                    r3 = obj1.unique_vector();
                    std::cout << r3 << std::endl;
                }
                catch (exception &e)
                {
                    cout << "ERROR! " << e.what() << endl;
                }
            }
            else if (num == 2)
            {
                try
                {
                    std::cout << "Unique Vector: " << std::endl;
                    r3 = obj2.unique_vector();
                    std::cout << r3 << std::endl;
                }
                catch (exception &e)
                {
                    cout << "ERROR! " << e.what() << endl;
                }
            }
            break;
        case 15:
            int n;
            cout << "Enter Value You Want to see occurence of in vector ";
            cin >> n;
            if (num == 1)
            {
                try
                {
                    int occurence = obj1.count(n);
                    if (occurence != 0)
                    {

                        cout << "The frequency of element " << n << " is " << occurence << endl;
                    }
                    else
                    {
                        cout << "Element not found!" << endl;
                    }
                }
                catch (exception &e)
                {
                    cout << "ERROR! " << e.what() << endl;
                }
            }
            else if (num == 2)
            {
                try
                {
                    int occurence = obj2.count(n);
                    if (occurence != 0)
                    {

                        cout << "The frequency of element " << n << " is " << occurence << endl;
                    }
                    else
                    {
                        cout << "Element not found!" << endl;
                    }
                }
                catch (exception &e)
                {
                    cout << "ERROR! " << e.what() << endl;
                }
            }
            break;
        case 16:
            b = obj1.subset(obj2);
            if (b)
            {
                cout << "Vector 2 is a subset of Vector 1" << endl;
            }
            else
            {
                cout << "Vector 2 is not a subset of Vector 1" << endl;
            }
            break;
        case 17:
            int k;
            cout << "Enter Key You want to find in vector: ";
            cin >> k;
            if (num == 1)
            {
                try
                {
                    if (obj1.search(k))
                    {
                        cout << "KEY FOUND !" << endl;
                    }
                    else
                    {
                        cout << "KEY NOT FOUND !" << endl;
                    }
                }
                catch (exception &e)
                {
                    cout << "ERROR! " << e.what() << endl;
                }
            }
            else if (num == 2)
            {
                try
                {
                    if (obj2.search(k))
                    {
                        cout << "KEY FOUND !" << endl;
                    }
                    else
                    {
                        cout << "KEY NOT FOUND !" << endl;
                    }
                }
                catch (exception &e)
                {
                    cout << "ERROR! " << e.what() << endl;
                }
            }
            break;
        case 18:
            obj3 = obj1 + obj2;
            cout << obj3 << endl;
            break;
        case 19:
            obj4 = obj1 - obj2;
            cout << obj4 << endl;
            break;
        case 20:
            z = obj1 == obj2;
            if (z)
            {
                cout << "Both Vectors are Equal " << endl;
            }
            else
            {
                cout << "Both Vectors are UnEqual " << endl;
            }
            break;
        case 21:
            y = obj1 < obj2;
            if (y)
            {
                cout << "Size of Vector 1 is Smaller" << endl;
            }
            else
            {
                cout << "Size of Vector 2 is Smaller" << endl;
            }

            break;
        case 22:
            x = obj1 > obj2;
            if (x)
            {
                cout << "Size of Vector 1 is Greater" << endl;
            }
            else
            {
                cout << "Size of Vector 2 is Greater" << endl;
            }
            break;
        case 23:
            cout << "After Assignment Vector 1 becomes" << endl;
            obj1 = obj2;
            cout << obj1 << endl;
            break;
        case 24:
            int i;
            cout << "Enter index you want to see value at? ";
            cin >> i;
            if (num == 1)
            {
                try
                {
                    int t = obj1[i];
                    cout << "The value at index " << i << " is " << t << endl;
                }
                catch (exception &e)
                {
                    cout << "ERROR! " << e.what() << endl;
                }
            }
            else if (num == 2)
            {
                try
                {
                    int t = obj2[i];
                    cout << "The value at index " << i << " is " << t << endl;
                }
                catch (exception &e)
                {
                    cout << "ERROR! " << e.what() << endl;
                }
            }
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }

        char last = 'N';
        cout << "DO YOU WANT TO CONTINUE?(Y or N) ";
        cin >> last;
        if (last == 'N' || last == 'n')
        {
            break;
        }

    } while (choice != 0);

    return 0;
}
