#include <iostream>
#include <stack>
using namespace std;

class SMS
{
    string name, email, address;
    int prn, cet;
    SMS *lc, *rc;

public:
    SMS() : lc(NULL), rc(NULL) {}
    void accept(SMS *&root);
    void insert(SMS *&root, SMS *next);
    void displayAll(SMS *root);
    void displayIIT(SMS *root);
    void displayNonIIT(SMS *root);
    int height(SMS *root);
    void mirror(SMS *root);
    int countNodes(SMS *root);
    void search(SMS *root, int prn);
    void update(SMS *root, int prn);
    void displayAncestors(SMS *root, int prn);
    void lowestScore(SMS *root);
    void topper(SMS *root);
};

// Function to accept student details
void SMS::accept(SMS *&root)
{
    SMS *newNode = new SMS();
    cout << "Enter name: ";
    cin >> newNode->name;
    cout << "Enter email: ";
    cin >> newNode->email;
    cout << "Enter address: ";
    cin >> newNode->address;
    cout << "Enter PRN: ";
    cin >> newNode->prn;
    cout << "Enter CET score: ";
    cin >> newNode->cet;
    insert(root, newNode);
}

// Function to insert a node into the BST
void SMS::insert(SMS *&root, SMS *next)
{
    if (root == NULL)
    {
        root = next; // Insert the first node
    }
    else if (next->cet < root->cet)
    {
        if (root->lc == NULL)
        {
            root->lc = next;
        }
        else
        {
            insert(root->lc, next);
        }
    }
    else
    {
        if (root->rc == NULL)
        {
            root->rc = next;
        }
        else
        {
            insert(root->rc, next);
        }
    }
}

// Function to display all students (iterative in-order traversal)
void SMS::displayAll(SMS *root)
{
    if (!root)
    {
        cout << "No students to display." << endl;
        return;
    }
    stack<SMS *> s;
    SMS *current = root;
    cout << "\nName\t\tEmail\t\tAddress\t\tPRN\t\tCET Score" << endl;
    while (current != NULL || !s.empty())
    {
        while (current != NULL)
        {
            s.push(current);
            current = current->lc;
        }
        current = s.top();
        s.pop();
        cout << current->name << "\t\t" << current->email << "\t\t" << current->address << "\t\t" << current->prn << "\t\t" << current->cet << endl;
        current = current->rc;
    }
}

// Function to display IIT students (CET > 90)
void SMS::displayIIT(SMS *root)
{
    if (!root)
    {
        cout << "No students to display." << endl;
        return;
    }
    stack<SMS *> s;
    SMS *current = root;
    cout << "Name\tEmail\tAddress\tPRN\tCET Score" << endl;
    while (current != NULL || !s.empty())
    {
        while (current != NULL)
        {
            s.push(current);
            current = current->lc;
        }
        current = s.top();
        s.pop();
        if (current->cet > 90)
            cout << current->name << "\t" << current->email << "\t" << current->address << "\t" << current->prn << "\t" << current->cet << endl;
        current = current->rc;
    }
}

// Function to display non-IIT students (CET <= 90)
void SMS::displayNonIIT(SMS *root)
{
    if (!root)
    {
        cout << "No students to display." << endl;
        return;
    }
    stack<SMS *> s;
    SMS *current = root;
    cout << "Name\tEmail\tAddress\tPRN\tCET Score" << endl;
    while (current != NULL || !s.empty())
    {
        while (current != NULL)
        {
            s.push(current);
            current = current->lc;
        }
        current = s.top();
        s.pop();
        if (current->cet <= 90)
            cout << current->name << "\t" << current->email << "\t" << current->address << "\t" << current->prn << "\t" << current->cet << endl;
        current = current->rc;
    }
}

// Function to calculate the height of the tree
int SMS::height(SMS *root)
{
    if (!root)
        return 0;
    int leftHeight = height(root->lc);
    int rightHeight = height(root->rc);
    return max(leftHeight, rightHeight) + 1;
}

// Function to create a mirror image of the tree
void SMS::mirror(SMS *root)
{
    if (!root)
        return;
    mirror(root->lc);
    mirror(root->rc);
    swap(root->lc, root->rc);
}

// Function to count the number of nodes in the tree
int SMS::countNodes(SMS *root)
{
    if (!root)
        return 0;
    return 1 + countNodes(root->lc) + countNodes(root->rc);
}

// Function to search for a student by PRN
void SMS::search(SMS *root, int prn)
{
    if (!root)
    {
        cout << "Student not found." << endl;
        return;
    }
    if (root->prn == prn)
    {
        cout << "Name\tEmail\tAddress\tPRN\tCET Score" << endl;
        cout << root->name << "\t" << root->email << "\t" << root->address << "\t" << root->prn << "\t" << root->cet << endl;
        return;
    }
    if (prn < root->prn)
        search(root->lc, prn);
    else
        search(root->rc, prn);
}

// Function to update student details by PRN
void SMS::update(SMS *root, int prn)
{
    if (!root)
        return;
    if (root->prn == prn)
    {
        cout << "Enter new name: ";
        cin >> root->name;
        cout << "Enter new email: ";
        cin >> root->email;
        cout << "Enter new address: ";
        cin >> root->address;
        cout << "Enter new CET score: ";
        cin >> root->cet;
        return;
    }
    if (prn < root->prn)
        update(root->lc, prn);
    else
        update(root->rc, prn);
}

// Function to display ancestors of a given node
void SMS::displayAncestors(SMS *root, int prn)
{
    if (!root)
    {
        cout << "PRN not found in the tree." << endl;
        return;
    }
    if (root->prn == prn)
        return;
    cout << root->prn << " ";
    if (prn < root->prn)
        displayAncestors(root->lc, prn);
    else
        displayAncestors(root->rc, prn);
}

void SMS::lowestScore(SMS *root)
{
    if (root == NULL)
    {
        cout << "No Student Record Found in Database" << endl;
    }
    else
    {
        while (root->lc != NULL)
        {
            root = root->lc;
        }
        cout << "Lowest Scorer Name: " << root->name << "  CET Score: " << root->cet << endl;
    }
}

void SMS::topper(SMS *root)
{
    if (root == NULL)
    {
        cout << "No Student Record Found in Database" << endl;
    }
    else
    {
        while (root->rc != NULL)
        {
            root = root->rc;
        }
        cout << "Topper Name: " << root->name << "  CET Score: " << root->cet << endl;
    }
}

int main()
{
    SMS *root = NULL;
    int choice, prn;
    do
    {
        cout << "\n     Menu\n\n1. Accept Student\n2. Display All Students\n3. Display IIT students\n4. Display Non-IIT students\n5. Height of Tree\n6. Mirror image of the Tree\n7. Count of Nodes\n8. Search a student\n9. Update student info\n10. Display Ancestors of node\n11. Display Topper\n12. Disaplay lowest scorer\n13. Exit\nEnter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            if (root == NULL)
            {
                root = new SMS();
                root->accept(root);
            }
            else
            {
                SMS *newNode = new SMS();
                newNode->accept(newNode);
                root->insert(root, newNode);
            }
            break;
        case 2:
            root->displayAll(root);
            break;
        case 3:
            root->displayIIT(root);
            break;
        case 4:
            root->displayNonIIT(root);
            break;
        case 5:
            cout << "Height of the tree: " << root->height(root) << endl;
            break;
        case 6:
            root->mirror(root);
            cout << "Tree mirrored successfully." << endl;
            break;
        case 7:
            cout << "Number of nodes: " << root->countNodes(root) << endl;
            break;
        case 8:
            cout << "Enter PRN: ";
            cin >> prn;
            root->search(root, prn);
            break;
        case 9:
            cout << "Enter PRN to update: ";
            cin >> prn;
            root->update(root, prn);
            break;
        case 10:
            cout << "Enter PRN for ancestors: ";
            cin >> prn;
            root->displayAncestors(root, prn);
            cout << endl;
            break;
        case 11:
            root->topper(root);
            break;
        case 12:
            root->lowestScore(root);
            break;
        case 13:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please choose a valid option." << endl;
            break;
        }
    } while (choice != 13);
    return 0;
}