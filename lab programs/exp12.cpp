#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream fout("data.txt");
    string name;
    int age;
    cout << "Enter name and age: ";
    cin >> name >> age;
    fout << "Name: " << name << "\nAge: " << age << endl;
    fout.close();

    ifstream fin("data.txt");
    string line;
    cout << "\nReading from file:\n";
    while(getline(fin, line)) {
        cout << line << endl;
    }
    fin.close();
    return 0;
}
