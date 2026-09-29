/*
* File Name: square.cpp
* Assignment: Lab 3 Exercise A
* Completed By:
*   Sharar Masud, 30205753
* Submission Date: Sept. 28, 2026
*/

#include "square.h"

#include <iostream>

Square::Square(double x, double y, double sideA, const char* name)
    : Shape(x, y, name), side_a(sideA)
{
}

Square::Square(const Square& other)
    : Shape(other), side_a(other.side_a)
{
}

Square& Square::operator=(const Square& other)
{
    if (this != &other) {
        Shape::operator=(other);
        set_side_a(other.side_a);
    }
    return *this;
}

double Square::get_side_a() const
{
    return side_a;
}

void Square::set_side_a(double sideA)
{
    side_a = sideA;
}

double Square::area() const
{
    return side_a * side_a;
}

double Square::perimeter() const
{
    return 4.0 * side_a;
}

void Square::display() const
{
    std::cout << "Square Name: " << getName() << '\n'
              << "X-coordinate: " << getOrigin().getx() << '\n'
              << "Y-coordinate: " << getOrigin().gety() << '\n'
              << "Side a: " << side_a << '\n'
              << "Area: " << area() << '\n'
              << "Perimeter: " << perimeter() << '\n';
}
