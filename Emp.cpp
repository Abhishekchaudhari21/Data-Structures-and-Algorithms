#include <iostream>
using namespace std;

class Student
{
public:
    int roll_no;
    string name, add;
    Student *leftChild = NULL, *rightChild = NULL;

    void create();
    void insert(Student *root, Student *next);
    void displayByInOrder(Student *root);
    void displayAllNonrecursive(Student *root);
    void displayLeafNode(Student *root);
    void displayInternalNode(Student *root);
    int displayTreeHeight(Student *root);
    void displayByPreOrder(Student *root);
    void displayByPostOrder(Student *root);
};

Student *root, *nextn, *st[100];
int top = -1;

void Student::create()
{
    root = new Student;
    cout << "Enter Student roll no : ";
    cin >> root->roll_no;
    cout << "Enter Student Name : ";
    cin >> root->name;
    cout << "Enter Student Address : ";
    cin >> root->add;
    root->leftChild = root->rightChild = NULL;

    int ch;
    do
    {
        cout << "Do you want to add another Student?(1/0) : ";
        cin >> ch;
        if (ch == 1)
        {
            nextn = new Student;
            cout << "Enter Student roll no : ";
            cin >> nextn->roll_no;
            cout << "Enter Student Name : ";
            cin >> nextn->name;
            cout << "Enter Student Address : ";
            cin >> nextn->add;
            nextn->leftChild = nextn->rightChild = NULL;
            insert(root, nextn);
        }
        else
        {
            cout << "Exiting...";
            break;
        }
    } while (ch != 0);
}

void Student::insert(Student *root, Student *next)
{
    char chr;
    bool inserted = false;

    while (!inserted)
    {
        cout << "Which side of " << root->name << " do you want to insert? (L/R): ";
        cin >> chr;
        if (chr == 'L' || chr == 'l')
        {
            if (root->leftChild == NULL)
            {
                root->leftChild = next;
                cout << "Student info added succesfully!\n";
                inserted = true;
            }
            else
            {
                insert(root->leftChild, next);
            }
        }
        else if (chr == 'R' || chr == 'r')
        {
            if (root->rightChild == NULL)
            {
                root->rightChild = next;
                cout << "Student info added successfully!\n";
                inserted = true;
                return;
            }
            else
            {
                insert(root->rightChild, next);
            }
        }
        else
        {
            cout << "Invalid choice. Please enter L or R." << endl;
        }
    }
}

void Student::displayByInOrder(Student *root)
{
    cout << "\nStudent_Id\tStudent_Name\tStudent_Address";
    if (root == NULL)
    {
        return;
    }
    else
    {
        displayByInOrder(root->leftChild);
        cout << "\n"
             << root->roll_no << "\t" << root->name << "\t\t" << root->add;
        displayByInOrder(root->rightChild);
    }
    cout << "\n"
         << endl;
}

void Student::displayByPreOrder(Student *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        cout << "\n"
             << root->roll_no << "\t" << root->name << "\t\t" << root->add;
        displayByPreOrder(root->leftChild);
        displayByPreOrder(root->rightChild);
    }
}

void Student::displayByPostOrder(Student *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        displayByPostOrder(root->leftChild);
        displayByPostOrder(root->rightChild);
        cout << "\n"
             << root->roll_no << "\t" << root->name << "\t\t" << root->add;
    }
}

void Student::displayAllNonrecursive(Student *root)
{
    Student *temp;
    temp = root;

    if (root != NULL)
    {
        do
        {
            while (temp != NULL)
            {
                top++;
                st[top] = temp;
                temp = temp->leftChild;
            }

            if (top != -1)
            {
                temp = st[top];
                top--;
                cout << "\n"
                     << temp->roll_no << "\t" << temp->name << "\t" << temp->add << endl;
                temp = temp->rightChild;
            }

        } while (temp != NULL || top != -1);
    }
    else
    {
        cout << "\nNo information added to display!!\nPlease add a node info...\n";
    }
}

void Student::displayLeafNode(Student *root)
{
    Student *temp;
    temp = root;

    if (root != NULL)
    {
        do
        {
            while (temp != NULL)
            {
                top++;
                st[top] = temp;
                temp = temp->leftChild;
            }

            if (top != -1)
            {
                temp = st[top];
                top--;
                if (temp->leftChild == NULL && temp->rightChild == NULL)
                    cout << "\n"
                         << temp->roll_no << "\t" << temp->name << "\t" << temp->add << endl;
                temp = temp->rightChild;
            }

        } while (temp != NULL || top != -1);
    }
    else
    {
        cout << "\nNo information added to display!!\nPlease add a node info...\n";
    }
}

void Student::displayInternalNode(Student *root)
{
    Student *temp;
    temp = root;

    if (root != NULL)
    {
        do
        {
            while (temp != NULL)
            {
                top++;
                st[top] = temp;
                temp = temp->leftChild;
            }

            if (top != -1)
            {
                temp = st[top];
                top--;
                if (temp->leftChild == NULL || temp->rightChild == NULL)
                    cout << "\n"
                         << temp->roll_no << "\t" << temp->name << "\t" << temp->add << endl;
                temp = temp->rightChild;
            }

        } while (temp != NULL || top != -1);
    }
    else
    {
        cout << "\nNo information added to display!!\nPlease add a node info...\n";
    }
}

// TO determine the height of tree
int Student::displayTreeHeight(Student *root)
{
    int leftHeight = 0, rightHeight = 0, finalHeight = 0;
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        leftHeight = displayTreeHeight(root->leftChild);
        rightHeight = displayTreeHeight(root->rightChild);

        if (leftHeight > rightHeight)
        {
            finalHeight = leftHeight + 1;
        }
        else
        {
            finalHeight = rightHeight + 1;
        }
        return finalHeight - 1;
    }
}

int main()
{
    int ch;
    Student student;
    while (ch != 10)
    {
        cout << "\nMain\n1. Create a node\n2. Display all nodes by recursive method\n3. Display all nodes by non-recursive method\n4. Display leaf nodes\n";
        cout << "5. Display internal nodes\n6. Display Root node\n7. Display Height of the tree\n8. Display all nodes by Preorder\n 9. Display all nodes by Postorder\n10. Exit\nEnter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            student.create();
            break;
        case 2:
            student.displayByInOrder(root);
            break;
        case 3:
            student.displayAllNonrecursive(root);
            break;
        case 4:
            student.displayLeafNode(root);
            break;
        case 5:
            student.displayInternalNode(root);
            break;
        case 6:
            if (root == NULL)
            {
                return 1;
            }
            else
            {
                cout << "\n"
                     << root->roll_no << "\t" << root->name << "\t" << root->add;
            }
            break;
        case 7:
            student.displayTreeHeight(root);
            break;
        case 8:
            cout << "Exiting....";
            break;
        default:
            break;
        }
    }
    return 0;
}
