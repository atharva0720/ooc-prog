#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3};
    list<string> l = {"apple", "banana", "mango"};
    map<int, string> m = {{1, "A"}, {2, "B"}, {3, "C"}};

    cout << "Vector: ";
    for(int x : v) cout << x << " ";
    cout << "\nList: ";
    for(string s : l) cout << s << " ";
    cout << "\nMap:\n";
    for(auto x : m) cout << x.first << " -> " << x.second << endl;
}
