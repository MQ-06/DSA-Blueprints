#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include <limits>
#include <algorithm>
using namespace std;

struct Wheel
{
    int size;
    Wheel(int s) : size(s) {}
};
// The Car structure contains pointers to Wheel objects, signifying that a car has wheels.
struct Car
{
    string model;
    Wheel *wheels[4]; // An array wheels of 4 pointers to Wheel objects.

    Car(string model, int size) : model(model)
    { // in composition
        // {    Car(string m, int wheelSize) : model(m), wheels{Wheel(wheelSize), Wheel(wheelSize), Wheel(wheelSize), Wheel(wheelSize)} {}

        for (int i = 0; i < 4; i++)
        {
            wheels[i] = new Wheel(size);
        }
    }
    ~Car()
    {
        for (int i = 0; i < 4; ++i)
        {
            delete wheels[i];
        }
    }

    void display()
    {
        cout << "Car model: " << model << endl;
        for (int i = 0; i < 4; ++i)
        {
            cout << "Wheel " << i + 1 << " size: " << wheels[i]->size << endl;
        }
    }
};

int main()
{
    Car c("BMW", 18);
    c.display();

    return 0;
}