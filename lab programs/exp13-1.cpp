#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    try {
        if(b == 0)
            throw b;
        cout << "Division = " << a / b << endl;
    }
    catch(int) {
        cout << "Error: Division by zero not allowed." << endl;
    }

    return 0;
}
