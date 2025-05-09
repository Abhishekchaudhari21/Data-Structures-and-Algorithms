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
    int loc;
    for (int i = 0; i < n; i++)
    {
        loc = key[i] % 10;  // Calculate original hashed location

        if (h[loc].ID == -1)  // If the location is free, insert normally
        {
            cout << "Enter Name for ID " << key[i] << " : ";
            cin >> h[loc].Name;
            h[loc].ID = key[i];
            chain[loc] = -1;  // No collision
            cout << "Record Added at location " << loc << "." << endl;
        }
        else
        {
            cout << "\nCollision Occurred at location " << loc << " !!!" << endl;
            int newLoc = (loc + 1) % 10;

            // Find next available position
            while (h[newLoc].ID != -1)
            {
                newLoc = (newLoc + 1) % 10;
            }

            cout << "Enter Name for ID " << key[i] << " : ";
            cin >> h[newLoc].Name;
            h[newLoc].ID = key[i];
            cout << "Record Added at location " << newLoc << "." << endl;

            // Update change field at the original location
            chain[loc] = newLoc;
            h[loc].change = newLoc;
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

                // Delete the record
                h[delLoc].ID = -1;
                h[delLoc].Name = "";
                h[delLoc].change = -1;
                chain[delLoc] = -1;
                cout << "Record deleted successfully!" << endl;

                // Check if the deleted location had a chained element
                int movedLoc = chain[delLoc];
                while (movedLoc != -1)  // Process every displaced entry
                {
                    int expectedLoc = key[movedLoc] % 10;

                    if (h[expectedLoc].ID == -1) // Move back to expected position if free
                    {
                        h[expectedLoc].ID = h[movedLoc].ID;
                        h[expectedLoc].Name = h[movedLoc].Name;
                        h[expectedLoc].change = chain[movedLoc];  // Preserve chain links

                        // Clear old location
                        h[movedLoc].ID = -1;
                        h[movedLoc].Name = "";
                        h[movedLoc].change = -1;
                        chain[movedLoc] = -1;

                        cout << "Record restored to original location: " << expectedLoc << endl;
                    }
                    else
                    {
                        cout << "Expected location occupied, chain maintained.\n";
                    }

                    movedLoc = chain[movedLoc]; // Move to next in chain
                }
                break;
            }
        }

        if (!isFound)
        {
            cout << "Record not found!" << endl;
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
