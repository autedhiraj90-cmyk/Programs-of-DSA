#include<iostream>
using namespace std;

typedef struct student
{
    int roll_num;
    char name[20];
    float marks;
} stud;

void create(stud s[20], int n);
void display(stud s[20], int n);
void search(stud s[20], int n, int key);
void bubble_sort(stud s[20], int n);

int main()
{
    stud s[20];
    int ch, n, key;

    do
    {
        cout << "\n 1) Create Student Database ";
        cout << "\n 2) Display Student Records ";
        cout << "\n 3) Linear Search";
        cout << "\n 4) Bubble Sort ";
        cout << "\n 5) Exit ";
        cout << "\n Enter Your Choice: ";
        cin >> ch;

        switch(ch)
        {
            case 1:
                cout << "\n Enter The Number Of Records: ";
                cin >> n;
                create(s, n);
                break;

            case 2:
                display(s, n);
                break;

            case 3:
                cout << "\n Enter the roll no you want to search: ";
                cin >> key;
                search(s, n, key);
                break;

            case 4:
                bubble_sort(s, n);
                break;

            case 5:
                return 0;

            default:
                cout << "\n Invalid choice\n";
        }

    } while(ch != 5);
}

void create(stud s[20], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        cout << "\n Enter the roll number: ";
        cin >> s[i].roll_num;
        cout << "\n Enter the Name: ";
        cin >> s[i].name;
        cout << "\n Enter the marks: ";
        cin >> s[i].marks;
    }
}

void display(stud s[20], int n)
{
    int i;
    cout << "\n\tRoll No\tName\tMarks";
    for(i = 0; i < n; i++)
    {
        cout << "\n\t" << s[i].roll_num << "\t" << s[i].name << "\t" << s[i].marks;
    }
}

void search(stud s[20], int n, int key)
{
    int i;
    cout << "\n\tRoll No\tName\tMarks";
    for(i = 0; i < n; i++)
    {
        if(key == s[i].roll_num)
        {
            cout << "\n\t" << s[i].roll_num << "\t" << s[i].name << "\t" << s[i].marks;
        }
    }
}

void bubble_sort(stud s[20], int n)
{
    int i, j;
    stud temp;
    for(i = 1; i < n; i++)
    {
        for(j = 0; j < n - 1; j++)
        {
            if(s[j].roll_num > s[j + 1].roll_num)
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}


