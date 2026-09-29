/*
* File Name: rectangle.cpp
* Assignment: Lab 3 Exercise A
* Completed By:
*   Sharar Masud, 30205753
* Submission Date: Sept. 28, 2026
*/

#include "rectangle.h"

#include <iostream>

Rectangle::Rectangle(double x, double y, double sideA, double sideB, const char* name)
    : Shape(x, y, name), Square(x, y, sideA, name), side_b(sideB)
{
}

Rectangle::Rectangle(const Rectangle& other)
    : Shape(other), Square(other), side_b(other.side_b)
{
}

Rectangle& Rectangle::operator=(const Rectangle& other)
{
    if (this != &other) {
        Square::operator=(other);
        set_side_b(other.side_b);
    }
    return *this;
}

double Rectangle::get_side_b() const
{
    return side_b;
}

void Rectangle::set_side_b(double sideB)
{
    side_b = sideB;
}

double Rectangle::area() const
{
    return get_side_a() * side_b;
}

double Rectangle::perimeter() const
{
    return 2.0 * (get_side_a() + side_b);
}

void Rectangle::display() const
{
    std::cout << "Rectangle Name: " << getName() << '\n'
              << "X-coordinate: " << getOrigin().getx() << '\n'
              << "Y-coordinate: " << getOrigin().gety() << '\n'
              << "Side a: " << get_side_a() << '\n'
              << "Side b: " << side_b << '\n'
              << "Area: " << area() << '\n'
              << "Perimeter: " << perimeter() << '\n';
}
