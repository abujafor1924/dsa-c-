#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Function to insert a node at the end
void insertAtEnd(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) { // যদি লিস্ট খালি হয়
        *head_ref = new_node;
        return;
    }

    Node* temp = *head_ref;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to display all nodes
void displayList(Node* node) {
    if (node == NULL) {
        cout << "List is empty!\n";
        return;
    }

    cout << "Linked List: ";
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Function to delete a node by value
void deleteNode(Node** head_ref, int key) {
    Node* temp = *head_ref;
    Node* prev = NULL;

    // যদি প্রথম নোডই delete করতে হয়
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        delete temp;
        cout << "Node deleted successfully.\n";
        return;
    }

    // অন্যথায় খুঁজে বের করা
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Value not found!\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "Node deleted successfully.\n";
}

// Function to search for a value
void searchNode(Node* head, int key) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Value found at position: " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Value not found in list.\n";
}

// Main function
int main() {
    Node* head = NULL;
    int choice, value;

    do {
        cout << "\n=== LINKED LIST MENU ===\n";
        cout << "1. Insert at end\n";
        cout << "2. Display list\n";
        cout << "3. Delete a value\n";
        cout << "4. Search a value\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            insertAtEnd(&head, value);
            cout << "Node inserted successfully.\n";
            break;

        case 2:
            displayList(head);
            break;

        case 3:
            cout << "Enter value to delete: ";
            cin >> value;
            deleteNode(&head, value);
            break;

        case 4:
            cout << "Enter value to search: ";
            cin >> value;
            searchNode(head, value);
            break;

        case 5:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
