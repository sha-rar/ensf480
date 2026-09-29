/*
* File Name: rectangle.h
* Assignment: Lab 3 Exercise A
* Completed By:
*   Sharar Masud, 30205753
* Submission Date: Sept. 28, 2026
*/

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "square.h"

class Rectangle : public Square {
public:
    Rectangle(double x, double y, double sideA, double sideB, const char* name);
    Rectangle(const Rectangle& other);
    Rectangle& operator=(const Rectangle& other);

    double get_side_b() const;
    virtual void set_side_b(double sideB);

    double area() const override;
    double perimeter() const override;
    void display() const override;

private:
    double side_b;
};

#endif
