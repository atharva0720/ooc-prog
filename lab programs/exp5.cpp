#include <iostream>
using namespace std;

class Shape {
public:
    float area(float radius) {
        return 3.14 * radius * radius;
    }

    float area(float length, float breadth) {
        return length * breadth;
    }

    float areaTriangle(float base, float height) {
        return 0.5 * base * height;
    }
};

int main() {
    Shape s;
    float r, l, b, base, h;

    cout << "Enter radius of circle: ";
    cin >> r;
    cout << "Area of Circle: " << s.area(r) << endl;

    cout << "\nEnter length and breadth of rectangle: ";
    cin >> l >> b;
    cout << "Area of Rectangle: " << s.area(l, b) << endl;

    cout << "\nEnter base and height of triangle: ";
    cin >> base >> h;
    cout << "Area of Triangle: " << s.areaTriangle(base, h) << endl;

    return 0;
}
