#include <iostream>
using namespace std;

class Student {
    string name;
    int roll;
    float marks;
public:
    friend istream& operator>>(istream &in, Student &s);
    friend ostream& operator<<(ostream &out, Student &s);
};

istream& operator>>(istream &in, Student &s) {
    in >> s.name >> s.roll >> s.marks;
    return in;
}

ostream& operator<<(ostream &out, Student &s) {
    out << s.name << " " << s.roll << " " << s.marks << endl;
    return out;
}

int main() {
    Student s;
    cin >> s;
    cout << s;
}
