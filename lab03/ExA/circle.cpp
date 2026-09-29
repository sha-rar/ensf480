/*
* File Name: circle.cpp
* Assignment: Lab 3 Exercise A
* Completed By:
*   Sharar Masud, 30205753
* Submission Date: Sept. 28, 2026
*/

#include "circle.h"

#include <cstdlib>
#include <iostream>

namespace {
const double PI = 3.14159265358979323846;

void validateRadius(double radius)
{
    if (radius < 0.0) {
        std::cerr << "Error: radius cannot be negative.\n";
        std::exit(EXIT_FAILURE);
    }
}
}

Circle::Circle(double x, double y, double radiusValue, const char* name)
    : Shape(x, y, name), radius(radiusValue)
{
    validateRadius(radius);
}

Circle::Circle(const Circle& other)
    : Shape(other), radius(other.radius)
{
}

Circle& Circle::operator=(const Circle& other)
{
    if (this != &other) {
        Shape::operator=(other);
        setRadius(other.radius);
    }
    return *this;
}

double Circle::getRadius() const
{
    return radius;
}

void Circle::setRadius(double radiusValue)
{
    validateRadius(radiusValue);
    radius = radiusValue;
}

double Circle::area() const
{
    return PI * radius * radius;
}

double Circle::perimeter() const
{
    return 2.0 * PI * radius;
}

void Circle::display() const
{
    std::cout << "Circle Name: " << getName() << '\n'
              << "X-coordinate: " << getOrigin().getx() << '\n'
              << "Y-coordinate: " << getOrigin().gety() << '\n'
              << "Radius: " << radius << '\n'
              << "Area: " << area() << '\n'
              << "Perimeter: " << perimeter() << '\n';
}
