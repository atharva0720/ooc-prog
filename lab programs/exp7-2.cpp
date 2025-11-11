#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    void getPersonData() {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
    }
};

class Student : public Person {
protected:
    int rollNo;
    string course;
public:
    void getStudentData() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cout << "Enter Course Name: ";
        cin.ignore();
        getline(cin, course);
    }
};

class Marks {
protected:
    float m1, m2, m3;
public:
    void getMarks() {
        cout << "Enter Marks for 3 Subjects: ";
        cin >> m1 >> m2 >> m3;
    }
};

class Result : public Student, public Marks {
    float total, avg;
public:
    void displayResult() {
        total = m1 + m2 + m3;
        avg = total / 3;
        cout << "\n--- Student Result ---";
        cout << "\nName: " << name;
        cout << "\nAge: " << age;
        cout << "\nRoll No: " << rollNo;
        cout << "\nCourse: " << course;
        cout << "\nMarks: " << m1 << ", " << m2 << ", " << m3;
        cout << "\nTotal: " << total;
        cout << "\nAverage: " << avg << endl;
    }
};

int main() {
    Result r;
    r.getPersonData();
    r.getStudentData();
    r.getMarks();
    r.displayResult();
    return 0;
}
