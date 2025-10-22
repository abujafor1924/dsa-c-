#include <iostream>
using namespace std;

// নোড স্ট্রাকচার
class Node {
public:
    int data;       // ডাটা রাখে
    Node* next;     // পরবর্তী নোডের পয়েন্টার
    
    // কনস্ট্রাক্টর
    Node(int value) {
        data = value;
        next = nullptr;  // শুরুতে nullptr
    }
};

// লিংকড লিস্ট ক্লাস
class LinkedList {
private:
    Node* head;     // প্রথম নোডের পয়েন্টার
    
public:
    // কনস্ট্রাক্টর
    LinkedList() {
        head = nullptr;  // শুরুতে লিস্ট খালি
    }
    
    // ডেস্ট্রাক্টর - মেমোরি ক্লিনআপ
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
    
    // লিস্ট খালি কিনা চেক
    bool isEmpty() {
        return head == nullptr;
    }
    
    // ১. শুরুতে নোড যোগ করা
    void insertAtBeginning(int value) {
        // নতুন নোড তৈরি
        Node* newNode = new Node(value);
        
        // নতুন নোডের Next指向目前的Head
        newNode->next = head;
        
        // Head指向新节点
        head = newNode;
        
        cout << value << " inserted at beginning." << endl;
    }
    
    // ২. শেষে নোড যোগ করা
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        
        // যদি লিস্ট খালি থাকে
        if (head == nullptr) {
            head = newNode;
            cout << value << " inserted at end." << endl;
            return;
        }
        
        // শেষ নোড পর্যন্ত যাওয়া
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        
        // শেষ নোডের Next指向新节点
        temp->next = newNode;
        
        cout << value << " inserted at end." << endl;
    }
    
    // ৩. নির্দিষ্ট পজিশনে নোড যোগ করা
    void insertAtPosition(int value, int position) {
        if (position < 0) {
            cout << "Invalid position!" << endl;
            return;
        }
        
        // যদি পজিশন 0 হয় (শুরুতে)
        if (position == 0) {
            insertAtBeginning(value);
            return;
        }
        
        Node* newNode = new Node(value);
        Node* temp = head;
        
        // (position-1) নম্বর নোডে যাওয়া
        for (int i = 0; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        
        // যদি পজিশন লিস্টের সাইজের চেয়ে বড় হয়
        if (temp == nullptr) {
            cout << "Position out of range!" << endl;
            delete newNode;
            return;
        }
        
        // নতুন নোড সংযোগ করা
        newNode->next = temp->next;
        temp->next = newNode;
        
        cout << value << " inserted at position " << position << endl;
    }
    
    // ৪. নোড ডিলিট করা (ভ্যালু দিয়ে)
    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        
        // যদি প্রথম নোড ডিলিট করতে হয়
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << value << " deleted from list." << endl;
            return;
        }
        
        Node* temp = head;
        
        // ডিলিট করতে হবে এমন নোডের আগের নোড খুঁজে বের করা
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }
        
        // ভ্যালু না পাওয়া গেলে
        if (temp->next == nullptr) {
            cout << "Value " << value << " not found in list!" << endl;
            return;
        }
        
        // নোড ডিলিট করা
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
        
        cout << value << " deleted from list." << endl;
    }
    
    // ৫. সার্চ করা
    bool search(int value) {
        Node* temp = head;
        int position = 0;
        
        while (temp != nullptr) {
            if (temp->data == value) {
                cout << value << " found at position " << position << endl;
                return true;
            }
            temp = temp->next;
            position++;
        }
        
        cout << value << " not found in list!" << endl;
        return false;
    }
    
    // ৬. লিস্ট ডিসপ্লে করা
    void display() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << " -> NULL" << endl;
    }
    
    // ৭. লিস্টের সাইজ
    int size() {
        int count = 0;
        Node* temp = head;
        
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        
        return count;
    }
    
    // ৮. লিস্ট রিভার্স করা
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        
        while (current != nullptr) {
            next = current->next;  // Store next node
            current->next = prev;  // Reverse link
            prev = current;        // Move prev forward
            current = next;        // Move current forward
        }
        
        head = prev;  // Update head
        cout << "List reversed." << endl;
    }
};

// মেইন ফাংশন - টেস্টিং
int main() {
    LinkedList list;
    
    cout << "=== সিঙ্গলি লিংকড লিস্ট ডেমো ===" << endl;
    
    // শুরুতে নোড যোগ
    list.insertAtBeginning(30);
    list.insertAtBeginning(20);
    list.insertAtBeginning(10);
    list.display();
    
    // শেষে নোড যোগ
    list.insertAtEnd(40);
    list.insertAtEnd(50);
    list.display();
    
    // নির্দিষ্ট পজিশনে যোগ
    list.insertAtPosition(25, 2);
    list.insertAtPosition(35, 5);
    list.display();
    
    // সার্চ টেস্ট
    list.search(25);
    list.search(100);
    
    // সাইজ চেক
    cout << "List size: " << list.size() << endl;
    
    // ডিলিট টেস্ট
    list.deleteNode(25);
    list.display();
    
    list.deleteNode(10);  // প্রথম নোড
    list.display();
    
    list.deleteNode(50);  // শেষ নোড
    list.display();
    
    // রিভার্স টেস্ট
    cout << "Before reverse: ";
    list.display();
    
    list.reverse();
    cout << "After reverse: ";
    list.display();
    
    return 0;
}