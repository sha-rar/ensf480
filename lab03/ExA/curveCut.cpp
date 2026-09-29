/*
* File Name: curveCut.cpp
* Assignment: Lab 3 Exercise A
* Completed By:
*   Sharar Masud, 30205753
* Submission Date: Sept. 28, 2026
*/

#include "curveCut.h"

#include <cstdlib>
#include <iostream>

namespace {
void terminateForInvalidDimensions()
{
    std::cerr << "Error: the radius of a CurveCut cannot exceed its width or length.\n";
    std::exit(EXIT_FAILURE);
}
}

CurveCut::CurveCut(double x, double y, double width, double length,
                   double radius, const char* name)
    : Shape(x, y, name),
      Rectangle(x, y, width, length, name),
      Circle(x, y, radius, name)
{
    validateDimensions();
}

CurveCut::CurveCut(const CurveCut& other)
    : Shape(other), Rectangle(other), Circle(other)
{
}

CurveCut& CurveCut::operator=(const CurveCut& other)
{
    if (this != &other) {
        Shape::operator=(other);
        Square::set_side_a(other.get_side_a());
        Rectangle::set_side_b(other.get_side_b());
        Circle::setRadius(other.getRadius());
    }
    return *this;
}

void CurveCut::set_side_a(double width)
{
    if (getRadius() > width) {
        terminateForInvalidDimensions();
    }
    Square::set_side_a(width);
}

void CurveCut::set_side_b(double length)
{
    if (getRadius() > length) {
        terminateForInvalidDimensions();
    }
    Rectangle::set_side_b(length);
}

void CurveCut::setRadius(double radius)
{
    if (radius > get_side_a() || radius > get_side_b()) {
        terminateForInvalidDimensions();
    }
    Circle::setRadius(radius);
}

double CurveCut::area() const
{
    return Rectangle::area() - Circle::area() / 4.0;
}

double CurveCut::perimeter() const
{
    return Rectangle::perimeter() - 2.0 * getRadius()
           + Circle::perimeter() / 4.0;
}

void CurveCut::display() const
{
    std::cout << "CurveCut Name: " << getName() << '\n'
              << "X-coordinate: " << getOrigin().getx() << '\n'
              << "Y-coordinate: " << getOrigin().gety() << '\n'
              << "Width: " << get_side_a() << '\n'
              << "Length: " << get_side_b() << '\n'
              << "Radius of the cut: " << getRadius() << '\n';
}

void CurveCut::validateDimensions() const
{
    if (getRadius() > get_side_a() || getRadius() > get_side_b()) {
        terminateForInvalidDimensions();
    }
}
