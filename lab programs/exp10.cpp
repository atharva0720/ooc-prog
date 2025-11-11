#include <iostream>
using namespace std;

class Shape {
public:
    virtual void area() { }
};

class Circle : public Shape {
    float r;
public:
    Circle(float rad) {
        r = rad;
    }
    void area() {
        cout << "Area of Circle = " << 3.14 * r * r << endl;
    }
};

class Rectangle : public Shape {
    float l, b;
public:
    Rectangle(float len, float bre) {
        l = len;
        b = bre;
    }
    void area() {
        cout << "Area of Rectangle = " << l * b << endl;
    }
};

int main() {
    Shape *s;
    Circle c1(4.5);
    Rectangle r1(5, 7);

    s = &c1;
    s->area();

    s = &r1;
    s->area();

    return 0;
}
