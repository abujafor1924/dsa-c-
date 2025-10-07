#include <iostream>
using namespace std;

int main() {
    char root[100];
    cout << "Enter the root: ";
    cin.getline(root, 100);
    int x = 0;
    int y = 0;
    
    // Calculate final coordinates
    for (int i = 0; root[i] != '\0'; i++) {
        switch (root[i]) {
            case 'N': y++; break;
            case 'S': y--; break;
            case 'E': x++; break;
            case 'W': x--; break;
        }
    }
    
    cout << "Final coordinates: (" << x << ", " << y << ")" << endl;
    
    // Find shortest path back to origin (0,0)
    if (x >= 0 && y >= 0) {
        for (int i = 0; i < y; i++) {
            cout << "N";
        }
        for (int i = 0; i < x; i++) {
            cout << "E";
        }
        cout << endl;
    } 
    else if (x >= 0 && y < 0) {
        for (int i = 0; i < -y; i++) {  // Positive value needed
            cout << "S";
        }
        for (int i = 0; i < x; i++) {
            cout << "E";
        }
        cout << endl;
    } 
    else if (x < 0 && y >= 0) {
        for (int i = 0; i < y; i++) {
            cout << "N";
        }
        for (int i = 0; i < -x; i++) {  // Positive value needed
            cout << "W";
        }
        cout << endl;
    } 
    else if (x < 0 && y < 0) {
        for (int i = 0; i < -y; i++) {  // Positive value needed
            cout << "S";
        }
        for (int i = 0; i < -x; i++) {  // Positive value needed
            cout << "W";
        }
        cout << endl;
    }
    
    return 0;
}