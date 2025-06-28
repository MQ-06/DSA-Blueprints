#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include <limits>
#include <algorithm>
using namespace std;
struct Engine
{
    int horsepower;
    void start()
    {
        cout << "Engine started with " << horsepower << " horsepower" << endl;
    }
};

struct Car
{
    Engine engine;
    string model;
    void startCar()
    {
        cout << "Car model: " << model << endl;
        engine.start();
    }
};

int main()
{
    Car c;
    c.engine.horsepower=900;
    c.model="bmw";
    c.startCar();

    return 0;
}