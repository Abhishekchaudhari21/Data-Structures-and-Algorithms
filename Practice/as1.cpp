#include <iostream>
using namespace std;

class Emp
{
    string name, id, add;
    Emp *lc, *rc; // left child and right child of the node
    int top = -1;

public:
    Emp() : lc(NULL), rc(NULL) {}
    void accept();
    void insert(Emp *root, Emp *next);
    void displayIn(Emp *root);
    void displayPre(Emp *root);
    void displayPost(Emp *root);
    void displayInNonRec(Emp *root);
    void displayPreNonRec(Emp *root);
    void displayPostNonRec(Emp *root);
    int height(Emp *root);
    void heightWtRec(Emp *root);
    void searchEmp(Emp *root, string ss);
    void mirror(Emp *root);
    void leafnode(Emp *root);

} *stk[100], *temp = nullptr;

Emp *root = nullptr;

void Emp::accept()
{
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter id: ";
    cin >> id;
    cout << "Enter address: ";
    cin >> add;
}

void Emp::insert(Emp *root, Emp *next)
{
    int press;
    cout << "Which side of " << root->name << " do you want to join?\n";
    cout << "If left, press 1\nIf right, press 2" << endl;
    cin >> press;
    if (!root)
    {
        cout << " Root is null, cannot insert." << endl;
        return;
    }

    if (press == 1)
    {
        if (root->lc == nullptr)
        {
            root->lc = next;
            cout << "Inserted at the left of " << root->name << endl;
        }
        else
        {
            insert(root->lc, next);
        }
    }
    else if (press == 2)
    {
        if (root->rc == nullptr)
        {
            root->rc = next;
            cout << "Inserted at the right of " << root->name << endl;
        }
        else
        {
            insert(root->rc, next);
        }
    }
    else
    {
        cout << "Invalid input. Please try again." << endl;
    }
}

void Emp::displayIn(Emp *node)
{
    if (!node)
        return; // Base case: if node is null, return

    if (node->lc)
    {

        displayIn(node->lc);
    }

    cout << node->name << "\t" << node->id << "\t" << node->add << endl;
    if (node->rc)
    {

        displayIn(node->rc);
    }
}
void Emp::displayPre(Emp *node)
{
    if (!node)
        return; // Base case: if node is null, return

    cout << node->name << "\t" << node->id << "\t" << node->add << endl;

    if (node->lc)
    {

        displayPre(node->lc);
    }
    if (node->rc)
    {

        displayPre(node->rc);
    }
}
void Emp::displayPost(Emp *node)
{
    if (!node)
        return; // Base case: if node is null, return

    if (node->lc)
    {

        displayPost(node->lc);
    }
    if (node->rc)
    {

        displayPost(node->rc);
    }
    cout << node->name << "\t" << node->id << "\t" << node->add << endl;
}
void Emp::displayInNonRec(Emp *node)
{
    if (node == NULL)
    {
        cout << "Employee not found" << endl;
        return;
    }
    else
    {
        temp = node;
        if (node != NULL)
        {
            do
            {
                while (temp != NULL)
                {
                    top = top + 1;
                    stk[top] = temp;
                    temp = temp->lc;
                }
                if (top != -1)
                {
                    temp = stk[top];
                    top = top - 1;
                    cout << temp->name << "\t" << temp->id << "\t" << temp->add << endl;
                    temp = temp->rc;
                }
            } while (top != -1 || temp != NULL);
        }
    }
}

void Emp::displayPreNonRec(Emp *node)
{
    if (node == NULL)
    {
        cout << "Employee not found" << endl;
        return;
    }
    else
    {
        temp = node;
        if (node != NULL)
        {
            do
            {
                while (temp != NULL)
                {
                    top = top + 1;
                    stk[top] = temp;
                    cout << temp->name << "\t" << temp->id << "\t" << temp->add << endl;
                    temp = temp->lc;
                }
                if (top != -1)
                {
                    temp = stk[top];
                    top = top - 1;
                    temp = temp->rc;
                }
            } while (top != -1 || temp != NULL);
        }
    }
}
void Emp::displayPostNonRec(Emp *node)
{
    if (node == NULL)
    {
        cout << "Employee not found" << endl;
        return;
    }
    else
    {
        temp = node;
        if (node != NULL)
        {
            do
            {
                while (temp != NULL)
                {
                    top = top + 1;
                    stk[top] = temp;
                    temp = temp->lc;
                }
                if (top != -1)
                {
                    temp = stk[top];
                    top = top - 1;
                    cout << temp->name << "\t" << temp->id << "\t" << temp->add << endl;
                    temp = temp->rc;
                }
            } while (top != -1 || temp != NULL);
        }
    }
}

int Emp::height(Emp *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int left_height = height(root->lc);
        int right_height = height(root->rc);
        if (left_height > right_height)
        {
            return left_height;
        }
        else
        {
            return right_height;
        }
    }
}

void Emp::heightWtRec(Emp *root)
{ // finding height without recursion
    if (root == NULL)
    {
        return;
    }
    else
    {
        int height = 0;
        Emp *temp = root;
        while (temp != NULL)
        {
            height++;
            if (temp->lc != NULL)
            {
                temp = temp->lc;
            }
            else if (temp->rc != NULL)
            {
                temp = temp->rc;
            }
            else
            {
                break;
            }
        }
        cout << "Height of tree is: " << height << endl;
    }
}

void Emp::mirror(Emp *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {

        mirror(root->lc);
        mirror(root->rc);
        Emp *temp = root->lc;
        root->lc = root->rc;
        root->rc = temp;
    }
}

void Emp::searchEmp(Emp *root, string ss)
{
    if (root == NULL)
    {
        cout << "Employee not found" << endl;
        return;
    }

    else
    {
        if (root->id == ss)
        {
            cout << "Employee found " << endl;
            cout << "Should we display it?" << endl;
            cout << "1. Yes \n2. No" << endl;
            int ch2;
            cin >> ch2;
            if (ch2 == 1)
            {
                cout << "Name \t ID \t Address" << endl;
                cout << "---------------------------" << endl;
                cout << root->name << "\t" << root->id << "\t" << root->add << endl;
            }
            else
            {
                return;
            }
        }
        else
        {
            searchEmp(root->lc, ss);
            searchEmp(root->rc, ss);
        }
    }
    cout << "Employee not found" << endl;
}

void Emp::leafnode(Emp *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        if (root->lc == NULL && root->rc == NULL)
        {
            cout << "Leaf node found" << endl;
            cout << "Name \t ID \t Address" << endl;
            cout << "---------------------------" << endl;
            cout << root->name << "\t" << root->id << "\t" << root->add << endl;
        }
        else
        {
            leafnode(root->lc);
            leafnode(root->rc);
        }
    }
}

int main()
{
    int choice;
    do
    {
        cout << "1. Accept Employee" << endl;
        cout << "2. Display Employees in Inorder using recursion" << endl;
        cout << "3. Display Employees in Preorder using recursion" << endl;
        cout << "4. Display Employees in Postorder using recursion" << endl;
        cout << "5. Display Employees in Inorder using non recursive function" << endl;
        cout << "6. Display Employees in Preorder using non recursive function" << endl;
        cout << "7. Display Employees in Postorder using non recursive function" << endl;
        cout << "8. Search Employee  " << endl;
        cout << "9.. Find height of the tree using recursion" << endl;
        cout << "10. Find height of the tree without recursive function" << endl;
        cout << "11. Create Mirror image of the tree using recursion" << endl;
        cout << "12.Display leaf nodes" << endl;
        cout << "13. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Emp *next = new Emp();
            next->accept();
            if (!root)
            {
                root = next;
                cout << "Root employee added." << endl;
            }
            else
            {
                root->insert(root, next);
            }
            break;
        }
        case 2:
        {
            if (!root)
            {
                cout << "No employees to display!" << endl;
            }
            else
            {
                cout << "In order Employee Details:" << endl;
                cout << "Name " << "\t" << "ID" << "\t" << "Address" << endl;
                cout << "-------------------------------------------------------------------------------" << endl;
                root->displayIn(root);
            }
            break;
        }
        case 3:
        {
            if (!root)
            {
                cout << "No employees to display!" << endl;
            }
            else
            {
                cout << " Pre Order Employee Details:" << endl;
                cout << "Name " << "\t" << "ID" << "\t" << "Address" << endl;
                cout << "-------------------------------------------------------------------------------" << endl;
                root->displayPre(root);
            }
            break;
        }
        case 4:
        {
            if (!root)
            {
                cout << "No employees to display!" << endl;
            }
            else
            {
                cout << " Post order Employee Details:" << endl;
                cout << "Name " << "\t" << "ID" << "\t" << "Address" << endl;
                cout << "-------------------------------------------------------------------------------" << endl;
                root->displayPost(root);
            }
            break;
        }
        case 5:
        {
            if (!root)
            {
                cout << "No employees to display!" << endl;
            }
            else
            {
                cout << "In order Employee Details:" << endl;
                cout << "Name " << "\t" << "ID" << "\t" << "Address" << endl;
                cout << "-------------------------------------------------------------------------------" << endl;
                root->displayInNonRec(root);
            }
            break;
        }
        case 6:
        {
            if (!root)
            {
                cout << "No employees to display!" << endl;
            }
            else
            {
                cout << " Pre Order Employee Details:" << endl;
                cout << "Name " << "\t" << "ID" << "\t" << "Address" << endl;
                cout << "-------------------------------------------------------------------------------" << endl;
                root->displayPreNonRec(root);
            }
            break;
        }
        case 7:
        {
            if (!root)
            {
                cout << "No employees to display!" << endl;
            }
            else
            {
                cout << " Post order Employee Details:" << endl;
                cout << "Name " << "\t" << "ID" << "\t" << "Address" << endl;
                cout << "-------------------------------------------------------------------------------" << endl;
                root->displayPostNonRec(root);
            }
            break;
        }
        case 8:
        {
            string ss;
            cout << "Enter employee id: " << endl;
            cin >> ss;
            root->searchEmp(root, ss);
            break;
        }
        case 9:
            cout << "---------HEIGHT OF TREE WITH RECURSION-----" << endl;
            cout << "Height of tree is: " << root->height(root) << endl;
            break;

        case 10:
            cout << "---------HEIGHT OF TREE WITHOUT RECURSION-----" << endl;
            root->heightWtRec(root);
            break;
        case 11:
            cout << "------Creating Mirror Image------" << endl;
            root->mirror(root);

            cout << "Mirror image created successfully" << endl;
            cout << "Do you want to display mirror image?(Y/N)Press 1 for yes and 2 for no" << endl;
            int ch;
            cin >> ch;
            if (ch == 1)
            {
                cout << "Should we dislpay mirror image in: 1.Inorder 2.Preorder 3.Postorder" << endl;
                int ch1;
                cin >> ch1;
                if (ch1 == 1)
                {
                    root->displayIn(root);
                }
                else if (ch1 == 2)
                {
                    root->displayPre(root);
                }
                else if (ch1 == 3)
                {
                    root->displayPost(root);
                }
                else
                {
                    cout << "Invalid choice!" << endl;
                }
            }
            else
            {
                cout << "Exiting the program" << endl;
                break;
            }
            break;
        case 12:
            root->leafnode(root);
            break;

        case 13:
            cout << "Exiting....." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }
    } while (choice != 13);

    return 0;
}