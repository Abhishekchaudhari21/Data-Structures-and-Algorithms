/*
Assignment 7
A student record system is software application used to manage student records including student info.10th,12th
result. Hash table can be used  as a data structure to efficiently store or retrieve student records
*/
#include <iostream>
using namespace std;
int key[20], n;

class studentRecords
{
    int ID;
    string Name;

public:
    void Table();
    void accept();
    void display();
    void search();
    void modify();
} h[50];

void studentRecords::Table()
{
    cout << "Enter No. of records you want to store: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter ID " << i << " : ";
        cin >> key[i];
    }
    for (int i = 0; i < 10; i++)
    {
        h[i].ID = -1;
    }
}

void studentRecords::accept()
{
    int loc;
    for (int i = 0; i < n; i++)
    {
        loc = key[i] % 10;
        if (h[loc].ID == -1)
        {
            cout << "Enter Name for ID " << key[i] << " : ";
            cin >> h[loc].Name;
            h[loc].ID = key[i];
            cout << "Record Added at location " << loc << "." << endl;
        }
        else
        {
            cout << "\nCollision Occured at location " << loc << "!!!" << endl;
            loc = (loc + 1) % 10;
            while (h[loc].ID != -1)
            {
                loc = (loc + 1) % 10;
            }
            cout << "Enter Name for ID " << key[i] << " : ";
            cin >> h[loc].Name;
            h[loc].ID = key[i];
            cout << "Record Added at location " << loc << "." << endl;
        }
    }
}

void studentRecords::display()
{
    cout << "\nStudent Records: \n";
    cout << "Location\tID\tName" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << i << "\t\t" << h[i].ID << "\t" << h[i].Name << endl;
    }
}

void studentRecords::search()
{
    int id, ch;
    bool isFound = false;
    do
    {
        cout << "\nEnter patient ID to search: ";
        cin >> id;
        for (int i = 0; i < 10; i++)
        {
            if (h[i].ID == id)
            {
                isFound = true;
                cout << "\nRecord found at location " << i << ": ID = " << h[i].ID << ", Name = " << h[i].Name << endl;
                break;
            }
        }
        if (!isFound)
        {
            cout << "Record not found!" << endl;
        }
        cout << "\nDo you want to search another record? (Yes-1/No-0): ";
        cin >> ch;
    } while (ch != 0);
}

void studentRecords::modify()
{
    int id, ch;
    bool isFound = false;
    do
    {
        cout << "\nEnter student ID to modify: ";
        cin >> id;
        for (int i = 0; i < 10; i++)
        {
            if (h[i].ID == id)
            {
                isFound = true;
                cout << "\nRecord found at location " << i << ": ID = " << h[i].ID << ", Name = " << h[i].Name << endl;
                cout << "\nEnter new Name for ID " << id << ": ";
                cin >> h[i].Name;
                cout << "Record modified successfully!" << endl;
                break;
            }
        }
        if (!isFound)
        {
            cout << "Record not found!" << endl;
        }

        cout << "\nDo you want to modify another record? (Yes - 1 / No - 0): ";
        cin >> ch;
    } while (ch != 0);
}

int main()
{
    int choice;
    cout << "\n\tStudent Record System\n";
    studentRecords m;
    do
    {
        cout << "\n1. Create Student Records\n2. Display Student Records\n3. Search Student Records\n4. Modify Student Records\n0. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            m.Table();
            m.accept();
            break;
        case 2:
            m.display();
            break;
        case 3:
            m.search();
            break;
        case 4:
            m.modify();
            break;
        case 0:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
        cout << "\nDo you want to continue? (Yes-1/No-0): ";
        cin >> choice;
    } while (choice != 0);
    return 0;
}