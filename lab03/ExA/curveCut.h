/*
* File Name: curveCut.h
* Assignment: Lab 3 Exercise A
* Completed By:
*   Sharar Masud, 30205753
* Submission Date: Sept. 28, 2026
*/

#ifndef CURVECUT_H
#define CURVECUT_H

#include "circle.h"
#include "rectangle.h"

class CurveCut : public Rectangle, public Circle {
public:
    CurveCut(double x, double y, double width, double length,
             double radius, const char* name);
    CurveCut(const CurveCut& other);
    CurveCut& operator=(const CurveCut& other);

    void set_side_a(double width) override;
    void set_side_b(double length) override;
    void setRadius(double radius) override;

    double area() const override;
    double perimeter() const override;
    void display() const override;

private:
    void validateDimensions() const;
};

#endif
