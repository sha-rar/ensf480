/*
* File Name: graphicsWorld.cpp
* Assignment: Lab 3 Exercise A
* Completed By:
*   Sharar Masud, 30205753
* Submission Date: Sept. 28, 2026
*/

#include "graphicsWorld.h"

#include "circle.h"
#include "curveCut.h"
#include "point.h"
#include "rectangle.h"
#include "shape.h"
#include "square.h"

#include <iostream>

using namespace std;

void GraphicsWorld::run()
{
    cout << "Lab 3 - GraphicsWorld\nAuthor: Sharar\n";

#if 1 // Point
    cout << "\nTesting Functions in class Point:" << endl;
    Point m(6, 8);
    Point n(6, 8);
    n.setx(9);
    cout << "Expected to display the distance between m and n is: 3";
    cout << "\nThe distance between m and n is: " << m.distance(n);
    cout << "\nExpected second version of the distance function also print: 3";
    cout << "\nThe distance between m and n is again: "
         << Point::distance(m, n) << endl;
#endif

#if 1 // Square
    cout << "\nTesting Functions in class Square:" << endl;
    Square s(5, 7, 12, "SQUARE - S");
    s.display();
#endif

#if 1 // Rectangle
    cout << "\nTesting Functions in class Rectangle:" << endl;
    Rectangle a(5, 7, 12, 15, "RECTANGLE A");
    a.display();

    Rectangle b(16, 7, 8, 9, "RECTANGLE B");
    b.display();

    double d = a.distance(b);
    cout << "\nDistance between rectangle a and b is: " << d << endl;

    Rectangle rec1 = a;
    rec1.display();

    cout << "\nTesting assignment operator in class Rectangle:" << endl;
    Rectangle rec2(3, 4, 11, 7, "RECTANGLE rec2");
    rec2.display();
    rec2 = a;
    a.set_side_b(200);
    a.set_side_a(100);

    cout << "\nExpected to display the following values for object rec2: " << endl;
    cout << "Rectangle Name: RECTANGLE A\n"
         << "X-coordinate: 5\n"
         << "Y-coordinate: 7\n"
         << "Side a: 12\n"
         << "Side b: 15\n"
         << "Area: 180\n"
         << "Perimeter: 54\n";
    cout << "\nIf it doesn't there is a problem with your assignment operator.\n" << endl;
    rec2.display();

    cout << "\nTesting copy constructor in class Rectangle:" << endl;
    Rectangle rec3(a);
    rec3.display();
    a.set_side_b(300);
    a.set_side_a(400);

    cout << "\nExpected to display the following values for object rec3: " << endl;
    cout << "Rectangle Name: RECTANGLE A\n"
         << "X-coordinate: 5\n"
         << "Y-coordinate: 7\n"
         << "Side a: 100\n"
         << "Side b: 200\n"
         << "Area: 20000\n"
         << "Perimeter: 600\n";
    cout << "\nIf it doesn't there is a problem with your copy constructor.\n" << endl;
    rec3.display();
#endif

#if 1 // Circle and CurveCut
    cout << "\nTesting Functions in class Circle:" << endl;
    Circle c(3, 5, 9, "CIRCLE C");
    c.display();
    cout << "The area of " << c.getName() << " is: " << c.area() << endl;
    cout << "The perimeter of " << c.getName() << " is: " << c.perimeter() << endl;
    cout << "The distance between rectangle a and circle c is: "
         << a.distance(c) << endl;

    cout << "\nTesting Functions in class CurveCut:" << endl;
    CurveCut rc(6, 5, 10, 12, 9, "CurveCut rc");
    rc.display();
    cout << "The area of " << rc.getName() << " is: " << rc.area() << endl;
    cout << "The perimeter of " << rc.getName() << " is: " << rc.perimeter() << endl;
    cout << "The distance between rc and c is: " << rc.distance(c) << endl;
#endif

#if 1 // Array of pointers and polymorphism
    cout << "\nTesting array of Shape pointers and polymorphism:" << endl;
    Shape* sh[4] = {&s, &a, &c, &rc};

    for (Shape* shape : sh) {
        shape->display();
        cout << "The area of " << shape->getName() << " is: "
             << shape->area() << endl;
        cout << "The perimeter of " << shape->getName() << " is: "
             << shape->perimeter() << endl;
    }
#endif

#if 1 // CurveCut copy constructor and assignment operator
    cout << "\nTesting copy constructor in class CurveCut:" << endl;
    CurveCut cc = rc;
    cc.display();

    cout << "\nTesting assignment operator in class CurveCut:" << endl;
    CurveCut cc2(2, 5, 100, 12, 9, "CurveCut cc2");
    cc2.display();
    cc2 = cc;
    cc2.display();
#endif
}
