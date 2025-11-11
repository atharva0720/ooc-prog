#include <iostream>
using namespace std;

class InvalidAgeException { };

class Person {
    int age;
public:
    void input() {
        cout << "Enter age: ";
        cin >> age;
        try {
            if(age < 0 || age > 120)
                throw InvalidAgeException();
            cout << "Valid age entered: " << age << endl;
        }
        catch(InvalidAgeException) {
            cout << "Invalid Age!" << endl;
        }
    }
};

int main() {
    Person p;
    p.input();
    return 0;
}
