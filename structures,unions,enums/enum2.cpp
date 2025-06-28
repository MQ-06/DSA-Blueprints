#include <iostream>
// TYPESAFETY YES
// ENUM CLASS
// enum class Color { RED, GREEN, BLUE };
// int colorValue = Color::RED; // Error

// TYPESAFETY NO

// ENUM
// enum Color { RED, GREEN, BLUE };
// int colorValue = RED; // OK

enum class Color
{
    RED,
    GREEN,
    BLUE
};

void printColor(Color color)
{
    switch (color)
    {
    case Color::RED:
        std::cout << "Red\n";
        break;
    case Color::GREEN:
        std::cout << "Green\n";
        break;
    case Color::BLUE:
        std::cout << "Blue\n";
        break;
    }
}

int main()
{
    Color myColor = Color::GREEN;
    printColor(myColor);
    return 0;
}
