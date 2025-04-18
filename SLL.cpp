#include <iostream>
using namespace std;

class Employee
{
    string name, id;
    Employee *next;
    static Employee *start;

public:
    void accept();
    void displayAll();
    void search();

}E;

Employee *Employee::start = NULL;

void Employee::accept()
{
    Employee *newnode = new Employee;
    cout << "Enter the employee ID and name: ";
    cin >> newnode->id >> newnode->name;
    newnode->next = NULL;
    if (start == NULL)
    {
        start = newnode; // First node
    }
    else
    {
        Employee *temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    cout << "Employee added successfully.\n";
}

void Employee::displayAll()
{
    Employee *temp = start;
    if (start == NULL)
    {
        cout << "\nNo records to show.\n";
        return;
    }
    cout << "\nEmployee Records:\n";
    while (temp != NULL)
    {
        cout << temp->id << "\t" << temp->name << "\n";
        temp = temp->next;
    }
}

void Employee::search()
{
    if (start == NULL)
    {
        cout << "\nNo any records to search...\n";
    }


    string name;
    cout << "Enter Employee id or name: ";
    cin >> name;

    Employee *temp = start;
    while (temp != NULL)
    {
        if (temp->name == name || temp->id == name)
        {
            cout << "\nEmployee found:\n";
            cout << "ID: " << temp->id << "\tName: " << temp->name << "\n";
            return;
        }
            temp = temp->next;
    }
    cout << "\nEmployee not found.\n"; 
}

int main()
{
    int ch;
    while (true)
    {
        cout << "\n----MENU----\n1. Accept Employee info\n2. Disaplay Employee info\n3. Search an employee info\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            E.accept();
            break;
        case 2:
            E.displayAll();
            break;
        case 3:
            E.search();
            break;
        case 4:
            cout << "Exiting program. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}




