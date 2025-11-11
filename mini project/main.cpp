#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class Hotel {
private:
    int room_no;
    string name, address, phone;
    int days;
    float rent;

public:
    void mainMenu();
    void checkIn();
    void displayAll();
    void searchRoom();
    void modifyRoom();
    void checkOut();
};

void Hotel::mainMenu() {
    int choice;
    while (true) {
        cout << "\n========== HOTEL MANAGEMENT SYSTEM ==========\n";
        cout << "1. Check-In (Add Customer)\n";
        cout << "2. Display All Customers\n";
        cout << "3. Search Customer by Room\n";
        cout << "4. Modify Customer Record\n";
        cout << "5. Check-Out (Delete Record)\n";
        cout << "6. Exit\n";
        cout << "---------------------------------------------\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: checkIn(); break;
            case 2: displayAll(); break;
            case 3: searchRoom(); break;
            case 4: modifyRoom(); break;
            case 5: checkOut(); break;
            case 6: exit(0);
            default: cout << "\nInvalid choice. Try again.\n";
        }
    }
}

void Hotel::checkIn() {
    ofstream fout("hotel.txt", ios::app);
    cout << "\nEnter Room No: ";
    cin >> room_no;
    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Address: ";
    getline(cin, address);
    cout << "Enter Phone Number: ";
    getline(cin, phone);
    cout << "Enter Number of Days: ";
    cin >> days;

    rent = days * 1500.0;

    fout << "Room No: " << room_no << endl;
    fout << "Name: " << name << endl;
    fout << "Address: " << address << endl;
    fout << "Phone: " << phone << endl;
    fout << "Days: " << days << endl;
    fout << "Rent: " << rent << endl;
    fout << "-------------------------------" << endl;

    fout.close();
    cout << "\nCustomer Checked In Successfully!\n";
}

void Hotel::displayAll() {
    ifstream fin("hotel.txt");
    if (!fin) {
        cout << "\nNo records found!\n";
        return;
    }

    cout << "\n========= All Customer Records =========\n\n";
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }
    fin.close();
}

void Hotel::searchRoom() {
    ifstream fin("hotel.txt");
    if (!fin) {
        cout << "\nNo records found!\n";
        return;
    }

    int r;
    cout << "\nEnter Room Number to Search: ";
    cin >> r;

    string line;
    bool found = false;

    while (getline(fin, line)) {
        if (line.find("Room No:") != string::npos) {
            int room = stoi(line.substr(9));
            if (room == r) {
                cout << "\n--- Customer Found ---\n";
                cout << line << endl;
                for (int i = 0; i < 6 && getline(fin, line); ++i)
                    cout << line << endl;
                found = true;
                break;
            }
        }
    }
    if (!found)
        cout << "\nRoom not found!\n";
    fin.close();
}

void Hotel::modifyRoom() {
    ifstream fin("hotel.txt");
    ofstream fout("temp.txt");

    if (!fin) {
        cout << "\nNo records found!\n";
        return;
    }

    int r;
    cout << "\nEnter Room Number to Modify: ";
    cin >> r;

    string line;
    bool found = false;
    while (getline(fin, line)) {
        if (line.find("Room No:") != string::npos) {
            int room = stoi(line.substr(9));
            if (room == r) {
                found = true;
                cin.ignore();
                cout << "\nEnter New Name: ";
                getline(cin, name);
                cout << "Enter New Address: ";
                getline(cin, address);
                cout << "Enter New Phone: ";
                getline(cin, phone);
                cout << "Enter New Days: ";
                cin >> days;
                rent = days * 1500.0;

                fout << "Room No: " << room_no << endl;
                fout << "Name: " << name << endl;
                fout << "Address: " << address << endl;
                fout << "Phone: " << phone << endl;
                fout << "Days: " << days << endl;
                fout << "Rent: " << rent << endl;
                fout << "-------------------------------" << endl;

        
                for (int i = 0; i < 6; ++i)
                    getline(fin, line);
            } else {
                fout << line << endl;
            }
        } else {
            fout << line << endl;
        }
    }

    fin.close();
    fout.close();

    remove("hotel.txt");
    rename("temp.txt", "hotel.txt");

    if (found)
        cout << "\nRecord Updated Successfully!\n";
    else
        cout << "\nRoom not found!\n";
}

void Hotel::checkOut() {
    ifstream fin("hotel.txt");
    ofstream fout("temp.txt");

    if (!fin) {
        cout << "\nNo records found!\n";
        return;
    }

    int r;
    cout << "\nEnter Room Number for Checkout: ";
    cin >> r;

    string line;
    bool found = false;
    while (getline(fin, line)) {
        if (line.find("Room No:") != string::npos) {
            int room = stoi(line.substr(9));
            if (room == r) {
                found = true;
                cout << "\nRoom " << room << " Checked Out Successfully!\n";

                // Skip next 6 lines of that record
                for (int i = 0; i < 6; ++i)
                    getline(fin, line);
            } else {
                fout << line << endl;
            }
        } else {
            fout << line << endl;
        }
    }

    fin.close();
    fout.close();

    remove("hotel.txt");
    rename("temp.txt", "hotel.txt");

    if (!found)
        cout << "\nRoom not found!\n";
}

int main() {
    Hotel h;
    h.mainMenu();
    return 0;
}
