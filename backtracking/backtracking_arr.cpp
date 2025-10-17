#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void fillArray(int arr[], int n, int index) {
    // Base case: If index reaches n, print the array
    if (index == n) {
        printArray(arr, n);
        return;
    }

    // Recursive case: Fill the current index with values from 1 to 3
    for (int val = 1; val <= 3; val++) {
        arr[index] = val;
        fillArray(arr, n, index + 1);
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    fillArray(arr, n, 0);

    return 0;
}