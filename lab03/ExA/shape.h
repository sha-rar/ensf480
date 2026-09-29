/*
* File Name: shape.h
* Assignment: Lab 3 Exercise A
* Completed By:
*   Sharar Masud, 30205753
* Submission Date: Sept. 28, 2026
*/

#ifndef SHAPE_H
#define SHAPE_H

#include "point.h"

class Shape {
public:
    Shape(double x, double y, const char* name);
    Shape(const Shape& other);
    Shape& operator=(const Shape& other);
    virtual ~Shape();

    const Point& getOrigin() const;
    const char* getName() const;

    virtual double area() const;
    virtual double perimeter() const;
    virtual void display() const;

    double distance(const Shape& other) const;
    static double distance(const Shape& the_shape, const Shape& other);

    void move(double dx, double dy);

protected:
    Point origin;

private:
    char* shapeName;

    static char* duplicateName(const char* name);
};

#endif
