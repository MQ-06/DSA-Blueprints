#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include <limits>
#include <algorithm>
using namespace std;
// Unions with Constructors and Destructors

// Only one member can be initialized explicitly in the constructor.
// You need to handle the destruction of union members manually if they are complex types (like classes).

#include <iostream>
using namespace std;

union MyUnion
{
    int intValue;
    float floatValue;
    char charValue;
    string strValue; // string is a complex type

    // Constructor
    MyUnion() : intValue(0) {}
    MyUnion(int i) : intValue(i) {}
    MyUnion(float f) : floatValue(f) {}
    MyUnion(char c) : charValue(c) {}

    // new (&strValue) string(s); is a placement new expression.
    MyUnion(const string &s) { new (&strValue) string(s); } // Placement new
    // Placement new constructs an object in a pre-allocated buffer, in this case, the memory allocated for strValue within the union.

    // Destructor
    ~MyUnion() { strValue.~string(); }
};

int main()
{
    MyUnion u("Hello, World!");
    cout << "String value: " << u.strValue << endl;

    u.~MyUnion(); // Manually call the destructor

    new (&u) MyUnion(3.14f); // Reconstruct as float
    cout << "Float value: " << u.floatValue << endl;
    // Clean up before exiting
    u.~MyUnion(); // Optional if we want to ensure all destructors are called
    return 0;
}
