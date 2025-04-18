#include <iostream>
#include <string>

using namespace std;

class Graph
{
    string city[50];
    int AdjMatrix[50][50];
    struct Node
    {
        int index;
        int fuel;
        Node *next;
    };

    Node *head[50];
    int v, edges;

public:
    Graph()
    {
        v = 0;
        edges = 0;
        for (int i = 0; i < 50; i++)
        {
            head[i] = nullptr;
            for (int j = 0; j < 50; j++)
            {
                AdjMatrix[i][j] = 0;
            }
        }
    }

    void acceptByAdjMatrix();
    void acceptByAdjList();
    void displayMatrix();
    void displayList();
};

void Graph::acceptByAdjMatrix()
{
    cout << "Enter the number of cities: ";
    cin >> v;

    cout << "Enter the city names: " << endl;
    for (int i = 0; i < v; i++)
    {
        cout << "City " << i + 1 << " : ";
        cin >> city[i];
    }

    cout << "Enter the fuel costs between cities (-1 for no direct path):" << endl;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (i == j)
            {
                AdjMatrix[i][j] = 0; // No self-loop
            }
            else
            {
                cout << "Fuel cost from " << city[i] << " to " << city[j] << ": ";
                cin >> AdjMatrix[i][j];
                if (AdjMatrix[i][j] < 0) // No direct path
                {
                    AdjMatrix[i][j] = 0;
                }
            }
        }
    }
}

void Graph::acceptByAdjList()
{
    cout << "Enter the number of cities: ";
    cin >> v;

    cout << "Enter the city names: " << endl;
    for (int i = 0; i < v; i++)
    {
        cout << "City " << i + 1 << " : ";
        cin >> city[i];
    }

    cout << "Enter the number of direct flights (edges): ";
    cin >> edges;

    for (int i = 0; i < 2*edges; i++)
    {
        string source, dest;
        int fuelCost;
        cout << "Enter source city: ";
        cin >> source;
        cout << "Enter destination city: ";
        cin >> dest;
        cout << "Enter fuel required: ";
        cin >> fuelCost;

        int srcIndex = -1, destIndex = -1;

        // Find the indices of source and destination
        for (int j = 0; j < v; j++)
        {
            if (city[j] == source)
                srcIndex = j;
            if (city[j] == dest)
                destIndex = j;
        }

        if (srcIndex == -1 || destIndex == -1)
        {
            cout << "Invalid city names. Try again.\n";
            i--;
            continue;
        }

        // Create new node
        Node *newNode = new Node();
        newNode->index = destIndex;
        newNode->fuel = fuelCost;
        newNode->next = nullptr;

        // Insert into adjacency list
        if (head[srcIndex] == nullptr)
        {
            head[srcIndex] = newNode;
        }
        else
        {
            Node *temp = head[srcIndex];
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

void Graph::displayMatrix()
{
    cout << "\nAdjacency Matrix Representation:\n";
    cout << "   ";
    for (int i = 0; i < v; i++)
    {
        cout << city[i] << " ";
    }
    cout << "\n";

    for (int i = 0; i < v; i++)
    {
        cout << city[i] << " ";
        for (int j = 0; j < v; j++)
        {
            cout << AdjMatrix[i][j] << " ";
        }
        cout << "\n";
    }
}

void Graph::displayList()
{
    cout << "\nAdjacency List Representation:\n";
    for (int i = 0; i < v; i++)
    {
        cout << city[i] << " -> ";
        Node *temp = head[i];
        while (temp != nullptr)
        {
            cout << city[temp->index] << " (Fuel: " << temp->fuel << ") -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
}

int main()
{
    Graph g;
    int choice;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Accept by adjacency matrix\n";
        cout << "2. Accept by adjacency list\n";
        cout << "3. Display adjacency matrix\n";
        cout << "4. Display adjacency list\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            g.acceptByAdjMatrix();
            break;
        case 2:
            g.acceptByAdjList();
            break;
        case 3:
            g.displayMatrix();
            break;
        case 4:
            g.displayList();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
            break;
        }
    } while (choice != 5);
    return 0;
}
