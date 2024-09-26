#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class student {
public:
    struct stud {
        char name[20], course[20], address[50], clg[30], scholar[30];
        int roll_no;
        long long int contact_no;
    } a;

public:
    void menu();
    void insert();
    void display();
    void update();
    void search();
    void deletes();
};

void student::menu() {
    int choice;
    char x;
    do {
        system("CLS");
        cout << "\t\t\t-----------------------------" << endl;
        cout << "\t\t\t| STUDENT MANAGEMENT SYSTEM |" << endl;
        cout << "\t\t\t-----------------------------" << endl;
        cout << "\t\t\t 1. Enter New Record" << endl;
        cout << "\t\t\t 2. Display Record" << endl;
        cout << "\t\t\t 3. Update Record" << endl;
        cout << "\t\t\t 4. Search Record" << endl;
        cout << "\t\t\t 5. Delete Record" << endl;
        cout << "\t\t\t 6. Exit" << endl;

        cout << "\t\t\tChoose Option [1/2/3/4/5/6]: ";
        cin >> choice;

        switch (choice) {
        case 1:
            do {
                insert();
                cout << "\n\t\t\tAdd Another Student Record (Y/N): ";
                cin >> x;
            } while (x == 'y' || x == 'Y');
            break;
        case 2:
            display();
            char dd;
            cout<<"Click y to contuinuce";
            cin>>dd;
            if(dd=='y'||dd=='Y')
            {
                cout<<"ok";
            }
            
           cin.get(); // Wait for input before clearing the screen
            break;
        case 3:
            update();
            cin.get();
            break;
        case 4:
            search();
            cin.get();
            break;
        case 5:
            deletes();
            cin.get();
            break;
        case 6:
            exit(0);
        default:
            cout << "\n\t\t\tInvalid Choice...Enter Again!";
            break;
        }
    } while (choice != 6);
}

void student::insert() {
    fstream file;
    char ch;

    cout << "------------------------------------- Add Student Details ---------------------------------------------" << endl;
    cin.ignore();
    cout << "\t\t\tEnter Name: ";
    cin.getline(a.name, 20);
    cout << "\t\t\tEnter Roll No.: ";
    cin >> a.roll_no;
    cin.ignore();
    cout << "\t\t\tEnter Course: ";
    cin.getline(a.course, 20);
    cout << "\t\t\tEnter Address: ";
    cin.getline(a.address, 50);
    cout << "\t\t\tEnter College Name: ";
    cin.getline(a.clg, 30);
    cout << "\t\t\tEnter Contact No.: ";
    cin >> a.contact_no;
    cin.ignore();

    cout << "\t\t\tDo you want to apply for a scholarship (Y/N): ";
    cin >> ch;
    cin.ignore();
    if (ch == 'y' || ch == 'Y') {
        cout << "\t\t\tEnter Scholarship Name: ";
        cin.getline(a.scholar, 30);
        cout << "\t\t\tYou have successfully applied for the scholarship!" << endl;
    } else {
        strcpy(a.scholar, "None");
    }

    file.open("exp.txt", ios::app | ios::binary);
    file.write((char *)&a, sizeof(a));
    file.close();
}

void student::display() {
    stud s;
    fstream file;
    file.open("exp.txt", ios::in | ios::binary);
    if (!file) {
        cout << "\n\t\tNo data found!";
    } else {
        cout << "------------------------------------- Student Record Table --------------------------------------------" << endl;
        while (file.read((char *)&s, sizeof(s))) {
            cout << "\t\t\tName: " << s.name << endl;
            cout << "\t\t\tRoll No.: " << s.roll_no << endl;
            cout << "\t\t\tCourse: " << s.course << endl;
            cout << "\t\t\tContact No.: " << s.contact_no << endl;
            cout << "\t\t\tAddress: " << s.address << endl;
            cout << "\t\t\tScholarship Applied: " << s.scholar << endl << endl;
        }
    }
    file.close();
}

void student::search() {
    stud s;
    char name[20];
    int roll;
    bool found = false;

    cout << "\n\t\tEnter Name: ";
    cin.ignore();
    cin.getline(name, 20);
    cout << "\t\tEnter Roll No.: ";
    cin >> roll;

    fstream file;
    file.open("exp.txt", ios::in | ios::binary);
    if (!file) {
        cout << "\n\t\tNo data found!";
    } else {
        while (file.read((char *)&s, sizeof(s))) {
            if (strcmp(name, s.name) == 0 && s.roll_no == roll) {
                cout << "\n\t\tName: " << s.name << endl;
                cout << "\n\t\tRoll No.: " << s.roll_no << endl;
                cout << "\n\t\tCourse: " << s.course << endl;
                cout << "\n\t\tContact No.: " << s.contact_no << endl;
                cout << "\n\t\tAddress: " << s.address << endl;
                cout << "\n\t\tScholarship Applied: " << s.scholar << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "\n\t\tNo record found!";
        }
    }
    file.close();
}

void student::update() {
    stud s;
    char name[20];
    int roll;
    bool found = false;

    cout << "\n\t\tEnter Name to Update: ";
    cin.ignore();
    cin.getline(name, 20);
    cout << "\t\tEnter Roll No.: ";
    cin >> roll;

    fstream file, temp;
    file.open("exp.txt", ios::in | ios::binary);
    temp.open("temp.txt", ios::out | ios::binary);

    if (!file) {
        cout << "\n\t\tNo data found!";
    } else {
        while (file.read((char *)&s, sizeof(s))) {
            if (strcmp(name, s.name) == 0 && s.roll_no == roll) {
                cout << "\n\t\tEnter New Details" << endl;
                cout << "\t\t\tEnter Name: ";
                cin.ignore();
                cin.getline(a.name, 20);
                cout << "\t\t\tEnter Roll No.: ";
                cin >> a.roll_no;
                cin.ignore();
                cout << "\t\t\tEnter Course: ";
                cin.getline(a.course, 20);
                cout << "\t\t\tEnter Address: ";
                cin.getline(a.address, 50);
                cout << "\t\t\tEnter College Name: ";
                cin.getline(a.clg, 30);
                cout << "\t\t\tEnter Contact No.: ";
                cin >> a.contact_no;
                cin.ignore();
                cout << "\t\t\tDo you want to apply for a scholarship (Y/N): ";
                char ch;
                cin >> ch;
                cin.ignore();
                if (ch == 'y' || ch == 'Y') {
                    cout << "\t\t\tEnter Scholarship Name: ";
                    cin.getline(a.scholar, 30);
                } else {
                    strcpy(a.scholar, "None");
                }
                temp.write((char *)&a, sizeof(a));
                found = true;
            } else {
                temp.write((char *)&s, sizeof(s));
            }
        }
        file.close();
        temp.close();
        remove("exp.txt");
        rename("temp.txt", "exp.txt");

        if (found) {
            cout << "\n\t\tRecord updated successfully!";
        } else {
            cout << "\n\t\tRecord not found!";
        }
    }
}

void student::deletes() {
    stud s;
    char name[20];
    int roll;
    bool found = false;

    cout << "\n\t\tEnter Name to Delete: ";
    cin.ignore();
    cin.getline(name, 20);
    cout << "\t\tEnter Roll No.: ";
    cin >> roll;

    fstream file, temp;
    file.open("exp.txt", ios::in | ios::binary);
    temp.open("temp.txt", ios::out | ios::binary);

    if (!file) {
        cout << "\n\t\tNo data found!";
    } else {
        while (file.read((char *)&s, sizeof(s))) {
            if (strcmp(name, s.name) != 0 || s.roll_no != roll) {
                temp.write((char *)&s, sizeof(s));
            } else {
                found = true;
            }
        }
        file.close();
        temp.close();
        remove("exp.txt");
        rename("temp.txt", "exp.txt");

        if (found) {
            cout << "\n\t\tRecord deleted successfully!";
        } else {
            cout << "\n\t\tRecord not found!";
        }
    }
}

int main() {
    student s1;
    s1.menu();
    return 0;
}
