#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
    int rollNo;
    string name;
public:
    void getStudentData() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
    }
};

class Marks {
protected:
    float m1, m2, m3;
public:
    void getMarksData() {
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
        cout << "\nRoll No: " << rollNo;
        cout << "\nName: " << name;
        cout << "\nMarks: " << m1 << ", " << m2 << ", " << m3;
        cout << "\nTotal: " << total;
        cout << "\nAverage: " << avg << endl;
    }
};

int main() {
    Result r;
    r.getStudentData();
    r.getMarksData();
    r.displayResult();
    return 0;
}
