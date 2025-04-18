// assignment 3 using the adjacency list
#include <iostream>
using namespace std;

class fms
{
public:
    int numofcity;
    int fuel;

    string city;

    fms *next;

    void accept();
    void insertEdge();
    void display();

} *head[10];

void fms::accept()
{ // accept no of cities to accept and cities name and store in the head array pointer
    cout << "Enter Number Of Cities to Enter : ";
    cin >> numofcity;
    for (int i = 0; i < numofcity; i++)
    {
        head[i] = new fms; // memory allocation
        // city name accept
        cout << "Enter " << i << " Cities Name : ";
        cin >> head[i]->city;
        head[i]->next = NULL; // setting next to NULL , creating individual array pointer
    }
}

void fms::insertEdge()
{
    // declare variable
    int totaledges;
    string sourcecity, destcity;

    // accept total edges
    cout << "Enter Total Edges : ";
    cin >> totaledges;

    // accept source and destination city and fuel
    for (int i = 0; i < totaledges; i++)
    {
        cout << "Enter Source and Destination City : ";
        cin >> sourcecity >> destcity;

        cout << "Enter Fuel : ";
        cin >> fuel; // direct store in the variable

        // compare the source city with the head array
        for (int j = 0; j < numofcity; j++)
        {
            if (head[j]->city == sourcecity)
            {

                fms *temp = head[j];
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = new fms;
                temp->next->city = destcity;
                temp->next->fuel = fuel;
                temp->next->next = NULL;
                break;
            }
        }
    }
}

void fms::display()
{
    // apply for loop for all cities
    for (int i = 0; i < numofcity; i++)
    {
        cout << head[i]->city << " -> "; // print the source city and arrow

        fms *temp = head[i]->next; // store the next pointer in temp variable

        while (temp != NULL)
        {                                                           // while temp is not null
            cout << temp->city << " (Fuel: " << temp->fuel << ") "; // print the destination city and fuel store in temp variable
            temp = temp->next;                                      // update temp to next pointer
        }

        cout << "\n";
    }
}

fms flight;

int main()
{
    flight.accept();
    flight.insertEdge();
    flight.display();
    return 0;
}

/*

#include <iostream>
#include <string>
using namespace std;

class fms {
public:
    int fuel;          // Fuel needed for travel
    string city;       // City name
    fms* next;         // Pointer to the next city (adjacency list)

    // Methods
    void accept(int& numofcity, fms* head[]);
    void insertEdge(int numofcity, fms* head[]);
    void display(int numofcity, fms* head[]);
};

// Method to accept city names and initialize the adjacency list
void fms::accept(int& numofcity, fms* head[]) {
    cout << "Enter the number of cities: ";
    cin >> numofcity;

    for (int i = 0; i < numofcity; i++) {
        head[i] = new fms;          // Allocate memory for each city
        cout << "Enter the name of city " << i + 1 << ": ";
        cin >> head[i]->city;       // Accept city name
        head[i]->next = nullptr;    // Initialize the next pointer as null
    }
}

// Method to add edges between cities
void fms::insertEdge(int numofcity, fms* head[]) {
    int totaledges;
    cout << "Enter the total number of edges: ";
    cin >> totaledges;

    for (int i = 0; i < totaledges; i++) {
        string sourcecity, destcity;
        cout << "Enter the source and destination city: ";
        cin >> sourcecity >> destcity;

        bool isEdgeExist = false;

        // Check if edge (sourcecity -> destcity) or (destcity -> sourcecity) already exists
        for (int j = 0; j < numofcity; j++) {
            if (head[j]->city == sourcecity) {
                fms* temp = head[j];
                while (temp->next != nullptr) {
                    if (temp->next->city == destcity) {
                        isEdgeExist = true;
                        cout << "Fuel for the route between " << sourcecity << " and " << destcity
                             << " is already inserted. Please enter another edge.\n";
                        i--; // Repeat the iteration for a valid edge
                        break;
                    }
                    temp = temp->next;
                }
                if (isEdgeExist) break;
            }
            // Check the reverse route
            if (head[j]->city == destcity) {
                fms* temp = head[j];
                while (temp->next != nullptr) {
                    if (temp->next->city == sourcecity) {
                        isEdgeExist = true;
                        cout << "Fuel for the route between " << destcity << " and " << sourcecity
                             << " is already inserted. Please enter another edge.\n";
                        i--; // Repeat the iteration for a valid edge
                        break;
                    }
                    temp = temp->next;
                }
                if (isEdgeExist) break;
            }
        }

        if (!isEdgeExist) {
            int fuel;
            cout << "Enter the fuel needed: ";
            cin >> fuel;

            // Insert edge (sourcecity -> destcity)
            for (int j = 0; j < numofcity; j++) {
                if (head[j]->city == sourcecity) {
                    fms* temp = head[j];
                    while (temp->next != nullptr) {
                        temp = temp->next;
                    }
                    temp->next = new fms;
                    temp->next->city = destcity; // Set destination city
                    temp->next->fuel = fuel;     // Set fuel value
                    temp->next->next = nullptr;  // Initialize next pointer
                    break;
                }
            }

            // Insert reverse edge (destcity -> sourcecity)
            for (int j = 0; j < numofcity; j++) {
                if (head[j]->city == destcity) {
                    fms* temp = head[j];
                    while (temp->next != nullptr) {
                        temp = temp->next;
                    }
                    temp->next = new fms;
                    temp->next->city = sourcecity; // Set source city
                    temp->next->fuel = fuel;       // Set fuel value
                    temp->next->next = nullptr;    // Initialize next pointer
                    break;
                }
            }
        }
    }
}

// Method to display the adjacency list
void fms::display(int numofcity, fms* head[]) {
    for (int i = 0; i < numofcity; i++) {
        cout << head[i]->city << " -> "; // Print source city

        fms* temp = head[i]->next; // Traverse the adjacency list
        while (temp != nullptr) {
            cout << temp->city << " (Fuel: " << temp->fuel << ") "; // Print destination city and fuel
            temp = temp->next; // Move to the next city
        }
        cout << "\n";
    }
}

int main() {
    int numofcity;              // Number of cities
    fms* head[10];              // Array of pointers for adjacency list
    fms flight;                 // Object of the class

    // Call methods to accept cities, insert edges, and display the adjacency list
    flight.accept(numofcity, head);
    flight.insertEdge(numofcity, head);
    flight.display(numofcity, head);

    return 0;
}

*/