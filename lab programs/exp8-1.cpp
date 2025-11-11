#include <iostream>
using namespace std;

class Number {
    int a;
public:
    Number(int x=0){ a=x; }
    Number operator+(Number n){ return Number(a + n.a); }
    Number operator-(Number n){ return Number(a - n.a); }
    Number operator++(){ return Number(++a); }
    Number operator--(){ return Number(--a); }
    void display(){ cout << a << endl; }
};

int main() {
    Number n1(10), n2(5), n3;
    n3 = n1 + n2;
    n3.display();
    n3 = n1 - n2;
    n3.display();
    ++n1;
    n1.display();
    --n2;
    n2.display();
}
