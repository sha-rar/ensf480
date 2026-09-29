/*
* File Name: point.h
* Assignment: Lab 3 Exercise A
* Completed By:
*   Sharar Masud, 30205753
* Submission Date: Sept. 28, 2026
*/

#ifndef POINT_H
#define POINT_H

class Point {
public:
    Point(double x, double y);
    Point(const Point& other);
    Point& operator=(const Point& other);
    ~Point();

    double getx() const;
    double gety() const;
    int getid() const;

    void setx(double x);
    void sety(double y);

    void display() const;

    static int counter();

    double distance(const Point& other) const;
    static double distance(const Point& first, const Point& second);

private:
    double x;
    double y;
    int id;

    static int objectCount;
    static int nextId;
};

#endif
