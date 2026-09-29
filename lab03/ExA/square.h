/*
* File Name: square.h
* Assignment: Lab 3 Exercise A
* Completed By:
*   Sharar Masud, 30205753
* Submission Date: Sept. 28, 2026
*/

#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"

class Square : virtual public Shape {
public:
    Square(double x, double y, double sideA, const char* name);
    Square(const Square& other);
    Square& operator=(const Square& other);

    double get_side_a() const;
    virtual void set_side_a(double sideA);

    virtual double area() const;
    virtual double perimeter() const;
    void display() const override;

private:
    double side_a;
};

#endif
