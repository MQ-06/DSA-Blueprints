#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include <limits>
#include <algorithm>
using namespace std;
// Structures in C++ are user-defined data types that allow the grouping of variables of different types under a single name.
// Struct: Members are public by default.
// Class: Members are private by default.

// BASIC STRCUTURE
struct Person
{
    int age;
    string name;
    float gpa;
};

// STRUCTUR WITH CONSTRUCTOR

struct car
{
    float engine;
    car(float engine) : engine(engine) {}

    void display()
    {
        cout << "engine: " << engine << " cc " << endl;
    }
};
// with member functions

struct point
{
    int x;
    int y;
    point(int x, int b)
    {
        this->x = x;
        this->y = b;
    }

    void print()
    {
        cout << "POINTS [ " << x << " , " << y << " ]" << endl;
    }
};
int main()
{

    Person p1;
    struct Person p2;
    p1.name = "mariam";
    p1.age = 19;
    p1.gpa = 3.7;
    p2.name = "rahaat";
    p2.age = 20;
    p2.gpa = 5.67;

    cout << "p1 details: " << endl;
    cout << "name: " << p1.name << endl;
    cout << "age: " << p1.age << endl;
    cout << "gpa: " << p1.gpa << endl;

    car c(5.99);
    c.display();
    point p(10, 20);
    p.print();
    return 0;
}