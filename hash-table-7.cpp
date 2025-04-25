#include <iostream>
using namespace std;

int key[20], n, chain[20];

class studentRecords
{
    int ID, change;
    string Name;

public:
    void Table();
    void accept();
    void display();
    void search();
    void modify();
    void deleteRecord();
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
        h[i].change = -1;
    }
}

void studentRecords::accept()
{
    int loc, ch;
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
            cout << "\nCollision Occurred at location " << loc << " !!!" << endl;
            loc = (loc + 1) % 10;
            while (h[loc].ID != -1)
            {
                loc = (loc + 1) % 10;
            }
            cout << "Enter Name for ID " << key[i] << " : ";
            cin >> h[loc].Name;
            h[loc].ID = key[i];
            cout << "Record Added at location " << loc << "." << endl;
            h[i].change = loc;
            chain[i] = loc;
        }
    }
}

void studentRecords::display()
{
    cout << "\nStudent Records: \n";
    cout << "Location\tID\tName\t\tChange " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << i << "\t\t" << h[i].ID << "\t" << h[i].Name << "\t\t" << h[i].change << endl;
    }
}

void studentRecords::search()
{
    int id, ch;
    bool isFound = false;
    do
    {
        cout << "\nEnter student ID to search: ";
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

void studentRecords::deleteRecord()
{
    int id, ch;
    bool isFound = false;
    do
    {
        cout << "\nEnter student ID to delete: ";
        cin >> id;

        int delLoc = -1;
        for (int i = 0; i < 10; i++)
        {
            if (h[i].ID == id)
            {
                isFound = true;
                delLoc = i;
                cout << "\nRecord found at location " << delLoc << ": ID = " << h[delLoc].ID << ", Name = " << h[delLoc].Name << endl;

                // Delete record
                h[delLoc].ID = -1;
                h[delLoc].Name = "";
                h[delLoc].change = -1;
                cout << "Record deleted successfully!" << endl;

                break;
            }
        }

        if (!isFound)
        {
            cout << "Record not found!" << endl;
        }
        else
        {
            // Resolve collisions and maintain chain properly
            for (int i = 0; i < 10; i++)
            {
                if (h[i].change == delLoc)
                {
                    int correctLoc = key[i] % 10;

                    if (h[correctLoc].ID == -1) // If original spot is empty, move it back
                    {
                        h[correctLoc].ID = h[i].ID;
                        h[correctLoc].Name = h[i].Name;
                        h[i].ID = -1;
                        h[i].Name = "";
                        h[i].change = -1;
                        chain[i] = -1;
                        cout << "Record moved to its original location at " << correctLoc << endl;
                    }
                    else
                    {
                        // Update chain properly
                        h[i].change = h[i].change == delLoc ? -1 : h[i].change;
                    }
                }
            }
        }

        cout << "\nDo you want to delete another record? (Yes - 1 / No - 0): ";
        cin >> ch;
    } while (ch != 0);
}

int main()
{
    int choice;
    cout << "\n\tStudent Record System\n";
    studentRecords m;
    while (choice != 6)
    {
        cout << "\n1. Create Student Records\n2. Display Student Records\n3. Search Student Records\n4. Modify Student Records\n5. Delete Student Record\n6. Exit the program\nEnter your choice: ";
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
        case 5:
            m.deleteRecord();
            break;
        case 6:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}
