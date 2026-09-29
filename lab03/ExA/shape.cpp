/*
* File Name: shape.cpp
* Assignment: Lab 3 Exercise A
* Completed By:
*   Sharar Masud, 30205753
* Submission Date: Sept. 28, 2026
*/

#include "shape.h"

#include <cstring>
#include <iostream>

char* Shape::duplicateName(const char* name)
{
    const char* source = (name != nullptr) ? name : "";
    char* result = new char[std::strlen(source) + 1];
    std::strcpy(result, source);
    return result;
}

Shape::Shape(double x, double y, const char* name)
    : origin(x, y), shapeName(duplicateName(name))
{
}

Shape::Shape(const Shape& other)
    : origin(other.origin), shapeName(duplicateName(other.shapeName))
{
}

Shape& Shape::operator=(const Shape& other)
{
    if (this != &other) {
        char* newName = duplicateName(other.shapeName);
        origin = other.origin;
        delete[] shapeName;
        shapeName = newName;
    }
    return *this;
}

Shape::~Shape()
{
    delete[] shapeName;
}

const Point& Shape::getOrigin() const
{
    return origin;
}

const char* Shape::getName() const
{
    return shapeName;
}

double Shape::area() const
{
    return 0.0;
}

double Shape::perimeter() const
{
    return 0.0;
}

void Shape::display() const
{
    std::cout << "Shape Name: " << shapeName << '\n'
              << "X-coordinate: " << origin.getx() << '\n'
              << "Y-coordinate: " << origin.gety() << '\n';
}

double Shape::distance(const Shape& other) const
{
    return origin.distance(other.origin);
}

double Shape::distance(const Shape& the_shape, const Shape& other)
{
    return Point::distance(the_shape.origin, other.origin);
}

void Shape::move(double dx, double dy)
{
    origin.setx(origin.getx() + dx);
    origin.sety(origin.gety() + dy);
}
