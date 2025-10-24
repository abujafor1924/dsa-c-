#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    // PUSH operation
    void push(int value) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = value;
        cout << value << " pushed to stack" << endl;
    }

    // POP operation
    int pop() {
        if (top < 0) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        int value = arr[top--];
        return value;
    }

    // PEEK operation
    int peek() {
        if (top < 0) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    // isEmpty check
    bool isEmpty() {
        return (top < 0);
    }

    // Display stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Example usage
int main() {
    Stack s;
    
    s.push(10);
    s.push(20);
    s.push(30);
    
    s.display(); // Output: 30 20 10
    
    cout << "Top element: " << s.peek() << endl; // Output: 30
    
    cout << s.pop() << " popped from stack" << endl; // Output: 30
    cout << s.pop() << " popped from stack" << endl; // Output: 20
    
    s.display(); // Output: 10
    
    return 0;
}