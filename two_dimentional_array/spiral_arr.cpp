#include <iostream>
using namespace std;

void spiralPrint(int arr[][100], int n, int m) {
    int startRow = 0, endRow = n-1;
    int startCol = 0, endCol = m-1;
    
    while(startRow <= endRow && startCol <= endCol) {
        // 1. Left to Right → (first row)
        for(int j = startCol; j <= endCol; j++) {
            cout << arr[startRow][j] << " ";
        }
        startRow++;
        
        // 2. Top to Bottom ↓ (last column)
        for(int i = startRow; i <= endRow; i++) {
            cout << arr[i][endCol] << " ";
        }
        endCol--;
        
        // 3. Right to Left ← (last row)
        if(startRow <= endRow) {
            for(int j = endCol; j >= startCol; j--) {
                cout << arr[endRow][j] << " ";
            }
            endRow--;
        }
        
        // 4. Bottom to Top ↑ (first column)
        if(startCol <= endCol) {
            for(int i = endRow; i >= startRow; i--) {
                cout << arr[i][startCol] << " ";
            }
            startCol++;
        }
    }
}

int main() {
    int arr[100][100];
    int n, m;
    
    cout << "Enter number of rows and columns: ";
    cin >> n >> m;
    
    cout << "Enter matrix elements:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    
    cout << "Spiral Print: ";
    spiralPrint(arr, n, m);
    cout << endl;
    return 0;
}