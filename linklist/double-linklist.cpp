#include <iostream>
using namespace std;

class DoubleNode {
public:
    int data;
    DoubleNode* next;
    DoubleNode* prev;
    
    DoubleNode(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    DoubleNode* head;
    DoubleNode* tail;
    
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    
    // Copy constructor (prevents shallow copy)
    DoublyLinkedList(const DoublyLinkedList& other) : head(nullptr), tail(nullptr) {
        DoubleNode* current = other.head;
        while (current != nullptr) {
            insertAtEnd(current->data);
            current = current->next;
        }
    }
    
    // Assignment operator
    DoublyLinkedList& operator=(const DoublyLinkedList& other) {
        if (this != &other) {
            // Clear existing list
            clear();
            
            // Copy elements
            DoubleNode* current = other.head;
            while (current != nullptr) {
                insertAtEnd(current->data);
                current = current->next;
            }
        }
        return *this;
    }
    
    ~DoublyLinkedList() {
        clear();
    }
    
    // Clear all nodes
    void clear() {
        DoubleNode* current = head;
        while (current != nullptr) {
            DoubleNode* next = current->next;
            delete current;
            current = next;
        }
        head = tail = nullptr;
    }
    
    // Check if list is empty
    bool isEmpty() const {
        return head == nullptr;
    }
    
    // Get front element
    int getFront() const {
        if (isEmpty()) {
            throw runtime_error("List is empty!");
        }
        return head->data;
    }
    
    // Get back element
    int getBack() const {
        if (isEmpty()) {
            throw runtime_error("List is empty!");
        }
        return tail->data;
    }
    
    // Insert at front
    void insertAtFront(int value) {
        DoubleNode* newNode = new DoubleNode(value);
        
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << value << " inserted at front." << endl;
    }
    
    // Insert at end
    void insertAtEnd(int value) {
        DoubleNode* newNode = new DoubleNode(value);
        
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << value << " inserted at end." << endl;
    }
    
    // Delete from front
    void deleteFromFront() {
        if (isEmpty()) {
            cout << "List is empty! Cannot delete." << endl;
            return;
        }
        
        DoubleNode* temp = head;
        head = head->next;
        
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr; // List became empty
        }
        
        cout << temp->data << " deleted from front." << endl;
        delete temp;
    }
    
    // Delete from end
    void deleteFromEnd() {
        if (isEmpty()) {
            cout << "List is empty! Cannot delete." << endl;
            return;
        }
        
        DoubleNode* temp = tail;
        tail = tail->prev;
        
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr; // List became empty
        }
        
        cout << temp->data << " deleted from end." << endl;
        delete temp;
    }
    
    // Display forward
    void displayForward() const {
        if (isEmpty()) {
            cout << "List is empty!" << endl;
            return;
        }
        
        DoubleNode* temp = head;
        cout << "Forward: NULL <- ";
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << " <-> ";
            }
            temp = temp->next;
        }
        cout << " -> NULL" << endl;
    }
    
    // Display backward
    void displayBackward() const {
        if (isEmpty()) {
            cout << "List is empty!" << endl;
            return;
        }
        
        DoubleNode* temp = tail;
        cout << "Backward: NULL <- ";
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->prev != nullptr) {
                cout << " <-> ";
            }
            temp = temp->prev;
        }
        cout << " -> NULL" << endl;
    }
    
    // Get size of list
    int getSize() const {
        int count = 0;
        DoubleNode* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }
};

// Test function
void testDoublyLinkedList() {
    cout << "\n=== Doubly Linked List Demo ===" << endl;
    
    DoublyLinkedList dll;
    
    cout << "Is list empty? " << (dll.isEmpty() ? "Yes" : "No") << endl;
    
    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtFront(5);
    dll.insertAtEnd(30);
    
    cout << "List size: " << dll.getSize() << endl;
    
    dll.displayForward();
    dll.displayBackward();
    
    dll.deleteFromFront();
    dll.displayForward();
    
    dll.deleteFromEnd();
    dll.displayForward();
    
    cout << "Front element: " << dll.getFront() << endl;
    cout << "Back element: " << dll.getBack() << endl;
    
    // Test copy constructor
    DoublyLinkedList dll2 = dll;
    cout << "\nCopied list: ";
    dll2.displayForward();
}

int main() {
    testDoublyLinkedList();
    return 0;
}