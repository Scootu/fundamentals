#include <iostream>
using namespace std;

// Define the structure of a node
struct node {
    int info;
    node* next;
};

void displayList(node* head) {
    cout << "Current List: ";
    while (head != nullptr) {
        cout << head->info << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    int n, iNum;
    node* head = nullptr; // Initialize the head of the list as null

    cout << "Enter the number of elements (n): ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter element " << (i + 1) << ": ";
        cin >> iNum;

        // Create a new node
        node* Q = new node;
        Q->info = iNum;
        Q->next = nullptr;

        // Insert into the sorted list
        if (head == nullptr || iNum < head->info) {
            // Insert at the beginning
            Q->next = head;
            head = Q;
        } else {
            // Find the correct position
            node* P = head;
            while (P->next != nullptr && P->next->info < iNum) {
                P = P->next;
            }
            // Insert after P
            Q->next = P->next;
            P->next = Q;
        }

        // Display the current state of the list
        displayList(head);
    }

    // Clean up memory
    node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
