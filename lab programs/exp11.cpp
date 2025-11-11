#include <iostream>
using namespace std;

class Employee {
public:
    virtual void calculateSalary() { }
};

class SalariedEmployee : public Employee {
    float salary;
public:
    SalariedEmployee(float s) { salary = s; }
    void calculateSalary() { cout << "Salary = " << salary << endl; }
};

class HourlyEmployee : public Employee {
    int hours;
    float rate;
public:
    HourlyEmployee(int h, float r) { hours = h; rate = r; }
    void calculateSalary() { cout << "Salary = " << hours * rate << endl; }
};

class CommissionedEmployee : public Employee {
    float sales, commission;
public:
    CommissionedEmployee(float s, float c) { sales = s; commission = c; }
    void calculateSalary() { cout << "Salary = " << sales * commission << endl; }
};

int main() {
    Employee *e;
    SalariedEmployee s(25000);
    HourlyEmployee h(40, 200);
    CommissionedEmployee c(50000, 0.1);

    e = &s;
    e->calculateSalary();
    e = &h;
    e->calculateSalary();
    e = &c;
    e->calculateSalary();
}
