#include <iostream>
#include <vector>
using namespace std;

void print2DArray(vector<vector<int>>& arr) {
    for(int i = 0; i < arr.size(); i++) {
        for(int j = 0; j < arr[i].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    
    // First, enter the dimensions: rows and columns
    cout << "Enter number of rows and columns: ";
    cin >> n >> m;
    
    vector<vector<int>> arr(n, vector<int>(m));
    
    // Then enter the matrix elements row by row
    cout << "Enter " << n << " rows with " << m << " numbers each:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    
    cout << "The 2D array is:" << endl;
    print2DArray(arr);
    return 0;
}