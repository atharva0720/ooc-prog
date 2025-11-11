#include <iostream>
using namespace std;

class Number {
    int a;
public:
    Number(int x=0){ a=x; }
    bool operator>(Number n){ return a > n.a; }
    bool operator<(Number n){ return a < n.a; }
    bool operator==(Number n){ return a == n.a; }
    bool operator!=(Number n){ return a != n.a; }
    bool operator>=(Number n){ return a >= n.a; }
    bool operator<=(Number n){ return a <= n.a; }
};

int main() {
    Number n1(10), n2(20);
    if(n1 > n2) cout << "n1 is greater\n";
    if(n1 < n2) cout << "n1 is smaller\n";
    if(n1 != n2) cout << "n1 not equal n2\n";
}
