#include <iostream>
#include <string>
using namespace std;

class LibraryItem {
protected:
    string title;
    string author;
    int year;
public:
    void setData(string t, string a, int y) {
        title = t;
        author = a;
        year = y;
    }
    void display() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << year << endl;
    }
};

class Book : public LibraryItem {
    int pages;
public:
    void setBook(string t, string a, int y, int p) {
        setData(t, a, y);
        pages = p;
    }
    void showBook() {
        cout << "\n--- Book Details ---" << endl;
        display();
        cout << "Pages: " << pages << endl;
    }
};

class Magazine : public LibraryItem {
    int issueNumber;
public:
    void setMagazine(string t, string a, int y, int issue) {
        setData(t, a, y);
        issueNumber = issue;
    }
    void showMagazine() {
        cout << "\n--- Magazine Details ---" << endl;
        display();
        cout << "Issue Number: " << issueNumber << endl;
    }
};

int main() {
    Book b;
    b.setBook("Software Developemt", "Atharva", 2024, 197);
    b.showBook();

    Magazine m;
    m.setMagazine("c++", "Sudharshan", 2024, 11);
    m.showMagazine();
    return 0;
}
