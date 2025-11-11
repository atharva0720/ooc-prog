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
    void displayStudentData() {
        cout << "\nRoll No: " << rollNo;
        cout << "\nName: " << name;
    }
};

class Test : public Student {
protected:
    float marks1, marks2;
public:
    void getTestData() {
        cout << "Enter Marks of Subject 1: ";
        cin >> marks1;
        cout << "Enter Marks of Subject 2: ";
        cin >> marks2;
    }
    void displayTestData() {
        cout << "\nMarks 1: " << marks1;
        cout << "\nMarks 2: " << marks2;
    }
};

class Result : public Test {
public:
    void displayResult() {
        float total = marks1 + marks2;
        float avg = total / 2;
        displayStudentData();
        displayTestData();
        cout << "\nTotal Marks: " << total;
        cout << "\nAverage: " << avg << "\n";
    }
};

int main() {
    Result r;
    r.getStudentData();
    r.getTestData();
    r.displayResult();
    return 0;
}
