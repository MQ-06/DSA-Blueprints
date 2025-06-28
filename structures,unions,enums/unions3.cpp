#include <iostream>
#include <cstring>
// In this example, ExampleUnion has member functions to set different types of values and print the current state. Keep in mind that because a union can only hold one value at a time, changing one member invalidates the others. This is why the printCurrentState function may not always show meaningful values for all members simultaneously.
union ExampleUnion
{
    int intValue;
    float floatValue;
    char str[20];

    ExampleUnion()
    {
        intValue = 0; // Default initialize intValue
    }

    ~ExampleUnion()
    {
        // No need to explicitly handle cleanup here since there's no dynamic allocation(no complex data types)
    }

    void setInt(int val)
    {
        intValue = val;
    }

    void setFloat(float val)
    {
        floatValue = val;
    }

    void setString(const char *val)
    {
        std::strcpy(str, val);
    }

    void printCurrentState()
    {
        std::cout << "Current state: intValue = " << intValue << ", floatValue = " << floatValue << ", str = " << str << std::endl;
    }
};

int main()
{
    ExampleUnion u;
    u.setInt(10);
    u.printCurrentState();

    u.setFloat(3.14f);
    u.printCurrentState();

    u.setString("Hello");
    u.printCurrentState();

    return 0;
}
