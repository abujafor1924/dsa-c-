#include<bits/stdc++.h>
using namespace std;

// Function to get the i-th bit (0-indexed from right)
int getIthBit(int n, int i) {
    int mask = (1 << i);
    return (n & mask) > 0 ? 1 : 0;
}

// Function to set the i-th bit (pass by reference)
void setIthBit(int &n, int i) {
    int mask = (1 << i);
    n = (n | mask);
}

// Function to set the i-th bit (return value)
int setIthBitReturn(int n, int i) {
    int mask = (1 << i);
    return (n | mask);
}

// Function to clear the i-th bit
void clearIthBit(int &n, int i) {
    int mask = ~(1 << i);
    n = (n & mask);
}

// Function to update the i-th bit
void updateIthBit(int &n, int i, int value) {
    clearIthBit(n, i);
    int mask = (value << i);
    n = (n | mask);
}

int main() {
    int n = 5;  // 0101 in binary
    int i;
    
    cout << "Enter bit position (0-31): ";
    cin >> i;
    
    // Display original number and its binary
    cout << "Original number: " << n << endl;
    cout << "Binary: ";
    for(int j = 31; j >= 0; j--) {
        cout << ((n >> j) & 1);
        if(j % 4 == 0) cout << " ";
    }
    cout << endl;
    
    // Get i-th bit
    cout << "Bit at position " << i << " is: " << getIthBit(n, i) << endl;
    
    // Set i-th bit using pass by reference
    int temp = n; // store original value
    setIthBit(n, i);
    cout << "After setting bit at position " << i << " (pass by reference): " << n << endl;
    
    // Set i-th bit using return value
    n = temp; // restore original value
    n = setIthBitReturn(n, i);
    cout << "After setting bit at position " << i << " (return value): " << n << endl;
    
    // Display new binary
    cout << "New binary: ";
    for(int j = 31; j >= 0; j--) {
        cout << ((n >> j) & 1);
        if(j % 4 == 0) cout << " ";
    }
    cout << endl;
    
    // Additional operations
    cout << "\n--- Additional Operations ---" << endl;
    
    // Clear i-th bit
    clearIthBit(n, i);
    cout << "After clearing bit at position " << i << ": " << n << endl;
    
    // Update i-th bit to 1
    n = temp; // restore original value
    updateIthBit(n, i, 1);
    cout << "After updating bit at position " << i << " to 1: " << n << endl;
    
    // Update i-th bit to 0
    n = temp; // restore original value
    updateIthBit(n, i, 0);
    cout << "After updating bit at position " << i << " to 0: " << n << endl;
    
    return 0;
}