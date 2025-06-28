#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include <limits>
#include <algorithm>
using namespace std;
typedef struct Date
{
    int day;
    int month;
    int year;
    Date(int d, int m, int y) : day(d), month(m), year(y) {}
    void dob()
    {
        cout << "day: " << day << "  month: " << month << " year: " << year << endl;
    }
} date; //instead of writing whole struct Date we can only write date
// structure with pointers
struct Node
{
    int data;
    Node *next;
};
struct Person
{
    int age;
    string name;
    Date dob;
    Person(int age, string n, Date dob) : age(age), name(n), dob(dob) {}
    void print()
    {
        cout << "name: " << name << " \n age: " << age << endl;
        dob.dob();
    }
};
int main()
{

    Date dob(10, 20, 2004);
    Person p(18, "mariam", dob);
    p.print();

    Node n1, n2, n3;
    n1.data = 1;
    n2.data = 2;
    n3.data = 3;

    n1.next = &n2;
    n2.next = &n3;
    n3.next = nullptr;

    Node *temp = &n1;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}