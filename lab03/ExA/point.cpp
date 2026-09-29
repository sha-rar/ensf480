/*
* File Name: point.cpp
* Assignment: Lab 3 Exercise A
* Completed By:
*   Sharar Masud, 30205753
* Submission Date: Sept. 28, 2026
*/

#include "point.h"

#include <cmath>
#include <iomanip>
#include <iostream>

int Point::objectCount = 0;
int Point::nextId = 1001;

Point::Point(double xValue, double yValue)
    : x(xValue), y(yValue), id(nextId++)
{
    ++objectCount;
}

Point::Point(const Point& other)
    : x(other.x), y(other.y), id(nextId++)
{
    ++objectCount;
}

Point& Point::operator=(const Point& other)
{
    if (this != &other) {
        x = other.x;
        y = other.y;
        // id deliberately remains unchanged: it identifies this Point object.
    }
    return *this;
}

Point::~Point()
{
    --objectCount;
}

double Point::getx() const
{
    return x;
}

double Point::gety() const
{
    return y;
}

int Point::getid() const
{
    return id;
}

void Point::setx(double xValue)
{
    x = xValue;
}

void Point::sety(double yValue)
{
    y = yValue;
}

void Point::display() const
{
    const std::ios::fmtflags oldFlags = std::cout.flags();
    const std::streamsize oldPrecision = std::cout.precision();

    std::cout << std::fixed << std::setprecision(2)
              << "X-coordinate: " << x << '\n'
              << "Y-coordinate: " << y << '\n';

    std::cout.flags(oldFlags);
    std::cout.precision(oldPrecision);
}

int Point::counter()
{
    return objectCount;
}

double Point::distance(const Point& other) const
{
    return Point::distance(*this, other);
}

double Point::distance(const Point& first, const Point& second)
{
    const double dx = first.x - second.x;
    const double dy = first.y - second.y;
    return std::sqrt(dx * dx + dy * dy);
}
