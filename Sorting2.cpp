#include <iostream>
#include <string>
using namespace std;

typedef struct student {
    int rollno;
    string name;
    float marks;
} stud;

void Create(stud s[10], int n);
void Display(stud s[10], int n);
void Search(stud s[10], int n, int key);
void Binary(stud s[10], int n, int key);
void Bubble(stud s[10], int n);
void Selection(stud s[10], int n);

int main() {
    stud s[10];
    int ch, n = 0, key;

    do {
        cout << "\n\n--- MENU ---";
        cout << "\n1) Create";
        cout << "\n2) Display";
        cout << "\n3) Search (Linear)";
        cout << "\n4) Search (Binary)";
        cout << "\n5) Bubble Sort";
        cout << "\n6) Selection Sort";
        cout << "\n7) Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "\nEnter number of students (max 10): ";
                cin >> n;
                Create(s, n);
                break;
            case 2:
                Display(s, n);
                break;
            case 3:
                cout << "\nEnter roll number to search: ";
                cin >> key;
                Search(s, n, key);
                break;
            case 4:
                cout << "\nEnter roll number to search (Binary): ";
                cin >> key;
                Binary(s, n, key);
                break;
            case 5:
                Bubble(s, n);
                break;
            case 6:
                Selection(s, n);
                break;
            case 7:
                cout << "\nExiting program...";
                break;
            default:
                cout << "\nInvalid choice!";
        }
    } while (ch != 7);

    return 0;
}

void Create(stud s[10], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nEnter Roll No: ";
        cin >> s[i].rollno;
        cout << "Enter Name: ";
        cin >> s[i].name;
        cout << "Enter Marks: ";
        cin >> s[i].marks;
    }
}

void Display(stud s[10], int n) {
    cout << "\nRoll No\tName\tMarks";
    for (int i = 0; i < n; i++) {
        cout << "\n" << s[i].rollno << "\t" << s[i].name << "\t" << s[i].marks;
    }
    cout << endl;
}

void Search(stud s[10], int n, int key) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (key == s[i].rollno) {
            cout << "\nRecord Found:\n";
            cout << s[i].rollno << "\t" << s[i].name << "\t" << s[i].marks << endl;
            found = true;
            break;
        }
    }
    if (!found)
        cout << "\nRecord not found!" << endl;
}

void Binary(stud s[10], int n, int key) {
    Bubble(s, n);  // sort before binary search
    int start = 0, end = n - 1;
    bool found = false;

    while (start <= end) {
        int mid = (start + end) / 2;
        if (key == s[mid].rollno) {
            cout << "\nRecord Found:\n";
            cout << s[mid].rollno << "\t" << s[mid].name << "\t" << s[mid].marks << endl;
            found = true;
            break;
        } else if (key > s[mid].rollno)
            start = mid + 1;
        else
            end = mid - 1;
    }

    if (!found)
        cout << "\nRecord not found!" << endl;
}

void Bubble(stud s[10], int n) {
    stud temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].rollno > s[j + 1].rollno) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
    cout << "\nAfter Bubble Sort (by Roll No):";
    Display(s, n);
}

void Selection(stud s[10], int n) {
    stud temp;
    for (int i = 0; i < n - 1; i++) {
        int minidx = i;
        for (int j = i + 1; j < n; j++) {
            if (s[j].rollno < s[minidx].rollno)
                minidx = j;
        }
        temp = s[i];
        s[i] = s[minidx];
        s[minidx] = temp;
    }
    cout << "\nAfter Selection Sort (by Roll No):";
    Display(s, n);
}
