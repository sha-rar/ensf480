/*
* File Name: circle.h
* Assignment: Lab 3 Exercise A
* Completed By:
*   Sharar Masud, 30205753
* Submission Date: Sept. 28, 2026
*/

#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : virtual public Shape {
public:
    Circle(double x, double y, double radius, const char* name);
    Circle(const Circle& other);
    Circle& operator=(const Circle& other);

    double getRadius() const;
    virtual void setRadius(double radius);

    double area() const override;
    double perimeter() const override;
    void display() const override;

private:
    double radius;
};

#endif
